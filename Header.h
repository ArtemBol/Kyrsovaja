/** @file
 * @author Большухин А.Д.
 * @version 1.1
 * @date 12.06.2019
 * @copyright ИБСТ ПГУ
 * @warning Курсовая работа
 * @brief Заголовочный файл для модуля Header
 */#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <TCHAR.H>

using namespace std;
/** @brief Получение хэша пароля c помошью 128-битного алгоритма хэширования MD5.
* @details Класс состоит из одного метода, получающего на вход строку с паролем.
* @param [in] password строка, содержащая введённый пользователем пароль.
* @warning Пароль должен состоять из 8 и более символов, иначе будет вызванно исключение.
*/
class CipherPassword
{
public:
	string md5(string password);///<Метод выполняющий хеширование.
};
/** @brief Сохранение данных, введённых пользователем, в реестре Windows.
 * @details В конструкторе находится строка, содержащая хэш пароля.
 * @param [in] password строка, содержащая введённый пользователем пароль.
 * @param [in] login строка, содержащая введённый пользователем логин.
 * Для сохранения логина и пароля используется метод RegAcc.
 * По пути HKEY_CURRENT_USER\Software создаётся раздел реестра, имеющий имя логина пользователя, а хэш пароля записывается в этот раздел.
 */
class RegUser :public CipherPassword
{
private:
	string strHash;///<Строка, содержащая хэш пароля.
public:
	int RegAcc(string login, string password);///<Метод добавляющий пользовательские данные в реестр.
};
/** @brief Удаление пользовательских данных, содержащихся в реестре Windows.
 * @details В конструкторе находится строка, содержащая хэш пароля.
 * @param [in] password строка, содержащая введённый пользователем пароль.
 * @param [in] login строка, содержащая введённый пользователем логин.
 * Для удаления учётной записи используется метод strHash.
 */
class DellUser :public CipherPassword
{
private:
	string strHash;///<Строка, содержащая хэш пароля.
public:
	int DellAcc(string login, string password);///<Метод удаляющий пользовательские данные из реестра.
};
/** @brief Проверка данных, введённых пользователем, с имеющимеся данными в реестре Windows.
 * @details В конструкторе находится строка, содержащая хэш пароля.
 * @param [in] password строка, содержащая введённый пользователем пароль.
 * @param [in] login строка, содержащая введённый пользователем логин.
 * Для преобразования полинома в последовательность отводных битов используется метод Polynomial_Converter.
 * Для генерации случайного числа используется метод LFSR_Galois.
 */
class AuthorizationUser :public CipherPassword
{
private:
	string strHash;///<Строка, содержащая хэш пароля.
public:
	int AuthorAcc(string login, string password);///<Метод сверяющий пользовательские данные с данными в реестре.
};