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

	//�вι���
	Student(int id, string name, string pwd);

	virtual void openMenu();

	void applyOrder(); //����ԤԼ

	void showMyOrder();

	void showAllOrder();

	void cancelOrder(); //ȡ��ԤԼ

	int m_id; // ѧ��ѧ��

	vector<ComputerRoom> vCom;
};
