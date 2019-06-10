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
	char hexNumbs[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	wPass = BCryptOpenAlgorithmProvider(&hAlgorithm, BCRYPT_MD5_ALGORITHM, NULL, 0);
	wPass = BCryptHash(hAlgorithm, NULL, 0, (PUCHAR)thisPassword.data(), thisPassword.size(), HashData, 16);
	wPass = BCryptCloseAlgorithmProvider(hAlgorithm, 0);
	for (int i = 0; i < hashSize; i++)
	{
		passwordHash += hexNumbs[(HashData[i] >> 4) & 0xF];
		passwordHash += hexNumbs[(HashData[i]) & 0xF];
	}
	return passwordHash;
}

int RegUser::RegAcc(string login, string password)//Добавление пользователя.
{
	unsigned int acc;
	string login1 = "Software\\";//Раздел реестра в котором находятся данные о пользователях.
	login1 += login;
	LPCSTR lplogin = login1.c_str();// Метод c_str() возвращает указатель на массив, который содержит последовательность символов с нулевым символом в конце, представляющую текущее значение строкового объекта.
	strHash = md5(password); 
	LPCSTR lpstrHash = strHash.c_str();
	HKEY hregkey;//Описатель раздела, который будет записываться.
	acc = RegCreateKeyA(HKEY_CURRENT_USER, lplogin, &hregkey);// RegCreateKeyA создает указанный раздел реестра. Если ключ уже существует, функция открывает его. HKEY_CURRENT_USER Извлекает дескриптор ключа для пользователя, который исполняет текущий поток.
	acc = RegSetValueA(HKEY_CURRENT_USER, lplogin, REG_SZ, lpstrHash, 0);//RegGetValueA получает тип и данные для указанного значения реестра.
	acc = RegCloseKey(HKEY_CURRENT_USER);
	return 0;
}

int DellUser::DellAcc(string login, string password)//Удаление пользователя.
{
	unsigned acc;
	_TCHAR vpassword[MAX_PATH];
	DWORD buflen = MAX_PATH;
	string login1 = "Software\\";//Раздел реестра в котором находятся данные о пользователях.
	login1 += login;
	LPCSTR lplogin = login1.c_str();
	strHash = md5(password);
	LPCSTR lpstrHash = strHash.c_str();
	HKEY hregkey;
	acc = RegOpenKeyA(HKEY_CURRENT_USER, lplogin, &hregkey);//RegOpenKeyA открывает указанный раздел реестра.
	acc = RegGetValueA(hregkey, NULL, NULL, RRF_RT_REG_SZ, NULL, (BYTE*)vpassword, &buflen);//RegGetValueA получает тип и данные для указанного значения реестра.
		if (_tcscmp(vpassword, lpstrHash) == 0)//Сравнение строк.
		{
			acc = RegDeleteKeyA(HKEY_CURRENT_USER, lplogin);//RegDeleteKeyA удаляет подраздел и его значения.
			acc = RegCloseKey(HKEY_CURRENT_USER);//RegCloseKey закрывает дескриптор указанного раздела реестра.
			cout << "\t\t*Учётная запись успешно удалена*\n\n";
		}
		else
			cout << "\t\t*Пароли не совпадают!*\n";
	return 0;
}