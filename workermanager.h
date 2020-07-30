#pragma once//防止头文件重复包含
#include<fstream>
#define FILENAME  "empfile.txt"
#include<iostream>
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
using namespace std;
class WorkerManager
{
public:
	WorkerManager();
	void Show_Menu();
	void ExitSystem();
	void addemp();
	void save();
	int get_Empnum();
	void init_emp();
	void show_emp();
	void del_emp();
	int empisexit(int id);
	void Mod_emp();
	void Find_emp();
	void Sort_emp();
	void Clean_file();
	~WorkerManager();
	int m_Empnum;
	Worker** m_Emparray;
	bool m_FileIsEmpty;
};
