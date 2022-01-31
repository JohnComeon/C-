#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Person
{
public:
	Person(string n, int a)
	{
		this->name = n;
		this->age = a;
	}
	string name;
	int age;
};

void print(Person p)
{
	cout << p.name<<p.age << endl;
}

void test()
{
	vector<Person> v;
	Person p1("aaa", 20);
	Person p2("abb", 21);
	Person p3("vvv", 23);
	v.emplace_back(p1);
	v.emplace_back(p2);
	v.emplace_back(p3);

	for_each(v.begin(), v.end(), print);

}



int main()
{
	test();
	system("pause");

	return 0;
}