#include "Header.h"

using namespace std;

string CipherPassword::md5(string password)
{
	const auto hashSize = 16;
	BCRYPT_ALG_HANDLE hAlgorithm;
	UCHAR HashData[hashSize];
	string thisPassword;
	string passwordHash;
	unsigned wPass;
	thisPassword = password;
	if (thisPassword.size() < 8)
		throw string("Слишком короткий пароль");
	char hexNumbs[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	wPass = BCryptOpenAlgorithmProvider(&hAlgorithm, BCRYPT_MD5_ALGORITHM, NULL, 0);
	if (wPass != 0)
		throw string("Cryptography error(поставщик хранилищ)");
	wPass = BCryptHash(hAlgorithm, NULL, 0, (PUCHAR)thisPassword.data(), thisPassword.size(), HashData, hashSize);
	if (wPass != 0)
		throw string("Cryptography error(вычисление хеша)");
	wPass = BCryptCloseAlgorithmProvider(hAlgorithm, 0);
	for (int i = 0; i < hashSize; i++)
	{
		passwordHash += hexNumbs[(HashData[i] >> 4) & 0xF];
		passwordHash += hexNumbs[(HashData[i]) & 0xF];
	}
	return passwordHash;
}

int RegUser::RegAcc(string login, string password)
{
	unsigned int acc;
	string login1 = "Software\\";
	login1 += login;
	LPCSTR lplogin = login1.c_str();
	LPCSTR lpstrHash = strHash.c_str();
	HKEY hregkey;
	if (acc = RegCreateKeyA(HKEY_CURRENT_USER, lplogin, &hregkey) != ERROR_SUCCESS)
		throw string("RegUser error(добавление логиа)");
	else
	{
		acc = RegSetValueA(HKEY_CURRENT_USER, lplogin, REG_SZ, lpstrHash, 0);
		if (acc != ERROR_SUCCESS)
			throw string("RegUser error(добавление пароля)");
		acc = RegCloseKey(HKEY_CURRENT_USER);
	}
	return 0;
}

int DellUser::DellAcc(string login, string password)
{
	unsigned acc;
	_TCHAR vpassword[MAX_PATH];
	DWORD buflen = MAX_PATH;
	string login1 = "Software\\";
	login1 += login;
	LPCSTR lplogin = login1.c_str();
	strHash = md5(password);
	LPCSTR lpstrHash = strHash.c_str();
	HKEY hregkey;
	if (acc = RegOpenKeyA(HKEY_CURRENT_USER, lplogin, &hregkey) != ERROR_SUCCESS)
		throw string("DellUser error(Логин не найден)");
	if (acc = RegGetValueA(hregkey, NULL, NULL, RRF_RT_REG_SZ, NULL, (BYTE*)vpassword, &buflen) != ERROR_SUCCESS)
		throw string("DellUser error(Неверный пароль)");
	if (_tcscmp(vpassword, lpstrHash) == 0)
	{
		if (acc = RegDeleteKeyA(HKEY_CURRENT_USER, lplogin) != ERROR_SUCCESS)
			throw string("DellUser error(Удаление пароля)");
		acc = RegCloseKey(HKEY_CURRENT_USER);
		cout << "\t\t*Учётная запись успешно удалена*\n\n";
	}
	else
		throw string("Пароли не совпадают");
	return 0;
}
int AuthorizationUser::AuthorAcc(string login, string password)
{
	unsigned acc;
	_TCHAR vpassword[MAX_PATH];
	DWORD buflen = MAX_PATH;
	string login1 = "Software\\";
	login1 += login;
	LPCSTR lplogin = login1.c_str();
	strHash = md5(password);
	LPCSTR lpstrHash = strHash.c_str();
	HKEY hregkey;
	if (acc = RegOpenKeyA(HKEY_CURRENT_USER, lplogin, &hregkey) != ERROR_SUCCESS)
		throw string("AuthorizationUser error(Логин не найден)");
	if (acc = RegGetValueA(hregkey, NULL, NULL, RRF_RT_REG_SZ, NULL, (BYTE*)vpassword, &buflen) != ERROR_SUCCESS)
		throw string("AuthorizationUser error(Неверный пароль)");
	if (_tcscmp(vpassword, lpstrHash) == 0)
	{
		cout << "\t\tWelcome\n\n";
		acc = RegCloseKey(HKEY_CURRENT_USER);
	}
	else
		throw string("Пароли не совпадают");
	return 0;
}