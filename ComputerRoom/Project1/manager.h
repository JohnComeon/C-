
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
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	virtual void openMenu();

	void addPerson();   //添加账号

	void showPerson();

	void showComputer();   // 显示机房信息

	void clearRecord();

	void initVector();
	vector<Student> vStu;
	vector<Teacher> vTea;

	bool checkRepeat(int id, int type);   //检查是否是重复

	vector<ComputerRoom> vCom;

};
