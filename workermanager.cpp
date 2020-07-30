
#include"职工管理系统.h"
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_Emparray = NULL;
		this->m_Empnum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else
	{
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			//cout << "文件为空" << endl;
			this->m_Emparray = NULL;
			this->m_Empnum = 0;
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}
		else
		{
			int num = this->get_Empnum();
			//cout << "文件人数为： " << num << endl;
			this->m_Empnum = num;
			this->m_Emparray = new Worker * [this->m_Empnum];
			this->init_emp();
			/*for (int i = 0;i < this->m_Empnum;i++)
			{
				cout << "职工编号： " << this->m_Emparray[i]->m_Id
					<< "职工姓名： " << this->m_Emparray[i]->m_Name
					<< "部门编号： " << this->m_Emparray[i]->m_Depid << endl;
			}*/
		}
	}
	this->m_Empnum = 0;
	this->m_Emparray = NULL;
}
void WorkerManager::Show_Menu()
{
	cout << "****************************************" << endl;
	cout << "**********欢迎使用职工管理系统**********" << endl;
	cout << "*************0.退出管理系统*************" << endl;
	cout << "*************1.增加职工信息*************" << endl;
	cout << "*************2.显示职工信息*************" << endl;
	cout << "*************3.删除离职职工*************" << endl;
	cout << "*************4.修改职工信息*************" << endl;
	cout << "*************5.查找职工信息*************" << endl;
	cout << "*************6.按照编号排序*************" << endl;
	cout << "*************7.清空所有文档*************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}
void WorkerManager::addemp()
{
	cout << "请输入添加职工的数量" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_Empnum + addnum;
		Worker** newspace = new Worker * [newsize];
		if (this->m_Emparray != NULL)
		{
			for (int i = 0;i < this->m_Empnum;i++)
			{
				newspace[i] = this->m_Emparray[i];
			}
		}
		for (int i = 0;i < addnum;i++)
		{
			int id;
			string name;
			int did;
			cout << "请输入第" << i + 1 << "个新员工的编号： " << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新员工的姓名： " << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新员工的部门编号： " << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[this->m_Empnum + i] = worker;
		}
		delete[] this->m_Emparray;
		this->m_Emparray = newspace;
		this->m_Empnum = newsize;
		cout << "成功添加" << addnum << "名员工" << endl;
		this->save();
	}
	else
	{
		cout << "添加有误" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0;i < this->m_Empnum;i++)
	{
		ofs << this->m_Emparray[i]->m_Id << " "
			<< this->m_Emparray[i]->m_Name << " "
			<< this->m_Emparray[i]->m_Depid << endl;
	}
	ofs.close();
}
int WorkerManager::get_Empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	int name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}
void WorkerManager::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did = 1)
		{
			worker = new Employee(id, name, did);
		}
		if (did = 2)
		{
			worker = new Manager(id, name, did);
		}
		if (did = 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_Emparray[index] = worker;
		index++;
		ifs.close();
	}
}
void WorkerManager::show_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件记录为空" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_Empnum;i++)
		{
			this->m_Emparray[i]->showInFo();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::empisexit(int id)
{
	int index = -1;
	for (int i = 0;i < this->m_Empnum;i++)
	{
		if (this->m_Emparray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::del_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->empisexit(id);
		if (index != -1)
		{
			for (int i = index;i < this->m_Empnum - 1;i++)
			{
				this->m_Emparray[i] = this->m_Emparray[i + 1];
			}
			m_Empnum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "未找到该职工，删除失败" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::Mod_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的员工的编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->empisexit(id);
		if (ret != -1)
		{
			delete this->m_Emparray[ret];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "请输入新的编号" << endl;
			cin >> newid;
			cout << "请输入新的姓名" << endl;
			cin >> newname;
			cout << "请输入新的岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newdid;
			Worker* worker = NULL;
			switch (newdid)
			{
			case 1:
				worker = new Employee(newid, newname, newdid);
				break;
			case 2:
				worker = new Manager(newid, newname, newdid);
				break;
			case 3:
				worker = new Boss(newid, newname, newdid);
				break;
			default:
				break;
			}
			this->m_Emparray[ret] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "查无此人，修改失败" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入您的查找方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入您要查找的职工编号" << endl;
			cin >>id;
			int ret = empisexit(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下" << endl;
				this->m_Emparray[ret]->showInFo();
			}
			else
			{
				cout << "查无此人，查找失败" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找的人的姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0;i < m_Empnum;i++)
			{
				if (m_Emparray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为： "
						<< this->m_Emparray[i]->m_Id << "号职工信息如下： " << endl;
					m_Emparray[i]->showInFo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人，查找失败" << endl;
			}
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::Sort_emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按职工编号进行升序排序" << endl;
		cout << "2.按职工编号进行降序排序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0;i < m_Empnum;i++)
		{
			int minormax = i;
			for (int j = i + 1;j < m_Empnum;j++)
			{
				if (select == 1)
				{
					if (m_Emparray[minormax]->m_Id > m_Emparray[j]->m_Id)
					{
						minormax = j;
					}
				
				}
				else
				{
					if (m_Emparray[minormax]->m_Id < m_Emparray[j]->m_Id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				Worker* temp = m_Emparray[i];
				m_Emparray[i] = m_Emparray[minormax];
				m_Emparray[minormax] = temp;

			}

		}
		cout << "排序成功，排序后的结果为: " << endl;
		save();
		show_emp();
	}
}
void WorkerManager::Clean_file()
{
	cout << "确定清空？"<<endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (m_Emparray != NULL)//删除堆区的每个职工对象
		{
			for (int i = 0;i < m_Empnum;i++)
			{
				delete m_Emparray[i];
				m_Emparray[i] = NULL;
			}
			//删除堆区的数组指针
			delete[] m_Emparray;
			m_Emparray = NULL;
			m_Empnum = 0;
			m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{
	if (this->m_Emparray != NULL)
	{
		delete[] this->m_Emparray;
		this->m_Emparray = NULL;
	}
}
