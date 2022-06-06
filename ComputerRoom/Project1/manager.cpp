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
	//��ʼ��
	this->m_name = name;
	this->m_pwd = pwd;

	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs>>com.m_comId && ifs>>com.m_MaxNum)
	{
		vCom.emplace_back(com);
	}
	ifs.close();
	cout << "����������Ϊ " << vCom.size() << endl;
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
	cout << "����������˺ŵ�����" << endl;
	cout << "1��Add Student..." << endl;
	cout << "2��Add Teacher..." << endl;

	string fileName;   //�����ļ���
	string tip;      // ��ʾID��
	
	ofstream ofs;     //�ļ���������

	string errortip;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ� ";
		errortip = "ѧ���ظ�������������...";
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "������ְ���ţ� ";
		errortip = "ְ�����ظ�������������...";
	}

	ofs.open(fileName, ios::out | ios::app);  //׷�ӵķ�ʽд�ļ�
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
	
	cout << "������������ ";
	cin >> name;
	cout << "���������룺 ";
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�..." << endl;
	system("pause");
	system("cls");
	ofs.close();

	this->initVector();   //���µ��ó�ʼ������
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs>>s.m_id && ifs>>s.m_name && ifs>>s.m_pwd)
	{
		vStu.emplace_back(s);
	}
	cout << "��ǰѧ������Ϊ " << vStu.size() <<endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
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
	cout << "ѧ�ţ� " << s.m_id << " ������ " << s.m_name << " ���룺 " << s.m_pwd << endl;
}

void PrintTea(Teacher &t)
{
	cout << "ְ���ţ� " << t.m_empid << " ������ " << t.m_name << " ���룺 " << t.m_pwd << endl;
}

void Manager::showPerson()
{
	cout << "������鿴������" << endl;
	cout << "1��Student..." << endl;
	cout << "2��Teacher..." << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ������Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStu);
	}
	else
	{
		cout << "������ʦ����Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTea);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������� " << it->m_comId << "������������ " << it->m_MaxNum << endl;
	}

	system("pause");
	system("cls");
}


void Manager::clearRecord()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "����ļ��ɹ�..." << endl;
	system("pause");
	system("cls");
}

