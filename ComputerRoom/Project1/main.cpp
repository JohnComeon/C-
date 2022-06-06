/*
 * @Author: John
 * @Date: 2022-05-25 16:31:47
 * @LastEditors: John
 * @LastEditTime: 2022-06-01 18:59:46
 * @FilePath: \Room\main.cpp
 * @Description:
 *
 * ���������ʹ�øó���
 * ѧ����������ʹ�û���
 * ��ʦ�����ѧ����ԤԼ����
 * ����Ա����ѧ������ʦ�����˺�
 *
 * ���������䣺1�Ż����������Ϊ20�ˣ�2�Ż����������Ϊ50�ˣ�3�Ż����������Ϊ100��
 *
 * �����飺
 * ����Ķ���ÿ���ɹ���Ա������գ�
 * ѧ������ԤԼδ��һ���ڵĻ���ʹ�ã�ԤԼ������Ϊ��һ�����壬ԤԼʱ��Ҫѡ��ԤԼʱ�Σ����硢���磩
 * ��ʦ����ʵ��������ԤԼͨ����ͨ��
 *
 * ÿ����ݶ���Ҫ��֤�󣬲��ܽ����Ӳ˵�
 *
 * ѧ�����幦�ܣ�
 *      ����ԤԼ
 *      �鿴����ԤԼ
 *      �鿴����ԤԼ
 *      ȡ��ԤԼ
 *      �˳���¼
 * ��ʦ���幦�ܣ�
 *      �鿴����ԤԼ
 *      ���ԤԼ
 *      �˳���¼
 * ����Ա���幦�ܣ�
 *      ����˺ţ����ѧ������ʦ���˺ţ���Ҫ���ѧ����Ż��ʦְ�����Ƿ��ظ�
 *      �鿴�˺ţ��鿴ѧ������ʦ��ȫ����Ϣ
 *      �鿴�������鿴���л�����Ϣ
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
			cout << "ע���ɹ�" << endl;
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
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



// ��¼����
void LoginIn(string filename, int type) // �ļ����ƣ� ��¼�������
{
	Identity *person = NULL;  //����ָ�룬ָ���������

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open()) //�ж��ļ��Ƿ����
	{
		cout << "Does not exist this file..." << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	if (type == 1) //ѧ��
	{
		cout << "Please print Id..." << endl;
		cin >> id;
	}

	else if (type == 2) //��ʦ
	{
		cout << "Please print EmpId..." << endl;
		cin >> id;
	}

	cout << "Please print name..." << endl;
	cin >> name;
	cout << "Please print pwd..." << endl;
	cin >> pwd;

	//��¼��֤
	if (type == 1) //ѧ��
	{
		int fId;      //�ļ��е�Id
		string fname; //�ļ��е�����
		string fpwd;  //�ļ��е�����

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

				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fId;      //�ļ��е�Id
		string fname; //�ļ��е�����
		string fpwd;  //�ļ��е�����

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

				//������ʦ��ݵ��Ӳ˵�
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
