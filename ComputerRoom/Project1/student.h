#pragma once
/*
 * @Author: John
 * @Date: 2022-05-26 14:28:41
 * @LastEditors: John
 * @LastEditTime: 2022-05-26 22:47:15
 * @FilePath: \Room\student.h
 * @Description:
 */
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Identity.h"
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "orderFile.h"

class Student : public Identity
{
public:
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	virtual void openMenu();

	void applyOrder(); //申请预约

	void showMyOrder();

	void showAllOrder();

	void cancelOrder(); //取消预约

	int m_id; // 学生学号

	vector<ComputerRoom> vCom;
};
