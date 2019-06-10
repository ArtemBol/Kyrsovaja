#include "Header.h"

using namespace std;

int main()
{
	string login;
	string password;
	string password2;
	string strHash;
	unsigned op;
	setlocale(LC_ALL, "ru");
	cout << "\t\t ________________________________\n";
	cout << "\t\t/*МОДУЛЬ ПАРОЛЬНОЙ АУТЕНТИФИКАЦИИ*\\\n\n";
		do {
			cout << "\t\tРежимы работы модуля:\n\t\t1-Добавить пользователя\n\t\t2-Удалить пользователя\n\t\t3-Сменить пароль\n\t\t0-Выход\n\n";
			cout << "\t\tВыберите режим работы: ";
			cin >> op;
			if (op > 3) {
				cout << "\n" << "\t\t*Недопустимый режим работы!*\n\n";
			}
			else if (op > 0) {

				if (op == 1) {
					cout << "\t\tВведите имя пользователя: ";
					cin >> login;
					cout << "\t\tВведите пароль (*пароль должен содержать 8 или более символов*): ";
					cin >> password;

					if (password.size() < 8)
						cout << "\t\tНенадежный пароль!\n\t\t*Пароль должен содержать 8 или более символов*\n";
					cout << "\t\tПовторите пароль: ";
					cin >> password2;
					if (password == password2)
					{
						RegUser newAcc;
						newAcc.RegAcc(login, password2);
					}
					else {
						cout << "\t\t*Пароли не совпадают!*\n";
					}
				}
			else if (op == 2)
			{
				cout << "\t\tВведите имя пользователя: ";
				cin >> login;
				cout << "\t\tВведите пароль: ";
				cin >> password2;
				DellUser dellAcc;
				dellAcc.DellAcc(login, password2);
			}
			else if (op == 3)
			{
				cout << "\t\tВведите имя пользователя: ";
				cin >> login;
				cout << "\t\tВведите старый пароль: ";
				cin >> password2;
				DellUser dell;
				dell.DellAcc(login, password2);
				cout << "\t\tВведите новый пароль: ";
				cin >> password;
				if (password.size() < 8)
					cout << "\t\tНенадежный пароль!\n\t\t*Пароль должен содержать 8 или более символов*\n";
				cout << "\t\tПовторите пароль: ";
				cin >> password2;
				if (password == password2)
				{
					RegUser addNewPass;
					addNewPass.RegAcc(login, password2);
				}
			}
			}
			else {
				cout << "\n" << "\t\t*Недопустимый режим работы!*\n\n";
			}
		} while (op != 0);
		return 0;
}