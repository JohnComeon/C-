
#include "teacher.h"
//Ĭ�Ϲ���
Teacher::Teacher()
{
}

Teacher::Teacher(int empid, string name, string pwd)
{
	//��ʼ��
	this->m_empid = empid;
	this->m_name = name;
	this->m_pwd = pwd;

}


void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "�޼�¼..." << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < of.m_size; i++)
	{
		cout << "ԤԼ���ڣ�" << of.m_orderData[i]["date"] << " ";
		cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "������" << of.m_orderData[i]["stuName"];
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << "������" << of.m_orderData[i]["roomId"];
		string status = "״̬�� ";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}


}

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "�޼�¼..." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼���£�" << endl;

	int index = 1;
	vector<int> v;  //�洢 �±���

	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.emplace_back(i);
			cout << index++ << ". ";
			cout << "ԤԼ���ڣ�" << of.m_orderData[i]["date"] << " ";
			cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "������" << of.m_orderData[i]["roomId"];

			string status = "״̬�� ";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}

	}
	cout << "������ȡ���ļ�¼��0��������" << endl;
	int select = 0;
	int res = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> res;
				if (res == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				
				of.updateOrder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
	return;
}



void Teacher::openMenu()
{
	cout << "Welcome Teacher " << this->m_name << endl;
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.�鿴����ԤԼ       |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.���ԤԼ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.ע����¼           |\n"; 
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "ѡ�����ѡ��" << endl;
}