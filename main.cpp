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
	cout << "\t\t/*������ ��������� ��������������*\\\n\n";
		do {
			cout << "\t\t������ ������ ������:\n\t\t1-�������� ������������\n\t\t2-������� ������������\n\t\t3-������� ������\n\t\t0-�����\n\n";
			cout << "\t\t�������� ����� ������: ";
			cin >> op;
			if (op > 3) {
				cout << "\n" << "\t\t*������������ ����� ������!*\n\n";
			}
			else if (op > 0) {

				if (op == 1) {
					cout << "\t\t������� ��� ������������: ";
					cin >> login;
					cout << "\t\t������� ������ (*������ ������ ��������� 8 ��� ����� ��������*): ";
					cin >> password;

					if (password.size() < 8)
						cout << "\t\t���������� ������!\n\t\t*������ ������ ��������� 8 ��� ����� ��������*\n";
					cout << "\t\t��������� ������: ";
					cin >> password2;
					if (password == password2)
					{
						RegUser newAcc;
						newAcc.RegAcc(login, password2);
					}
					else {
						cout << "\t\t*������ �� ���������!*\n";
					}
				}
			else if (op == 2)
			{
				cout << "\t\t������� ��� ������������: ";
				cin >> login;
				cout << "\t\t������� ������: ";
				cin >> password2;
				DellUser dellAcc;
				dellAcc.DellAcc(login, password2);
			}
			else if (op == 3)
			{
				cout << "\t\t������� ��� ������������: ";
				cin >> login;
				cout << "\t\t������� ������ ������: ";
				cin >> password2;
				DellUser dell;
				dell.DellAcc(login, password2);
				cout << "\t\t������� ����� ������: ";
				cin >> password;
				if (password.size() < 8)
					cout << "\t\t���������� ������!\n\t\t*������ ������ ��������� 8 ��� ����� ��������*\n";
				cout << "\t\t��������� ������: ";
				cin >> password2;
				if (password == password2)
				{
					RegUser addNewPass;
					addNewPass.RegAcc(login, password2);
				}
			}
			}
			else {
				cout << "\n" << "\t\t*������������ ����� ������!*\n\n";
			}
		} while (op != 0);
		return 0;
}