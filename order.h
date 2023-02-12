#pragma once
#include<iostream>
using namespace std;

class Order
{
public:
	Order(int dayOfWeek,int amOrPm,int roomId,int orderByStudentId,string orderByStudentName,int state);
	
	int m_dayOfWeek;
	int m_amOrPm;
	int m_roomId;
	int m_orderByStudentId;
	int m_state;
	string m_orderByStudentName;

};




