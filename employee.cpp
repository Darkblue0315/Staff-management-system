#include"employee.h"
Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Depid = did;
}
void Employee::showInFo()
{
	cout << "职工编号为： " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位： " << this->getDepName()
		<< "\t岗位职责： 完成经理交给的任务" << endl;
}
string Employee::getDepName()
{
	return string("员工");
}