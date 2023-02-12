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
		cout << "\t\t|        1���鿴����ԤԼ       |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        2�����ԤԼ           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        0��ע����¼           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t -----------------------------\n";
		cout << endl << "��������Ҫʹ�õĹ���:";
		int chioce;
		cin >> chioce;
		if (chioce == 0) {
			cout << "ע���ɹ���" << endl;
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
			cout << "�����������������룺" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}

void Teacher::viewWholeAppointment()
{
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
			<< "��\tԤԼѧ�ţ�" << it->m_orderByStudentId << "\tԤԼѧ��������" << it->m_orderByStudentName << "\tԤԼ״̬��" << state << endl;
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

string Teacher::toStringAmOrPm(int amOrPm)
{
	if (amOrPm == 1) {
		return string("����");
	}
	else if (amOrPm == 2) {
		return string("����");
	}
}

string Teacher::toStringState(int state)
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

void Teacher::examineAppointment() {
	vector<Order> orderV = this->readAppointmentFile();
	string dayOfWeek;
	string amOrPm;
	string state;
	int num = 0;//��¼������˵ļ�¼��
	int chioce;
	for (vector<Order>::iterator it = orderV.begin();it != orderV.end();it++) {
		if (it->m_state == 1) {//����˵�ԤԼ
			dayOfWeek = this->toStringDayOfWeek(it->m_dayOfWeek);
			amOrPm = this->toStringAmOrPm(it->m_amOrPm);
			state = this->toStringState(it->m_state);
			cout << endl<<"����˵�ԤԼ���£�" << endl;
			cout << "ԤԼʱ�䣺" << dayOfWeek << "\tԤԼʱ��Σ�" << amOrPm << "\tԤԼ�����ţ�" << it->m_roomId
				<< "��\tԤԼѧ�ţ�" << it->m_orderByStudentId << "\tԤԼѧ��������" << it->m_orderByStudentName << "\tԤԼ״̬��" << state << endl;
			cout << "�Ƿ�ͨ����ˣ�1��ͨ�� 2����ͨ��" << endl;
			cin >> chioce;
			if (chioce == 1) {
				it->m_state = 2;//ԤԼ״̬��Ϊͨ��
				this->updateAppointmentFILE(orderV);
			}
			else {
				it->m_state = 3;//ԤԼ״̬��Ϊδͨ��
				this->updateAppointmentFILE(orderV);
			}
			cout << "����ԤԼ�����ɣ�" << endl;
		}
		else {
			num++;
		}
	}
	if (num == orderV.size()) {
		cout << "��ǰû����Ҫ��˵�ԤԼ��" << endl;
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
