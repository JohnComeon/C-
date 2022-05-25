/*
 * @Author: John
 * @Date: 2022-05-11 10:39:37
 * @LastEditors: John
 * @LastEditTime: 2022-05-22 15:50:45
 * @FilePath: \Speech\speechManager.cpp
 * @Description: 
 */
#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <string>
#include <fstream>

using namespace std;

speechManager::speechManager()
{
    initspeech();   // 初始化容器和属性

    createSpeaker();

    loadRecord();  //加载往届记录

}

speechManager::~speechManager()
{

}

void speechManager::showMenu()
{
    cout<<"*******************************************"<<endl;
    cout<<"******Welcome to the Speech Competition****"<<endl;
    cout<<"*****************1. Start*****************"<<endl;
    cout<<"***********2. View past records***********"<<endl;
    cout<<"*****************3. Clear()***************"<<endl;
    cout<<"*****************4. Exit()****************"<<endl;
    cout<<endl;
}

void speechManager::exitSystem()
{
    cout<<"bye.."<<endl;
    system("pause");
    exit(0);
}

void speechManager::initspeech()
{
    v1.clear();
    v2.clear();
    vvictory.clear();
    m_speaker.clear();
    index = 1;

    m_Record.clear();  //初始化记录容器
}

void speechManager::createSpeaker()
{
    string seed = "ABCDEFGHIJKL";
    
    for (int i=0;i<seed.size(); i++)
    {
        string name = "Speaker";
        name += seed[i];
        Speaker s;
        s.m_name = name;
        // Speaker s;
        // s.m_name = "Speaker" + seed[i];

        for(int j=0; j<2; j++)
        {
            s.m_score[j] = 0;
        }
        
        v1.emplace_back(i+10001);   // 创建选手编号，并加入到容器中
        m_speaker.insert(make_pair(i+10001, s));
    }
}

