#include<iostream>
#include<string>

#include<vector>
#include<algorithm>
using namespace std;

void print(int val)
{
	cout << val << endl;
}

void test()
{
	vector<int> v;   //������һ��vector����������
	v.emplace_back(10);  //β����������
	v.emplace_back(20);
	v.emplace_back(30);

	//ͨ�����������������е�����
	//vector<int>::iterator itBegin = v.begin();  //��ʼ��������ָ�������еĵ�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end();  //������������ָ�������е����һ��Ԫ�ص���һ��λ��

	////��һ�ֱ�����ʽ
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//�ڶ��ֱ�����ʽ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;    //ȡֵ����ӡ���
	}

	//�����ֱ�����ʽ������STL���ṩ�ı����㷨
	for_each(v.begin(), v.end(), print);

}

int main()
{

	test();
	system("pause");
	return 0;
}