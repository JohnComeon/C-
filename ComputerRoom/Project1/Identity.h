#pragma once
#include<iostream>
#include <string>
using namespace std;

//��ݳ������
class Identity
{
public:
	//�����˵� ���麯��
	virtual void openMenu() = 0;
	string m_name;   //�û���
	string m_pwd;   //����
};

