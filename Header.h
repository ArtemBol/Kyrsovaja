#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>
#include <TCHAR.H>

using namespace std;

class CipherPassword
{
public:
	string md5(string password);
};

class RegUser:public CipherPassword
{
private:
	string strHash;
public:
	int RegAcc(string login, string password);
};

class DellUser:public CipherPassword
{
private:
	string strHash;
public:
	int DellAcc(string login, string password);
};