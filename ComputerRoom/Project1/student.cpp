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
	//初始化属性
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化机房信息
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
	cout << "\t\t|          1.申请预约          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.查看我的预约        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.查看所有预约       |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          4.取消预约           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.注销登录          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "选择你的选项" << endl;
}



void Student::applyOrder()
{
	cout << "请输入预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)  //输入错误就一直让重复输入
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入错误" << endl;
	}
	cout << "请输入申请预约时间段..." << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}

	}

	cout << "请选择机房" << endl;
	cout << "1号机房容量： " << vCom[0].m_MaxNum << endl;
	cout << "2号机房容量： " << vCom[1].m_MaxNum << endl;
	cout << "3号机房容量： " << vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入错误" << endl;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";  //时间段
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
		cout << "无记录..." << endl;
		system("pause");
		system("cls");
	}
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_id)   //string转换为int后进行比较
		{
			cout << "预约日期：" << of.m_orderData[i]["date"]<<" ";
			cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
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

	system("pause");
	system("cls"); 
}


void Student::showAllOrder()
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

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无记录..." << endl;
		system("pause");
		system("cls");
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	int index = 1;
	vector<int> v;  //存储 下标编号

	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_id)   //string转换为int后进行比较
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
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
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}

		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
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
				cout << "已经取消预约" << endl;
				break;
			}
		}
		cout << "输入错误" << endl;
	}

}
