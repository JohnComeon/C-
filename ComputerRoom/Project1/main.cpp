/*
 * @Author: John
 * @Date: 2022-05-25 16:31:47
 * @LastEditors: John
 * @LastEditTime: 2022-06-01 18:59:46
 * @FilePath: \Room\main.cpp
 * @Description:
 *
 * 有三种身份使用该程序：
 * 学生代表：申请使用机房
 * 教师：审核学生的预约申请
 * 管理员：给学生、教师创建账号
 *
 * 机房有三间：1号机房最大容量为20人，2号机房最大容量为50人，3号机房最大容量为100人
 *
 * 申请简介：
 * 申请的订单每周由管理员负责清空；
 * 学生可以预约未来一周内的机房使用，预约的日期为周一至周五，预约时需要选择预约时段（上午、下午）
 * 教师依据实际情况审核预约通过或不通过
 *
 * 每个身份都需要验证后，才能进入子菜单
 *
 * 学生具体功能：
 *      申请预约
 *      查看自身预约
 *      查看所有预约
 *      取消预约
 *      退出登录
 * 老师具体功能：
 *      查看所有预约
 *      审核预约
 *      退出登录
 * 管理员具体功能：
 *      添加账号：添加学生或老师的账号，需要检测学生编号或教师职工号是否重复
 *      查看账号：查看学生或老师的全部信息
 *      查看机房：查看所有机房信息
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Identity.h"
#include <fstream>
#include "globalFile.h"

#include "student.h"
#include "teacher.h"
#include "manager.h"

void studentMenu(Identity * &student)
{
	while (true)
	{
		student->openMenu();
		Student *stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
		}
	}
}


void teacherMenu(Identity * &teacher)
{
	while (true)
	{
		teacher->openMenu();
		Teacher *tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMenu(Identity * &manager)
{
	while (true)
	{
		/* code */
		manager->openMenu();
		Manager * man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "Add a person ..." << endl;
			man->addPerson();

		}
		else if (select == 2)
		{
			cout << "Show person" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{

			man->showComputer();
		}
		else {

			system("cls");
		}
	}
}



// 登录功能
void LoginIn(string filename, int type) // 文件名称， 登录身份类型
{
	Identity *person = NULL;  //父类指针，指向子类对象

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open()) //判断文件是否存在
	{
		cout << "Does not exist this file..." << endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1) //学生
	{
		cout << "Please print Id..." << endl;
		cin >> id;
	}

	else if (type == 2) //老师
	{
		cout << "Please print EmpId..." << endl;
		cin >> id;
	}

	cout << "Please print name..." << endl;
	cin >> name;
	cout << "Please print pwd..." << endl;
	cin >> pwd;

	//登录验证
	if (type == 1) //学生
	{
		int fId;      //文件中的Id
		string fname; //文件中的姓名
		string fpwd;  //文件中的密码

		while (ifs >> fId && ifs >> fname && ifs >> fpwd)
		{
			cout << fId << endl;
			cout << fname << endl;
			cout << fpwd << endl;
			if (fId == id && fname == name && fpwd == pwd)
			{
				cout << "Success ..." << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fId;      //文件中的Id
		string fname; //文件中的姓名
		string fpwd;  //文件中的密码

		while (ifs >> fId && ifs >> fname && ifs >> fpwd)
		{
			cout << fId << endl;
			cout << fname << endl;
			cout << fpwd << endl;
			if (fId == id && fname == name && fpwd == pwd)
			{
				cout << "Success ..." << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入老师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "Admin login Success..." << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "FAIL ..." << endl;
	system("pause");
	system("cls");
}

int main()
{
	int choice = 0;

	while (true)
	{
		cout << "==========================================="
			<< endl;
		cout << endl
			<< "Please " << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.Student           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.Teacher           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.Manager           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.Exit...          |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "Please input your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "bye..." << endl;
			system("pause");
			return 0;
			break;

		default:

			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
