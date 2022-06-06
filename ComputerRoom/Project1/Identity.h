#pragma once
#include<iostream>
#include <string>
using namespace std;

//身份抽象基类
class Identity
{
public:
	//操作菜单 纯虚函数
	virtual void openMenu() = 0;
	string m_name;   //用户名
	string m_pwd;   //密码
};

