
#include "teacher.h"
//默认构造
Teacher::Teacher()
{
}

Teacher::Teacher(int empid, string name, string pwd)
{
	//初始化
	this->m_empid = empid;
	this->m_name = name;
	this->m_pwd = pwd;

}


void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无记录..." << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < of.m_size; i++)
	{
		cout << "预约日期：" << of.m_orderData[i]["date"] << " ";
		cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "姓名：" << of.m_orderData[i]["stuName"];
		cout << "学号：" << of.m_orderData[i]["stuId"];
		cout << "机房：" << of.m_orderData[i]["roomId"];
		string status = "状态： ";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}


}

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无记录..." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下：" << endl;

	int index = 1;
	vector<int> v;  //存储 下标编号

	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.emplace_back(i);
			cout << index++ << ". ";
			cout << "预约日期：" << of.m_orderData[i]["date"] << " ";
			cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房：" << of.m_orderData[i]["roomId"];

			string status = "状态： ";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}

	}
	cout << "请输入取消的记录，0代表返回" << endl;
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
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
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
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
	return;
}



void Teacher::openMenu()
{
	cout << "Welcome Teacher " << this->m_name << endl;
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.查看所有预约       |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.审核预约           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.注销登录           |\n"; 
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "选择你的选项" << endl;
}