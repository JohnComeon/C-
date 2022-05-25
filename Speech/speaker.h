/*
 * @Author: John
 * @Date: 2022-05-11 14:15:11
 * @LastEditors: John
 * @LastEditTime: 2022-05-11 14:19:17
 * @FilePath: \Speech\speaker.h
 * @Description: 
 */
#pragma once    //仅编译一次
#include <iostream>
using namespace std;

class Speaker{
public:
    string m_name;
    double m_score[2];  //分数
};
