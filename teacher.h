#pragma once
#include<iostream>
using namespace std;
#include"identity.h"

class Teacher :public Identity {
public:
	Teacher(int teacher_id);
	Teacher(int teacher_id, string teacher_name, int teacher_pwd);
	void operMenu();
	void viewWholeAppointment();
	vector<Order> readAppointmentFile();
	void examineAppointment();
	void updateAppointmentFILE(vector<Order>& orderV);
	string toStringDayOfWeek(int dayOfWeek);
	string toStringAmOrPm(int amOrPm);
	string toStringState(int state);
	int m_teacher_id;
};
