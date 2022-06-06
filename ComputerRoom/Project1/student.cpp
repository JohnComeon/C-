/*
 * @Author: John
 * @Date: 2022-05-26 14:28:46
 * @LastEditors: John
 * @LastEditTime: 2022-05-26 22:52:56
 * @FilePath: \Room\student.cpp
 * @Description:
 */

#include "student.h"


Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	//��ʼ������
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comId && ifs >> com.m_MaxNum)
	{
		vCom.emplace_back(com);
	}
	ifs.close();

}

void Student::openMenu()
{
	cout << "Welcome Students "<<this->m_name << endl;
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.����ԤԼ          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�鿴����ԤԼ       |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          4.ȡ��ԤԼ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.ע����¼          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "ѡ�����ѡ��" << endl;
}



void Student::applyOrder()
{
	cout << "������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)  //��������һֱ���ظ�����
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�������" << endl;
	}
	cout << "����������ԤԼʱ���..." << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}

	}

	cout << "��ѡ�����" << endl;
	cout << "1�Ż��������� " << vCom[0].m_MaxNum << endl;
	cout << "2�Ż��������� " << vCom[1].m_MaxNum << endl;
	cout << "3�Ż��������� " << vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "�������" << endl;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";  //ʱ���
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "RoomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");
}


void Student::showMyOrder()
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
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_id)   //stringת��Ϊint����бȽ�
		{
			cout << "ԤԼ���ڣ�" << of.m_orderData[i]["date"]<<" ";
			cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
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

	system("pause");
	system("cls"); 
}


void Student::showAllOrder()
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

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "�޼�¼..." << endl;
		system("pause");
		system("cls");
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	int index = 1;
	vector<int> v;  //�洢 �±���

	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_id)   //stringת��Ϊint����бȽ�
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
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
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}

		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
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
				of.m_orderData[v[select-1]]["status"]="0";
				of.updateOrder();
				cout << "�Ѿ�ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "�������" << endl;
	}

}