void speechManager::speechDraw()
{
    cout<<"The "<<index<<" round"<<endl;
    cout<<"................."<<endl;
    
    if(index==1)
    {
        random_shuffle(v1.begin(), v1.end());
        for(auto it=v1.begin(); it!=v1.end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for(auto it=v2.begin(); it!=v2.end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<"................."<<endl;
    system("pause");
}

void speechManager::startSpeech()
{
    //第一轮比赛
    //抽签
    speechDraw();
    //比赛
    speechContest();
    //显示晋级结果
    showScore();
    
    index++;    
    //第二轮比赛
    //抽签
    speechDraw();
    //比赛
    speechContest();
    //显示晋级结果
    showScore();
    // 保存文件
    saveRecord();

    //重置比赛
    initspeech();
    createSpeaker();
    loadRecord();

    cout<<endl;
}

void speechManager::speechContest()
{
    cout<<"The round "<<index<<" contest starts..."<<endl;
    //临时容器，存放小组成绩
    multimap<double, int, greater<double>> groupScore;
    int num = 0;

    vector<int> v_src;   //选手容器
    if(index==1)
    {
        v_src = v1;
    }
    else
    {
        v_src = v2;
    }

    for(auto it=v_src.begin(); it!=v_src.end(); it++)
    {
        //评委打分
        deque<double> d;
        for(int i=0; i<10; i++)
        {
            double s = (rand()%401+600)/10.f;    // 600~1000
            // cout<<s<<" ";
            d.push_back(s);
        }
        sort(d.begin(), d.end(), greater<double>());
        //去除最高分与最低分
        d.pop_front();
        d.pop_back();
        double sum = accumulate(d.begin(), d.end(),0);
        double avg = sum/(double)d.size();

        //打印平均分
        // cout<<"ID is "<<*it<<" Name is "<<m_speaker[*it].m_name<<", Score is "<<
        // avg<<endl;
        //将平均分放入到map容器中
        m_speaker[*it].m_score[index-1] = avg;

        groupScore.insert(make_pair(avg, *it));  //key是分数，value是具体选手的编号
        num ++;
        if(num%6==0)    
        {
            cout<<"The rank of Group "<<num/6<<endl;
            for(auto it=groupScore.begin(); it!=groupScore.end();it++)
            {
                cout<<"ID is "<<it->second<<", Name is "<<m_speaker[it->second].m_name<<
                ", Score is "<<m_speaker[it->second].m_score[0]<<endl;
            }

            int count = 0;
            for(auto it=groupScore.begin(); it!=groupScore.end(),count<3;it++,count++)
            {   
                if(index==1)
                {
                    v2.emplace_back((*it).second);
                }
                else
                {
                    vvictory.emplace_back((*it).second);
                }
            }
                
            groupScore.clear();
        }
        
    }
    cout<<"----------------"<<endl;
    system("pause");
}

void speechManager::showScore()
{
    cout<<"----------------The "<<index <<" winner info-----------"<<endl;
    vector<int> vs;
    if(index==1)
    {
        vs = v2;
    }
    else{
        vs = vvictory;
    }
    for(auto it=vs.begin(); it!=vs.end();it++)
    {
        cout<<"ID is "<<*it<<", Name is "<<m_speaker[*it].m_name<<", Score is "<<
         m_speaker[*it].m_score[0]<<endl;        
    }
    cout<<endl;
    system("pause");
}


void speechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);
    for(auto it=vvictory.begin(); it!=vvictory.end(); it++)
    {
        ofs<<*it<<","<<m_speaker[*it].m_score[1]<<",";
    }
    ofs<<endl;  //换行
    ofs.close();
    cout<<"Finish Saving..."<<endl;
    isEmpty = false;   //更新状态
}


void speechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in);  //读取文件
    if(!ifs.is_open())
    {
        isEmpty = true;
        cout<<"No file..."<<endl;
        ifs.close();
        return;
    }

    //文件清空的情况
    char ch;
    ifs>>ch ;
    if(ifs.eof())
    {
        cout<<"File is empty..."<<endl;
        isEmpty = true;
        ifs.close();
        return;
    }

    //文件不为空时
    isEmpty = false;
    ifs.putback(ch);     //将上面读取的单个字符 放回来
    string data;
    int Number = 1;
    while (ifs>>data)
    {
        // cout<<data<<endl;
        int pos = -1;
        int start = 0;
        vector<string> vs;
        while (true)
        {
            
            pos = data.find(",", start);
            if (pos==-1)
            {
                break;
            }
            string tmp = data.substr(start, pos-start);
            
            // cout<<tmp<<endl;

            vs.emplace_back(tmp);
            start = pos+1;
        }
        
        m_Record.insert(make_pair(Number, vs));
        // cout<<m_Record[0][0]<<endl;
        Number ++;
    }
    ifs.close();    
    for(auto it = m_Record.begin(); it!=m_Record.end();it++)
    {
        cout<<it->first<<" ID is "<<it->second[0]<<",score is " <<it->second[1]<<endl;
        
    }
}

void speechManager::showRecord()
{
    if (isEmpty)
    {
        cout<<"File is empty..."<<endl;
    }

    for(auto it = m_Record.begin(); it!=m_Record.end();it++)
    {
        cout<<"The Number "<<it->first +1
        <<"Winner 1st is "<<it->second[0]<<" score is "<<it->second[1]<<" "
        <<"Winner 2rd is "<<it->second[2]<<" score is "<<it->second[3]<<" "
        <<"Winner 3th is "<<it->second[4]<<" score is "<<it->second[5]<<" "<<endl;
    }
    system("pause");
    system("cls");
}

void speechManager::clearRecord()
{
    cout<<"Clear??"<<endl;
    cout<<"1: Yes"<<endl;
    cout<<"2: No"<<endl;
    
    int flag = 0;
    cin>>flag;
    if (flag==1)
    {
        ofstream ofs("speech.csv", ios::trunc); 
        //打开模式 ios::trunc 若文件存在，则先删除再重新创建
        ofs.close();

        initspeech();
        createSpeaker();
        loadRecord();

        cout<<"Clear finished.."<<endl;
    }
    system("pause");
    system("cls");

}   
