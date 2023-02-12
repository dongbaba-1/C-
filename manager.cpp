#include"manager.h"


void Manager::operMenu() {
	while (true) {
		//cout << "\t\t��ӭ������Ա��" << this->m_name << endl;
		cout << " \t\t-------------------------\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       1������˺�        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       2���鿴�˺�        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       3���鿴����        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       4�����ԤԼ        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       0��ע����¼        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t -------------------------\n";
		cout << "\t\t����������ѡ��";
		int chioce;
		cin >> chioce;
		if (chioce == 0) {
			cout << "ע���ɹ�!" << endl;
			break;
		}
		switch (chioce)
		{
		case 1:
			this->addAccount();
			system("pause");
			system("cls");
			break;
		case 2:
			this->viewAccount();
			system("pause");
			system("cls");
			break;
		case 3:
			this->viewComputerRoom();
			system("pause");
			system("cls");
			break;
		case 4:
			this->clearAppointment();
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

void Manager::addAccount() {
	int flag;
	int student_id;
	string student_name;
	int teacher_id;
	string teacher_name;
	int student_pwd;
	int teacher_pwd;
	int i;
	vector<Student> stuV;
	vector<Teacher> teaV;
	this->readStudentFile(stuV);
	this->readTeacherFile(teaV);
	cout << "ѡ����Ҫ��ӵ��˻����ͣ�" << endl;
	cout << "1��ѧ��    2����ʦ" << endl;
	cin >> flag;
	while (flag != 1 && flag != 2) {
		cout << "����������������룺" << endl;
		cin >> flag;

	}
	if (flag == 1) {
		cout << "������ѧ�ţ�" << endl;
		cin >> student_id;
		while (this->IsStudentIdExist(stuV, student_id,i)) {
			cout << "ѧ���ظ������������룺" << endl;
			cin >> student_id;
		}
		cout << "������������" << endl;
		cin >> student_name;
		cout << "����������" << endl;
		cin >> student_pwd;
		Student student(student_id,student_name,student_pwd);
		writeInStudentFile(student);
		cout << "��ӳɹ���" << endl;


	}
	else if (flag == 2) {
		cout << "������ְ���ţ�" << endl;
		cin >> teacher_id;
		while (this->IsTeacherIdExist(teaV,teacher_id,i))
		{
			cout << "ְ�����ظ�������������" << endl;
			cin >> teacher_id;
		}
		cout << "������������" << endl;
		cin >> teacher_name;
		cout << "����������" << endl;
		cin >> teacher_pwd;
		Teacher teacher(teacher_id, teacher_name, teacher_pwd);
		writeInTeacherFile(teacher);
		cout << "��ӳɹ���" << endl;

	}
}

void Manager::viewAccount() {
	int flag;
	vector<Student> stuV;
	vector<Teacher> teaV;
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	cin >> flag;
	while (flag != 1 && flag != 2) {
		cout << "����������������룺" << endl;
		cin >> flag;
	}
	if (flag == 1) {
		cout << "����ѧ����Ϣ���£�" << endl;
		this->readStudentFile(stuV);
		//for_each(stuV.begin(), stuV.end(), Myprint());
		for (int i = 0;i < stuV.size();i++) {
			cout << "ѧ�ţ�" << stuV[i].m_student_id << "\t������" << stuV[i].m_name << "\t���룺" << stuV[i].m_pwd<<endl;
		}
	}
	else if (flag == 2) {
		cout << "������ʦ��Ϣ���£�" << endl;
		this->readTeacherFile(teaV);
		for (int i = 0;i < teaV.size();i++) {
			cout << "ְ���ţ�" << teaV[i].m_teacher_id << "\t������" << teaV[i].m_name << "\t���룺" << teaV[i].m_pwd << endl;
		}
	}
}

void Manager::clearAppointment() {
	ofstream ofs;
	ofs.open(ORDERFILENAME, ios::out);
	ofs.close();
	cout << "����ɹ���" << endl;
}

void Manager::logOut() {

}

void Manager::viewComputerRoom() {
	cout << "������Ϣ���£�" << endl;
	ifstream ifs;
	vector<string> v;
	char c = ' ';
	ifs.open(ROOMFILENAME, ios::in);
	if (ifs.is_open()) {
		char buff[1024] = { 0 };
		while (ifs.getline(buff,sizeof(buff)))
		{
			//cout << buff << endl;
			string str;
			stringstream ss(buff);
			while (getline(ss, str, c)) {
				v.push_back(str);
			}
			cout << "������ţ�" << v[0] << "\t�������������" << v[1] << endl;
			v.clear();

		}
	}
	else {
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	ifs.close();
}

void Manager::writeInStudentFile(Student student) {
	ofstream ofs;
	ofs.open(STUFILENAME, ios::out | ios::app);
	ofs << student.m_student_id << " " << student.m_name << " " << student.m_pwd << endl;
	ofs.close();

}

void Manager::writeInTeacherFile(Teacher teacher) {
	ofstream ofs;
	ofs.open(TEAFILENAME, ios::out | ios::app);
	ofs << teacher.m_teacher_id << " " << teacher.m_name << " " << teacher.m_pwd << endl;
	ofs.close();

}

void Manager::readStudentFile(vector<Student>& stuVector) {
	ifstream ifs;
	char c = ' ';
	vector<string> v;
	ifs.open(STUFILENAME, ios::in);
	if (ifs.is_open()) {
		char buff[1024] = { 0 };
		while (ifs.getline(buff,sizeof(buff))) {
			
			int student_id;
			string student_name;
			int student_pwd;

			//cout << buff << endl;
			string str;
			stringstream ss(buff);

			
			while (getline(ss, str, c)) {
				v.push_back(str);
			}
			/*for (int i = 0;i < v.size();i++) {
				cout << "v" << i << " " << v[i] << endl;
			}*/
			stringstream id;
			stringstream pwd;
			id << v[0];
			id >> student_id;//stringת��Ϊint��
			student_name = v[1];
			pwd << v[2];
			pwd >> student_pwd;
			Student student(student_id,student_name,student_pwd);//����һ������
			stuVector.push_back(student);
			v.clear();
		}
	}
	else {
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	ifs.close();
}

void Manager::readTeacherFile(vector<Teacher>& teaVector) {
	ifstream ifs;
	char c = ' ';
	vector<string> v;
	ifs.open(TEAFILENAME, ios::in);
	if (ifs.is_open()) {
		char buff[1024] = { 0 };
		while (ifs.getline(buff, sizeof(buff))) {

			int teacher_id;
			string teacher_name;
			int teacher_pwd;

			//cout << buff << endl;
			string str;
			stringstream ss(buff);


			while (getline(ss, str, c)) {
				v.push_back(str);
			}
			/*for (int i = 0;i < v.size();i++) {
				cout << "v" << i << " " << v[i] << endl;
			}*/
			stringstream id;
			stringstream pwd;
			id << v[0];
			id >> teacher_id;//stringת��Ϊint��
			teacher_name = v[1];
			pwd << v[2];
			pwd >> teacher_pwd;//stringת��Ϊint��
			Teacher teacher(teacher_id,teacher_name,teacher_pwd);//����һ������
			teaVector.push_back(teacher);
			v.clear();
		}
	}
	else {
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	ifs.close();
}

void Manager::readManagerFile(vector<Manager>& manVector)
{
	ifstream ifs;
	ifs.open(MANAGERFILE, ios::in);
	char buff[1024] = { 0 };
	char c = ' ';
	vector<string> v;
	int manager_pwd;
	while (ifs.getline(buff, sizeof(buff)))
	{
		string str;
		stringstream ss(buff);
		while (getline(ss, str, c)) {
			v.push_back(str);
		}
		Manager manager;
		stringstream pwd;
		pwd << v[1];
		pwd >> manager_pwd;
		manager.m_name = v[0];
		manager.m_pwd = manager_pwd;
		manVector.push_back(manager);
		v.clear();
	}
	ifs.close();
}

bool Manager::IsStudentIdExist(vector<Student> stu, int student_id,int &i) {
	for (i = 0;i < stu.size();i++) {
		if (stu[i].m_student_id == student_id) {
			return true;
		}
	}
	return false;
}

bool Manager::IsTeacherIdExist(vector<Teacher> teac, int teacher_id,int &i) {
	for (i = 0;i < teac.size();i++) {
		if (teac[i].m_teacher_id == teacher_id) {
			return true;
		}
	}
	return false;
}

bool Manager::IsManagerNameExist(vector<Manager> man, string manager_name,int &i) {
	for (i = 0;i < man.size();i++) {
		if (man[i].m_name == manager_name) {
			return true;
		}
	}
	return false;
}
void Manager::managerLogIn()
{
	vector<Manager> manV;
	this->readManagerFile(manV);
	string manager_name;
	int manager_pwd;
	int i;
	cout << "���������Ա���֣�" << endl;
	cin >> manager_name;
	if (this->IsManagerNameExist(manV,manager_name,i)) {
		cout << "���������Ա�˺����룺" << endl;
		cin >> manager_pwd;
		while (manV[i].m_pwd != manager_pwd) {
			cout << "����������������룺" << endl;
			cin >> manager_pwd;
		}
		cout << "��¼�ɹ���" << endl;
		system("pause");
		system("cls");
		cout << "��ӭ��������Ա��" << manV[i].m_name << endl;
		this->operMenu();
	}
	else {
		cout << "�����ڸù���Ա��" << endl;
		return;

	}
	/*for (i = 0;i < manV.size();i++) {
		if (manV[i].m_name == manager_name) {
			cout << "���������Ա�˺����룺" << endl;
			cin >> manager_pwd;
			while (manV[i].m_pwd != manager_pwd) {
				cout << "����������������룺" << endl;
				cin >> manager_pwd;
			}
			cout << "��¼�ɹ���" << endl;
			this->operMenu();
		}
	}
	if (i == manV.size()) {
		cout << "�����ڸù���Ա��" << endl;
		return;
	}*/

	
}

void Manager::studentLogIn() {
	vector<Student> stuV;
	this->readStudentFile(stuV);
	int student_id;
	int student_pwd;
	int i;
	cout << "������ѧ�ţ�" << endl;
	cin >> student_id;
	if (this->IsStudentIdExist(stuV, student_id, i)) {
		cout << "���������룺" << endl;
		cin >> student_pwd;
		while (stuV[i].m_pwd != student_pwd) {
			cout << "����������������룺" << endl;
			cin >> student_pwd;
		}
		cout << "��¼�ɹ���" << endl;
		system("pause");
		system("cls");
		Student student(student_id,stuV[i].m_name);
		student.operMenu();
	}
	else {
		cout << "��ѧ�Ų����ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
}

void Manager::teacherLogIn() {
	vector<Teacher> teaV;
	this->readTeacherFile(teaV);
	int teacher_id;
	int teacher_pwd;
	int i;
	cout << "������ְ���ţ�" << endl;
	cin >> teacher_id;
	if (this->IsTeacherIdExist(teaV,teacher_id,i)) {
		cout << "���������룺" << endl;
		cin >> teacher_pwd;
		while (teaV[i].m_pwd != teacher_pwd) {
			cout << "����������������룺" << endl;
			cin >> teacher_pwd;
		}
		cout << "��¼�ɹ���" << endl;
		system("pause");
		system("cls");
		Teacher teacher(teacher_id);
		teacher.operMenu();
	}
	else {
		cout << "��ְ���Ų����ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
}

