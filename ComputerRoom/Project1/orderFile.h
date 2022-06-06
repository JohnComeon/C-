#pragma once
#include <iostream>
using namespace std;

#include "globalFile.h"
#include <fstream>
#include <string>
#include <map>

class OrderFile
{
public:
	OrderFile();
	void updateOrder();

	map<int, map<string, string>> m_orderData;  //keyΪ��¼��������valueΪ������¼����Ϣ
	int m_size;   //ԤԼ��¼����
};
