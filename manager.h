#pragma once
#include"identity.h"
#include"student.h"
#include"teacher.h"
class Manager :public Identity {
public:
	void operMenu();
	void addAccount();
	void viewAccount();
	void viewComputerRoom();
	void clearAppointment();
	void logOut();
	void writeInStudentFile(Student student);
	void writeInTeacherFile(Teacher teacher);
	//void writeInFile(Identity& identity);
	void readStudentFile(vector<Student>& stuVector);//将文件中的信息读入vector中
	void readTeacherFile(vector<Teacher>& teaVector);
	void readManagerFile(vector<Manager>& manVector);
	bool IsStudentIdExist(vector<Student> stuV,int student_id,int &i);
	bool IsTeacherIdExist(vector<Teacher> teaV,int teacher_id,int &i);
	bool IsManagerNameExist(vector<Manager> manV, string manager_name,int &i);
	void managerLogIn();
	void studentLogIn();
	void teacherLogIn();
	vector<Student> stuVector;
	vector<Teacher> TeaVector;
	int m_manager_id;
};
