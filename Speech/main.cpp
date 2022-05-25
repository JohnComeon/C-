/*
 * @Author: John
 * @Date: 2022-05-10 21:01:42
 * @LastEditors: John
 * @LastEditTime: 2022-05-22 15:47:29
 * @FilePath: \Speech\main.cpp
 * @Description: 
 * 学校举办一场演讲比赛，共12个人参加，比赛共两轮，第一轮为淘汰赛，第二轮为决赛
 * 每个选手都有对应的编号：如10001~10012
 * 比赛方式：分组比赛，每组6人
 * 第一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲
 * 十个评委进行打分，去除最高分与最低分，求得平均法作为本选手的成绩
 * 当小组演讲后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮比赛
 * 第二轮为决赛，前三名胜出
 * 每轮比赛后需要显示胜出选手的信息
 * 
 * 程序功能：
 * 1、开始演讲比赛：完成整个比赛的流程，每个比赛阶段需要给用户一个提示，用户按下任意键后继续下一个阶段
 * 2、查看往届记录：查看之前比赛前三名的结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
 * 3、清空比赛记录：将文件中的数据清空
 * 4、退出比赛程序：退出当前程序
 */
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

#include "speechManager.h"
#include "speechManager.cpp"
using namespace std;
#include <ctime>

int main() {

    //随机数种子
    srand((unsigned int)time(NULL));
    speechManager sm;
    // for(map<int, Speaker>::iterator it=sm.m_speaker.begin(); it!=sm.m_speaker.end();it++)
    // {
    //     cout<< it->first<<endl;
    //     cout<<(*it).second.m_name<<" "<<it->second.m_score[0]<<endl;
    // } 
    
    int choice = 0;

    while (true)
    {
        // speechManager sm;
        sm.showMenu();

        cout<<"Choose "<<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            sm.startSpeech();
            break;
        case 2:
            sm.showRecord();
        case 3:
            sm.clearRecord();
            break;
        case 4:
            sm.exitSystem();
            break;    
        default:
            system("cls");  //清屏
            break;
        }
    }
    
    


    system("pause");
    return 0;
}

