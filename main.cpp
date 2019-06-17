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
		cout << "\t\t/*������ ��������� ��������������*\\\n\n";
		do {
			cout << "\t\t������ ������ ������:\n\t\t1-��������������\n\t\t2-�������� ������������\n\t\t3-������� ������������\n\t\t4-������� ������\n\t\t0-�����\n\n";
			cout << "\t\t�������� ����� ������: ";
			cin >> op;
			if (op > 4) {
				throw string("������������ ����� ������");
			}
			else if (op > 0) {
				if (op == 1) {
					cout << "\t\t������� ��� ������������: ";
					cin >> login;
					cout << "\t\t������� ������: ";
					cin >> password;
					AuthorizationUser Acc;
					Acc.AuthorAcc(login, password);
				}
				else if (op == 2) {
					cout << "\t\t������� ��� ������������: ";
					cin >> login;
					cout << "\t\t������� ������ (*������ ������ ��������� 8 ��� ����� ��������*): ";
					cin >> password;

					cout << "\t\t��������� ������: ";
					cin >> password2;
					if (password == password2)
					{
						RegUser newAcc;
						newAcc.RegAcc(login, password2);
					}
					else {
						throw string("������ �� ���������");
					}
				}
				else if (op == 3)
				{
					cout << "\t\t������� ��� ������������: ";
					cin >> login;
					cout << "\t\t������� ������: ";
					cin >> password;
					DellUser dellAcc;
					dellAcc.DellAcc(login, password);
				}
				else if (op == 4)
				{
					cout << "\t\t������� ��� ������������: ";
					cin >> login;
					cout << "\t\t������� ������ ������: ";
					cin >> password;
					DellUser dell;
					dell.DellAcc(login, password);
					cout << "\t\t������� ����� ������: ";
					cin >> password2;
					cout << "\t\t��������� ������: ";
					cin >> password;
					if (password == password2)
					{
						RegUser addNewPass;
						addNewPass.RegAcc(login, password2);
					}
					else
						throw string("������ �� ���������");
				}
			}
			else
				throw string("������������ ����� ������");
		} while (op != 0);
		return 0;
	}
	catch (string& e) {
		cerr << "Error: " << e << endl;
	}
	return 0;
}