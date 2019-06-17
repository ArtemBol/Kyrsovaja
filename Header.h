/** @file
 * @author ��������� �.�.
 * @version 1.1
 * @date 12.06.2019
 * @copyright ���� ���
 * @warning �������� ������
 * @brief ������������ ���� ��� ������ Header
 */#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <TCHAR.H>

using namespace std;
/** @brief ��������� ���� ������ c ������� 128-������� ��������� ����������� MD5.
* @details ����� ������� �� ������ ������, ����������� �� ���� ������ � �������.
* @param [in] password ������, ���������� �������� ������������� ������.
* @warning ������ ������ �������� �� 8 � ����� ��������, ����� ����� �������� ����������.
*/
class CipherPassword
{
public:
	string md5(string password);///<����� ����������� �����������.
};
/** @brief ���������� ������, �������� �������������, � ������� Windows.
 * @details � ������������ ��������� ������, ���������� ��� ������.
 * @param [in] password ������, ���������� �������� ������������� ������.
 * @param [in] login ������, ���������� �������� ������������� �����.
 * ��� ���������� ������ � ������ ������������ ����� RegAcc.
 * �� ���� HKEY_CURRENT_USER\Software �������� ������ �������, ������� ��� ������ ������������, � ��� ������ ������������ � ���� ������.
 */
class RegUser :public CipherPassword
{
private:
	string strHash;///<������, ���������� ��� ������.
public:
	int RegAcc(string login, string password);///<����� ����������� ���������������� ������ � ������.
};
/** @brief �������� ���������������� ������, ������������ � ������� Windows.
 * @details � ������������ ��������� ������, ���������� ��� ������.
 * @param [in] password ������, ���������� �������� ������������� ������.
 * @param [in] login ������, ���������� �������� ������������� �����.
 * ��� �������� ������� ������ ������������ ����� strHash.
 */
class DellUser :public CipherPassword
{
private:
	string strHash;///<������, ���������� ��� ������.
public:
	int DellAcc(string login, string password);///<����� ��������� ���������������� ������ �� �������.
};
/** @brief �������� ������, �������� �������������, � ���������� ������� � ������� Windows.
 * @details � ������������ ��������� ������, ���������� ��� ������.
 * @param [in] password ������, ���������� �������� ������������� ������.
 * @param [in] login ������, ���������� �������� ������������� �����.
 * ��� �������������� �������� � ������������������ �������� ����� ������������ ����� Polynomial_Converter.
 * ��� ��������� ���������� ����� ������������ ����� LFSR_Galois.
 */
class AuthorizationUser :public CipherPassword
{
private:
	string strHash;///<������, ���������� ��� ������.
public:
	int AuthorAcc(string login, string password);///<����� ��������� ���������������� ������ � ������� � �������.
};