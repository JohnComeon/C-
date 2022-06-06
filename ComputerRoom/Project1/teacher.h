#pragma once
#include<iostream>
#include <string>
using namespace std;
#include "Identity.h"
#include "orderFile.h"
#include <vector>

class Teacher :public Identity
{
public:
	Teacher();

	//有参构造
	Teacher(int empid, string name, string pwd);

	virtual void openMenu();

	void validOrder();   //审核预约

	void showAllOrder();

	int m_empid;    // 老师编号
};

