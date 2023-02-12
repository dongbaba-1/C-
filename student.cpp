#include"student.h"

Student::Student(int student_id,string student_name) {
	this->m_student_id = student_id;
	this->m_name = student_name;
}
Student::Student(int student_id, string student_name, int student_pwd) {
	this->m_student_id = student_id;
	this->m_name = student_name;
	this->m_pwd = student_pwd;
}

void Student::operMenu() {
	
	while (true) {
		cout << "\t\t -----------------------------\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         1、申请预约          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         2、查看我的预约      |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         3、查看所有预约      |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         4、取消预约          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         0、注销登录          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t -----------------------------\n";
		cout << endl << "请输入您要使用的功能:";
		int chioce;
		cin >> chioce;
		vector<Order> order;
		if (chioce == 0) {
			cout << "注销成功！" <<endl;
			system("pause");
			system("cls");
			break;
		}
		switch (chioce)
		{
		case 1:
			this->applyAppointment();
			system("pause");
			system("cls");
			break;
		case 2:
			this->viewMyAppointment();
			system("pause");
			system("cls");
			break;
		case 3:
			this->viewWholeAppointment();
			system("pause");
			system("cls");
			break;
		case 4:
			order = this->readAppointmentFile();
			this->cancelAppointment(order);
			break;
		default:
			cout << "输入有误请重新输入：" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}


void Student::applyAppointment() {
	int dayOfweek;
	int amOrpm;
	int roomId;
	//int orderByStudentId;
	cout << "请选择预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	
	cin >> dayOfweek;
	cout << endl << "请选择预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	cin >> amOrpm;
	cout << "请选择预约的机房：" << endl;
	cout << "1号机房容量：20" << endl;
	cout << "2号机房容量：50" << endl;
	cout << "3号机房容量：100" << endl;
	cin >> roomId;
	//Order order(dayOfweek,amOrpm,roomId,this->m_student_id,this->m_name);
	ofstream ofs;
	ofs.open(ORDERFILENAME, ios::out|ios::app);
	ofs << dayOfweek << " " << amOrpm << " " << roomId <<" " <<this->m_student_id << " " <<this->m_name<<" " << 1 <<endl;//1是待审核
	cout << "预约成功！" << endl;
	ofs.close();
}

void Student::viewMyAppointment() {
	vector<Order> orderV = this->readAppointmentFile();
	string dayOfWeek;
	string amOrPm;
	string state;
	cout << "我的预约信息如下：" << endl;
	for (int i = 0;i < orderV.size();i++) {
		if (orderV[i].m_orderByStudentId == this->m_student_id) {
			dayOfWeek = this->toStringDayOfWeek(orderV[i].m_dayOfWeek);
			amOrPm = this->toStringAmOrPm(orderV[i].m_amOrPm);
			state = this->toStringState(orderV[i].m_state);
			cout << "预约时间：" << dayOfWeek << "\t预约时间段：" << amOrPm << "\t预约机房号：" << orderV[i].m_roomId
				<< "号\t预约学号：" << orderV[i].m_orderByStudentId << "\t预约学生姓名：" << orderV[i].m_orderByStudentName  
				<<"\t预约状态：" << state<<endl;
		}
	}
}

void Student::viewWholeAppointment() {
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
			<< "号\t预约学号：" << it->m_orderByStudentId << "\t预约学生姓名：" << it->m_orderByStudentName <<"\t预约状态："<<state<<endl;
	}
	
}

void Student::cancelAppointment(vector<Order>& orderV) {
	int chioce;
	cout << "审核中或预约成功的记录可以取消，待输入取消的记录" << endl;
	this->viewMyAppointment();
	cout << "输入“1”确认取消，输入“0”返回：" << endl;
	cin >> chioce;
	if (chioce == 1) {
		for (vector<Order>::iterator it = orderV.begin();it != orderV.end();it++) {
			if (it->m_orderByStudentId == this->m_student_id) {
				it->m_state = 4;//状态修改为4：已取消
			}
		}
		this->updateAppointmentFILE(orderV);
		cout << "取消成功！" << endl;
	}
	else {
		return;
	}

}

void Student::updateAppointmentFILE(vector<Order>&orderV) {
	ofstream ofs;
	ofs.open(ORDERFILENAME, ios::out);
	for (int i = 0;i < orderV.size();i++) {
		ofs << orderV[i].m_dayOfWeek << " " << orderV[i].m_amOrPm << " " << orderV[i].m_roomId << " " 
			<< orderV[i].m_orderByStudentId << " " << orderV[i].m_orderByStudentName << " " << orderV[i].m_state << endl;
	}
	ofs.close();
}

string Student::toStringDayOfWeek(int dayOfWeek)
{
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

string Student::toStringAmOrPm(int amOrPm)
{
	if (amOrPm == 1) {
		return string("上午");
	}
	else if (amOrPm == 2) {
		return string("下午");
	}
}

string Student::toStringState(int state)
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

vector<Order> Student::readAppointmentFile() {
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
}