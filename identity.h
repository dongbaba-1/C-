#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include"order.h"
#include"globelFile.h"
using namespace std;

class Identity {
public:
	Identity();
	virtual void operMenu() = 0;//´¿Ðéº¯Êý
	
 	string m_name;
	int m_pwd;

};
