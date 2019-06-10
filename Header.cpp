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

int RegUser::RegAcc(string login, string password)//���������� ������������.
{
	unsigned int acc;
	string login1 = "Software\\";//������ ������� � ������� ��������� ������ � �������������.
	login1 += login;
	LPCSTR lplogin = login1.c_str();// ����� c_str() ���������� ��������� �� ������, ������� �������� ������������������ �������� � ������� �������� � �����, �������������� ������� �������� ���������� �������.
	strHash = md5(password); 
	LPCSTR lpstrHash = strHash.c_str();
	HKEY hregkey;//��������� �������, ������� ����� ������������.
	acc = RegCreateKeyA(HKEY_CURRENT_USER, lplogin, &hregkey);// RegCreateKeyA ������� ��������� ������ �������. ���� ���� ��� ����������, ������� ��������� ���. HKEY_CURRENT_USER ��������� ���������� ����� ��� ������������, ������� ��������� ������� �����.
	acc = RegSetValueA(HKEY_CURRENT_USER, lplogin, REG_SZ, lpstrHash, 0);//RegGetValueA �������� ��� � ������ ��� ���������� �������� �������.
	acc = RegCloseKey(HKEY_CURRENT_USER);
	return 0;
}

int DellUser::DellAcc(string login, string password)//�������� ������������.
{
	unsigned acc;
	_TCHAR vpassword[MAX_PATH];
	DWORD buflen = MAX_PATH;
	string login1 = "Software\\";//������ ������� � ������� ��������� ������ � �������������.
	login1 += login;
	LPCSTR lplogin = login1.c_str();
	strHash = md5(password);
	LPCSTR lpstrHash = strHash.c_str();
	HKEY hregkey;
	acc = RegOpenKeyA(HKEY_CURRENT_USER, lplogin, &hregkey);//RegOpenKeyA ��������� ��������� ������ �������.
	acc = RegGetValueA(hregkey, NULL, NULL, RRF_RT_REG_SZ, NULL, (BYTE*)vpassword, &buflen);//RegGetValueA �������� ��� � ������ ��� ���������� �������� �������.
		if (_tcscmp(vpassword, lpstrHash) == 0)//��������� �����.
		{
			acc = RegDeleteKeyA(HKEY_CURRENT_USER, lplogin);//RegDeleteKeyA ������� ��������� � ��� ��������.
			acc = RegCloseKey(HKEY_CURRENT_USER);//RegCloseKey ��������� ���������� ���������� ������� �������.
			cout << "\t\t*������� ������ ������� �������*\n\n";
		}
		else
			cout << "\t\t*������ �� ���������!*\n";
	return 0;
}