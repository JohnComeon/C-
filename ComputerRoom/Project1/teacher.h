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

	//�вι���
	Teacher(int empid, string name, string pwd);

	virtual void openMenu();

	void validOrder();   //���ԤԼ

	void showAllOrder();

	int m_empid;    // ��ʦ���
};

