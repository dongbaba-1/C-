#include<iostream>
using namespace std;
#include"identity.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
int main() {
	int choice;
	Manager manager;

	while (true) {
		cout << "================��ӭ����Dbb�Ļ���ԤԼϵͳ=============" << endl;
		cout << "\t\t -------------------------\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       1��ѧ��           |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       2����ʦ           |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       3������Ա         |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       0���˳�           |\n";
		cout << "\t\t -------------------------\n";
		cout << endl << "�������������:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			manager.studentLogIn();
			break;
		case 2:
			manager.teacherLogIn();
			break;
		case 3:
			manager.managerLogIn();
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "��ӭ�´�ʹ��!" << endl;
			exit(0);
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	return 0;
}