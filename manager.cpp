#include"manager.h"
Manager::Manager(int id, string name, int did)
{
	this->m_Name = name;
	this->m_Id = id;
	this->m_Depid = did;
}
void Manager::showInFo()
{
	cout << "职工编号为： " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位： " << this->getDepName()
		<< "\t岗位职责： 完成老板交给的任务" << endl;
}
string Manager::getDepName()
{
	return string("经理");
}