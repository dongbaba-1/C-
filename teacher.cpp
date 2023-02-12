#include"teacher.h"

Teacher::Teacher(int teacher_id)
{
	this->m_teacher_id = teacher_id;
}

Teacher::Teacher(int teacher_id, string teacher_name, int teacher_pwd) {
	this->m_teacher_id = teacher_id;
	this->m_name = teacher_name;
	this->m_pwd = teacher_pwd;
}
void Teacher::operMenu() {
	while (true)
	{
		cout << "\t\t -----------------------------\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        1、查看所有预约       |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        2、审核预约           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        0、注销登录           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t -----------------------------\n";
		cout << endl << "请输入您要使用的功能:";
		int chioce;
		cin >> chioce;
		if (chioce == 0) {
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			break;
		}
		switch (chioce)
		{
		case 1:
			this->viewWholeAppointment();
			system("pause");
			system("cls");
			break;
		case 2:
			this->examineAppointment();
			system("pause");
			system("cls");
			break;
		default:
			cout << "输入有误请重新输入：" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}

void Teacher::viewWholeAppointment()
{
	vector<Order> orderV = this->readAppointmentFile();
	cout << "所有预约信息如下：" << endl;
	string dayOfWeek;
	string amOrPm;
	string state;
	for (vector<Order>::iterator it = orderV.begin();it != orderV.end();it++) {
		dayOfWeek = this->toStringDayOfWeek(it->m_dayOfWeek);
		amOrPm = this->toStringAmOrPm(it->m_amOrPm);
		state = this->toStringState(it->m_state);
		cout << "预约时间：" << dayOfWeek << "\t预约时间段：" << amOrPm << "\t预约机房号：" << it->m_roomId
			<< "号\t预约学号：" << it->m_orderByStudentId << "\t预约学生姓名：" << it->m_orderByStudentName << "\t预约状态：" << state << endl;
	}
}

vector<Order> Teacher::readAppointmentFile()
{
	ifstream ifs;
	ifs.open(ORDERFILENAME, ios::in);
	char c = ' ';
	vector<Order> ordV;
	vector<string> strV;
	char buff[1024] = { 0 };
	int dayOfWeek;
	int amOrPm;
	int roomId;
	int orderByStudentId;
	int state;
	while (ifs.getline(buff, sizeof(buff)))
	{
		string str;
		stringstream ss(buff);
		while (getline(ss, str, c)) {
			strV.push_back(str);
		}
		stringstream ss_dayOfWeek;
		stringstream ss_amOrPm;
		stringstream ss_roomId;
		stringstream ss_orderByStudentId;
		stringstream ss_state;
		ss_dayOfWeek << strV[0];
		ss_dayOfWeek >> dayOfWeek;
		ss_amOrPm << strV[1];
		ss_amOrPm >> amOrPm;
		ss_roomId << strV[2];
		ss_roomId >> roomId;
		ss_orderByStudentId << strV[3];
		ss_orderByStudentId >> orderByStudentId;
		ss_state << strV[5];
		ss_state >> state;
		Order order(dayOfWeek, amOrPm, roomId, orderByStudentId, strV[4], state);
		ordV.push_back(order);
		strV.clear();
	}
	return ordV;
	//return vector<Order>();
}

string Teacher::toStringDayOfWeek(int dayOfWeek) {
	if (dayOfWeek == 1) {
		return string("周一");
	}
	else if (dayOfWeek == 2) {
		return string("周二");
	}
	else if (dayOfWeek == 3) {
		return string("周三");
	}
	else if (dayOfWeek == 4)
	{
		return string("周四");
	}
	else if (dayOfWeek == 5) {
		return string("周五");
	}
}

string Teacher::toStringAmOrPm(int amOrPm)
{
	if (amOrPm == 1) {
		return string("上午");
	}
	else if (amOrPm == 2) {
		return string("下午");
	}
}

string Teacher::toStringState(int state)
{
	if (state == 1) {
		return string("待审核");
	}
	else if (state == 2) {
		return string("审核已通过");
	}
	else if (state == 3) {
		return string("审核未通过");
	}
	else if (state == 4) {
		return string("已取消");
	}
}

void Teacher::examineAppointment() {
	vector<Order> orderV = this->readAppointmentFile();
	string dayOfWeek;
	string amOrPm;
	string state;
	int num = 0;//记录不用审核的记录数
	int chioce;
	for (vector<Order>::iterator it = orderV.begin();it != orderV.end();it++) {
		if (it->m_state == 1) {//待审核的预约
			dayOfWeek = this->toStringDayOfWeek(it->m_dayOfWeek);
			amOrPm = this->toStringAmOrPm(it->m_amOrPm);
			state = this->toStringState(it->m_state);
			cout << endl<<"待审核的预约如下：" << endl;
			cout << "预约时间：" << dayOfWeek << "\t预约时间段：" << amOrPm << "\t预约机房号：" << it->m_roomId
				<< "号\t预约学号：" << it->m_orderByStudentId << "\t预约学生姓名：" << it->m_orderByStudentName << "\t预约状态：" << state << endl;
			cout << "是否通过审核？1、通过 2、不通过" << endl;
			cin >> chioce;
			if (chioce == 1) {
				it->m_state = 2;//预约状态改为通过
				this->updateAppointmentFILE(orderV);
			}
			else {
				it->m_state = 3;//预约状态改为未通过
				this->updateAppointmentFILE(orderV);
			}
			cout << "该条预约审核完成！" << endl;
		}
		else {
			num++;
		}
	}
	if (num == orderV.size()) {
		cout << "当前没有需要审核的预约！" << endl;
	}
}

void Teacher::updateAppointmentFILE(vector<Order>& orderV)
{
	ofstream ofs;
	ofs.open(ORDERFILENAME, ios::out);
	for (int i = 0;i < orderV.size();i++) {
		ofs << orderV[i].m_dayOfWeek << " " << orderV[i].m_amOrPm << " " << orderV[i].m_roomId << " "
			<< orderV[i].m_orderByStudentId << " " << orderV[i].m_orderByStudentName << " " << orderV[i].m_state << endl;
	}
	ofs.close();
}
