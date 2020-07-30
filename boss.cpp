#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->m_Name = name;
	this->m_Id = id;
	this->m_Depid = did;
}
void Boss::showInFo()
{
	cout << "职工编号为： " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位： " << this->getDepName()
		<< "\t岗位职责： 管理公司所有事务" << endl;
}
string Boss::getDepName()
{
	return string("老板");
}