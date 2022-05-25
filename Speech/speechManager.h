/*
 * @Author: John
 * @Date: 2022-05-11 10:39:23
 * @LastEditors: John
 * @LastEditTime: 2022-05-22 15:37:30
 * @FilePath: \Speech\speechManager.h
 * @Description: 
 */
#pragma once    //仅编译一次
#include <iostream>
#include<vector>
#include<map>
#include "speaker.h"
using namespace std;

// 演讲比赛管理类
class speechManager
{
public:
    speechManager();

    void showMenu();  //显示菜单

    void exitSystem();

    ~speechManager();

    void initspeech();

    vector<int> v1;  // 第一轮选手编号容器
    vector<int> v2;
    vector<int> vvictory;

    map<int, Speaker> m_speaker;  //存放编号及其对应具体选手的容器

    int index;
    

    void createSpeaker();

    //开始比赛  比赛整个流程控制函数
    void startSpeech();
     
    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    void showScore();

    void saveRecord();
    void loadRecord();
    bool isEmpty;  
    map<int, vector<string>> m_Record;   //往届记录，key代表第几届，value记录具体信息

    void showRecord();   //显示往届记录
    void clearRecord();
};

