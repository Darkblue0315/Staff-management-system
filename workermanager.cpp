
#include"ְ������ϵͳ.h"
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
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
			//cout << "�ļ�Ϊ��" << endl;
			this->m_Emparray = NULL;
			this->m_Empnum = 0;
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}
		else
		{
			int num = this->get_Empnum();
			//cout << "�ļ�����Ϊ�� " << num << endl;
			this->m_Empnum = num;
			this->m_Emparray = new Worker * [this->m_Empnum];
			this->init_emp();
			/*for (int i = 0;i < this->m_Empnum;i++)
			{
				cout << "ְ����ţ� " << this->m_Emparray[i]->m_Id
					<< "ְ�������� " << this->m_Emparray[i]->m_Name
					<< "���ű�ţ� " << this->m_Emparray[i]->m_Depid << endl;
			}*/
		}
	}
	this->m_Empnum = 0;
	this->m_Emparray = NULL;
}
void WorkerManager::Show_Menu()
{
	cout << "****************************************" << endl;
	cout << "**********��ӭʹ��ְ������ϵͳ**********" << endl;
	cout << "*************0.�˳�����ϵͳ*************" << endl;
	cout << "*************1.����ְ����Ϣ*************" << endl;
	cout << "*************2.��ʾְ����Ϣ*************" << endl;
	cout << "*************3.ɾ����ְְ��*************" << endl;
	cout << "*************4.�޸�ְ����Ϣ*************" << endl;
	cout << "*************5.����ְ����Ϣ*************" << endl;
	cout << "*************6.���ձ������*************" << endl;
	cout << "*************7.��������ĵ�*************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}
void WorkerManager::addemp()
{
	cout << "���������ְ��������" << endl;
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
			cout << "�������" << i + 1 << "����Ա���ı�ţ� " << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����Ա���������� " << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����Ա���Ĳ��ű�ţ� " << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		cout << "�ɹ����" << addnum << "��Ա��" << endl;
		this->save();
	}
	else
	{
		cout << "�������" << endl;
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
		cout << "�ļ���¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ�����" << endl;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "δ�ҵ���ְ����ɾ��ʧ��" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::Mod_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա���ı��" << endl;
		int id = 0;
		cin >> id;
		int ret = this->empisexit(id);
		if (ret != -1)
		{
			delete this->m_Emparray[ret];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "�������µı��" << endl;
			cin >> newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			cout << "�������µĸ�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
		{
			cout << "���޴��ˣ��޸�ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "���������Ĳ��ҷ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������Ҫ���ҵ�ְ�����" << endl;
			cin >>id;
			int ret = empisexit(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����" << endl;
				this->m_Emparray[ret]->showInFo();
			}
			else
			{
				cout << "���޴��ˣ�����ʧ��" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ���ҵ��˵�����" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0;i < m_Empnum;i++)
			{
				if (m_Emparray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ�� "
						<< this->m_Emparray[i]->m_Id << "��ְ����Ϣ���£� " << endl;
					m_Emparray[i]->showInFo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "���޴��ˣ�����ʧ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.��ְ����Ž�����������" << endl;
		cout << "2.��ְ����Ž��н�������" << endl;
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
		cout << "����ɹ��������Ľ��Ϊ: " << endl;
		save();
		show_emp();
	}
}
void WorkerManager::Clean_file()
{
	cout << "ȷ����գ�"<<endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (m_Emparray != NULL)//ɾ��������ÿ��ְ������
		{
			for (int i = 0;i < m_Empnum;i++)
			{
				delete m_Emparray[i];
				m_Emparray[i] = NULL;
			}
			//ɾ������������ָ��
			delete[] m_Emparray;
			m_Emparray = NULL;
			m_Empnum = 0;
			m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
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
