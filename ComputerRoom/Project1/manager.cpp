/*
 * @Author: John
 * @Date: 2022-05-26 13:59:06
 * @LastEditors: John
 * @LastEditTime: 2022-06-01 19:06:47
 * @FilePath: \Room\manager.cpp
 * @Description:
 */

#include "manager.h"
#include "globalFile.h"
#include <fstream>
#include "student.h"
#include "teacher.h"
#include<algorithm>


Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	//初始化
	this->m_name = name;
	this->m_pwd = pwd;

	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs>>com.m_comId && ifs>>com.m_MaxNum)
	{
		vCom.emplace_back(com);
	}
	ifs.close();
	cout << "机房的数量为 " << vCom.size() << endl;
}

void Manager::openMenu()
{
	cout << "Welcome " << this->m_name << endl;
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.Add person         |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.Show person        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.Show Computer      |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.Exit...          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";

}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、Add Student..." << endl;
	cout << "2、Add Teacher..." << endl;

	string fileName;   //操作文件名
	string tip;      // 提示ID号
	
	ofstream ofs;     //文件操作对象

	string errortip;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号： ";
		errortip = "学号重复，请重新输入...";
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工号： ";
		errortip = "职工号重复，请重新输入...";
	}

	ofs.open(fileName, ios::out | ios::app);  //追加的方式写文件
	cout << tip << endl;

	int id;
	string name, pwd;

	while (true)
	{
		cin >> id;
		bool res = checkRepeat(id, select);
		if (res)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << "请输入姓名： ";
	cin >> name;
	cout << "请输入密码： ";
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功..." << endl;
	system("pause");
	system("cls");
	ofs.close();

	this->initVector();   //重新调用初始化容器
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs>>s.m_id && ifs>>s.m_name && ifs>>s.m_pwd)
	{
		vStu.emplace_back(s);
	}
	cout << "当前学生数量为 " << vStu.size() <<endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.emplace_back(t);
	}
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}

void PrintStu(Student &s)
{
	cout << "学号： " << s.m_id << " 姓名： " << s.m_name << " 密码： " << s.m_pwd << endl;
}

void PrintTea(Teacher &t)
{
	cout << "职工号： " << t.m_empid << " 姓名： " << t.m_name << " 密码： " << t.m_pwd << endl;
}

void Manager::showPerson()
{
	cout << "请输入查看的类型" << endl;
	cout << "1、Student..." << endl;
	cout << "2、Teacher..." << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生的信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStu);
	}
	else
	{
		cout << "所有老师的信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTea);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号 " << it->m_comId << "，机房的容量 " << it->m_MaxNum << endl;
	}

	system("pause");
	system("cls");
}


void Manager::clearRecord()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空文件成功..." << endl;
	system("pause");
	system("cls");
}

