#include<iostream>
using namespace std;
#include"职工管理系统.h"
#include"worker.h"
#include"employee.h"
int main()
{
	/*Worker* worker = NULL;
	worker = new Employee(1, "张三",1);
	worker->showInFo();*/
	WorkerManager wm;
	int choice=0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择" << endl;
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