#pragma once
#include<iostream>
#include"identity.h"
using namespace std;

class Student:public Identity {
	
public:
	Student(int student_id,string student_name);
	Student(int student_id, string student_name, int student_pwd);
	void operMenu();

	void applyAppointment();
	void viewMyAppointment();
	void viewWholeAppointment();
	void cancelAppointment(vector<Order>& orderV);
	void updateAppointmentFILE(vector<Order>& orderV);
	string toStringDayOfWeek(int dayOfWeek);
	string toStringAmOrPm(int amOrPm);
	string toStringState(int state);
	vector<Order> readAppointmentFile();
	int m_student_id;
	
};
