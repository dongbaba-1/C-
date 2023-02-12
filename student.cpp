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
		cout << "\t\t|         1������ԤԼ          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         2���鿴�ҵ�ԤԼ      |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         3���鿴����ԤԼ      |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         4��ȡ��ԤԼ          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         0��ע����¼          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t -----------------------------\n";
		cout << endl << "��������Ҫʹ�õĹ���:";
		int chioce;
		cin >> chioce;
		vector<Order> order;
		if (chioce == 0) {
			cout << "ע���ɹ���" <<endl;
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
			cout << "�����������������룺" << endl;
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
	cout << "��ѡ��ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	
	cin >> dayOfweek;
	cout << endl << "��ѡ��ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	cin >> amOrpm;
	cout << "��ѡ��ԤԼ�Ļ�����" << endl;
	cout << "1�Ż���������20" << endl;
	cout << "2�Ż���������50" << endl;
	cout << "3�Ż���������100" << endl;
	cin >> roomId;
	//Order order(dayOfweek,amOrpm,roomId,this->m_student_id,this->m_name);
	ofstream ofs;
	ofs.open(ORDERFILENAME, ios::out|ios::app);
	ofs << dayOfweek << " " << amOrpm << " " << roomId <<" " <<this->m_student_id << " " <<this->m_name<<" " << 1 <<endl;//1�Ǵ����
	cout << "ԤԼ�ɹ���" << endl;
	ofs.close();
}

void Student::viewMyAppointment() {
	vector<Order> orderV = this->readAppointmentFile();
	string dayOfWeek;
	string amOrPm;
	string state;
	cout << "�ҵ�ԤԼ��Ϣ���£�" << endl;
	for (int i = 0;i < orderV.size();i++) {
		if (orderV[i].m_orderByStudentId == this->m_student_id) {
			dayOfWeek = this->toStringDayOfWeek(orderV[i].m_dayOfWeek);
			amOrPm = this->toStringAmOrPm(orderV[i].m_amOrPm);
			state = this->toStringState(orderV[i].m_state);
			cout << "ԤԼʱ�䣺" << dayOfWeek << "\tԤԼʱ��Σ�" << amOrPm << "\tԤԼ�����ţ�" << orderV[i].m_roomId
				<< "��\tԤԼѧ�ţ�" << orderV[i].m_orderByStudentId << "\tԤԼѧ��������" << orderV[i].m_orderByStudentName  
				<<"\tԤԼ״̬��" << state<<endl;
		}
	}
}

void Student::viewWholeAppointment() {
	vector<Order> orderV = this->readAppointmentFile();
	cout << "����ԤԼ��Ϣ���£�" << endl;
	string dayOfWeek;
	string amOrPm;
	string state;
	for (vector<Order>::iterator it = orderV.begin();it != orderV.end();it++) {
		dayOfWeek = this->toStringDayOfWeek(it->m_dayOfWeek);
		amOrPm = this->toStringAmOrPm(it->m_amOrPm);
		state = this->toStringState(it->m_state);
		cout << "ԤԼʱ�䣺" << dayOfWeek << "\tԤԼʱ��Σ�" << amOrPm << "\tԤԼ�����ţ�" << it->m_roomId
			<< "��\tԤԼѧ�ţ�" << it->m_orderByStudentId << "\tԤԼѧ��������" << it->m_orderByStudentName <<"\tԤԼ״̬��"<<state<<endl;
	}
	
}

void Student::cancelAppointment(vector<Order>& orderV) {
	int chioce;
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	this->viewMyAppointment();
	cout << "���롰1��ȷ��ȡ�������롰0�����أ�" << endl;
	cin >> chioce;
	if (chioce == 1) {
		for (vector<Order>::iterator it = orderV.begin();it != orderV.end();it++) {
			if (it->m_orderByStudentId == this->m_student_id) {
				it->m_state = 4;//״̬�޸�Ϊ4����ȡ��
			}
		}
		this->updateAppointmentFILE(orderV);
		cout << "ȡ���ɹ���" << endl;
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
		return string("��һ");
	}
	else if (dayOfWeek == 2) {
		return string("�ܶ�");
	}
	else if (dayOfWeek == 3) {
		return string("����");
	}
	else if (dayOfWeek == 4)
	{
		return string("����");
	}
	else if (dayOfWeek == 5) {
		return string("����");
	}
}

string Student::toStringAmOrPm(int amOrPm)
{
	if (amOrPm == 1) {
		return string("����");
	}
	else if (amOrPm == 2) {
		return string("����");
	}
}

string Student::toStringState(int state)
{
	if (state == 1) {
		return string("�����");
	}
	else if (state == 2) {
		return string("�����ͨ��");
	}
	else if (state == 3) {
		return string("���δͨ��");
	}
	else if (state == 4) {
		return string("��ȡ��");
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