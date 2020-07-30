#pragma once
#include<iostream>
using namespace std;
//#include"boss.h"
//#include"employee.h"
//#include"manager.h"
class Worker
{
public:
	virtual void showInFo() = 0;
	virtual string getDepName() = 0;
	int m_Id;
	string m_Name;
	int m_Depid;
};
