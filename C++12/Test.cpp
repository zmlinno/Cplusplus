#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

void test_vector1()
{
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);*/

	vector<int> v(10, 1);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector2()
{
	size_t sz;
	vector<int> v;
	v.reserve(100);
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity:" << sz << '\n';
		}
	}
	
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	cout << "---------" << endl;

	v.shrink_to_fit();
	//Õâ¸öº¯Êý£¿
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	vector<int>a;
	a.resize(10, 1);
	for (auto e : a)
	{
		cout << e << endl;
	}
}


void test_vector3()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	for (auto e : v)
	{
		cout << e << endl;
	}
	cout << endl;

	auto pos = find(v.begin(), v.end(), 2);
	{
		if (pos != v.end())
		{
			v.insert(pos, 30);
			for (auto e : v)
			{
				cout << e << " ";
			}
			cout << endl;
			
		}


		v.insert(v.begin(), 0);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		
	}

}
int main()
{
	//test_vector1();
	//test_vector2();
	test_vector3();
	return 0;
}