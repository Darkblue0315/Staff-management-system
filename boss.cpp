#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->m_Name = name;
	this->m_Id = id;
	this->m_Depid = did;
}
void Boss::showInFo()
{
	cout << "ְ�����Ϊ�� " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ�� " << this->getDepName()
		<< "\t��λְ�� ����˾��������" << endl;
}
string Boss::getDepName()
{
	return string("�ϰ�");
}