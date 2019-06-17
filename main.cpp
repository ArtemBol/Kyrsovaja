#include "Header.h"

using namespace std;

int main()
{
	try {
		string login;
		string password;
		string password2;
		string strHash;
		unsigned op;
		setlocale(LC_ALL, "ru");
		cout << "\t\t ________________________________\n";
		cout << "\t\t/*МОДУЛЬ ПАРОЛЬНОЙ АУТЕНТИФИКАЦИИ*\\\n\n";
		do {
			cout << "\t\tРежимы работы модуля:\n\t\t1-Авторизоваться\n\t\t2-Добавить пользователя\n\t\t3-Удалить пользователя\n\t\t4-Сменить пароль\n\t\t0-Выход\n\n";
			cout << "\t\tВыберите режим работы: ";
			cin >> op;
			if (op > 4) {
				throw string("Недопустимый режим работы");
			}
			else if (op > 0) {
				if (op == 1) {
					cout << "\t\tВведите имя пользователя: ";
					cin >> login;
					cout << "\t\tВведите пароль: ";
					cin >> password;
					AuthorizationUser Acc;
					Acc.AuthorAcc(login, password);
				}
				else if (op == 2) {
					cout << "\t\tВведите имя пользователя: ";
					cin >> login;
					cout << "\t\tВведите пароль (*пароль должен содержать 8 или более символов*): ";
					cin >> password;

					cout << "\t\tПовторите пароль: ";
					cin >> password2;
					if (password == password2)
					{
						RegUser newAcc;
						newAcc.RegAcc(login, password2);
					}
					else {
						throw string("Пароли не совпадают");
					}
				}
				else if (op == 3)
				{
					cout << "\t\tВведите имя пользователя: ";
					cin >> login;
					cout << "\t\tВведите пароль: ";
					cin >> password;
					DellUser dellAcc;
					dellAcc.DellAcc(login, password);
				}
				else if (op == 4)
				{
					cout << "\t\tВведите имя пользователя: ";
					cin >> login;
					cout << "\t\tВведите старый пароль: ";
					cin >> password;
					DellUser dell;
					dell.DellAcc(login, password);
					cout << "\t\tВведите новый пароль: ";
					cin >> password2;
					cout << "\t\tПовторите пароль: ";
					cin >> password;
					if (password == password2)
					{
						RegUser addNewPass;
						addNewPass.RegAcc(login, password2);
					}
					else
						throw string("Пароли не совпадают");
				}
			}
			else
				throw string("Недопустимый режим работы");
		} while (op != 0);
		return 0;
	}
	catch (string& e) {
		cerr << "Error: " << e << endl;
	}
	return 0;
}