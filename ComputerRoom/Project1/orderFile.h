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

	map<int, map<string, string>> m_orderData;  //key为记录的条数，value为该条记录的信息
	int m_size;   //预约记录个数
};
