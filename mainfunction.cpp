#include<iostream>
using namespace std;
#include"ְ������ϵͳ.h"
#include"worker.h"
#include"employee.h"
int main()
{
	/*Worker* worker = NULL;
	worker = new Employee(1, "����",1);
	worker->showInFo();*/
	WorkerManager wm;
	int choice=0;
	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch(choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.addemp();
			break;
		case 2:
			wm.show_emp();
			break;
		case 3:
			wm.del_emp();
			break;
		case 4:
			wm.Mod_emp();
			break;
		case 5:
			wm.Find_emp();
			break;
		case 6:
			wm.Sort_emp();
			break;
		case 7:
			wm.Clean_file();
			break;
		default:
			system("cls");
			break;


		}
	}
	system("pause");
	return 0;
}