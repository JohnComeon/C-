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
	vector<int> v;   //创建了一个vector容器，数组
	v.emplace_back(10);  //尾部插入数据
	v.emplace_back(20);
	v.emplace_back(30);

	//通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();  //起始迭代器，指向容器中的第一个元素
	//vector<int>::iterator itEnd = v.end();  //结束迭代器，指向容器中的最后一个元素的下一个位置

	////第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;    //取值，打印输出
	}

	//第三种遍历方式，利用STL中提供的遍历算法
	for_each(v.begin(), v.end(), print);

}

int main()
{

	test();
	system("pause");
	return 0;
}