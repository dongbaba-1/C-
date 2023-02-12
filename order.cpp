#include"order.h"

Order::Order(int dayOfWeek, int amOrPm, int roomId, int orderByStudentId,string orderByStudentName,int state)
{
	this->m_dayOfWeek = dayOfWeek;
	this->m_amOrPm = amOrPm;
	this->m_roomId = roomId;
	this->m_orderByStudentId = orderByStudentId;
	this->m_orderByStudentName = orderByStudentName;
	this->m_state = state;
}
