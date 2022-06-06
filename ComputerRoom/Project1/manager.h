
#include<iostream>
#include <string>

#include "Identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

using namespace std;

class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	virtual void openMenu();

	void addPerson();   //����˺�

	void showPerson();

	void showComputer();   // ��ʾ������Ϣ

	void clearRecord();

	void initVector();
	vector<Student> vStu;
	vector<Teacher> vTea;

	bool checkRepeat(int id, int type);   //����Ƿ����ظ�

	vector<ComputerRoom> vCom;

};
