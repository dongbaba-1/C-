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
		cout << "================欢迎来到Dbb的机房预约系统=============" << endl;
		cout << "\t\t -------------------------\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       1、学生           |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       2、老师           |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       3、管理员         |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       0、退出           |\n";
		cout << "\t\t -------------------------\n";
		cout << endl << "请输入您的身份:";
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
			cout << "欢迎下次使用!" << endl;
			exit(0);
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	return 0;
}