// #include<iostream>
// #include<algorithm>
// using namespace std;

// #include<vector>

// void test_vector1()
// {
//     vector<int> v(10,1);
//     for(size_t i = 0;i<v.size();i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;


//     vector<int>::iterator it = v.begin();
//     while(it != v.end())
//     {
//         cout << *it << " ";
//         ++it;
//     }
//     cout << endl;


//     for(auto e: v)
//     {
//         cout << e << " ";
//     }
//     cout << endl;

    

// }



// void test_vector2()
// {
//     size_t sz;
//     vector<int> v;
//     v.reserve(100);
//     sz = v.capacity();
//     cout << "making v grow:\n";
//     for(int i = 0; i<100; i++)
//     {
//         v.push_back(i);
//         if(sz != v.capacity())
//         {
//             sz = v.capacity();
//             cout << "capacity changed:" << sz << endl;
//         }
//     }
//     cout << v.size() << endl;
//     cout << v.capacity() << endl;
//     v.reserve(10);
//     cout << v.size() << endl;
//     cout << v.capacity() << endl;

//     cout << "---------" << endl;

//     cout << v.size() << endl;
//     cout << v.capacity() << endl;
//     v.resize(10);
//     cout << v.size() << endl;
//     cout << v.capacity() << endl;

//     v.reserve(200);
//     cout << v.capacity() << endl;

//     v.shrink_to_fit();
//     cout << v.size() << endl;
//     cout << v.capacity() << endl;
// }


// void test_vector3()
// {
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     v.push_back(4);

//     for(auto e : v)
//     {
//         cout << e << " ";
//     }
//     cout << endl;

//     auto pos = find(v.begin(),v.end(),3);
//     if(pos != v.end())
//     {
//         v.insert(pos,30);
//     }

//     //头插
//     v.insert(v.begin(),0);
//     for(auto e : v)
//     {
//         cout << e <<" "; 
//     }
//     cout << endl;

//     v.insert(v.begin()+2,0);
//     for(auto e : v)
//     {
//         cout << e << " ";
//     }
//     cout << endl;

//     string s("abcd");
//     v.insert(v.begin(),s.begin(),s.end());
//     for(auto e : v)
//     {
//         cout << e << " ";
//     }
//     cout << endl;
// }


// void test_vector4()
// {
//     //对象数组
//     vector<string> v;
//     string s1("苹果");
//     v.push_back(s1);
//     v.push_back(string("草莓"));
//     v.push_back("香蕉");

//     vector<vector<int>> vv;
// }

// #include "vector.h"
// int main()
// {
//     //test_vector1();
//     //test_vector2();
//     //test_vector3();
//     //test_vector4();
//     bit::test_vector3();
//     return 0;
// }





#include<iostream>
#include<algorithm>
using namespace std;

#include<vector>

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
		cout << *it << " ";
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
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	cout << "--------------" << endl;

	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.shrink_to_fit();
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	vector<int> a;
	a.resize(10, 1);
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		v.insert(pos, 30);
	}

	// 头插
	v.insert(v.begin(), 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin()+2, 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	string s("abcd");
	v.insert(v.begin(), s.begin(), s.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector()
{
	// 对象数组
	vector<string> v;
	string s1("苹果");
	v.push_back(s1);
	v.push_back(string("香蕉"));
	v.push_back("草莓");

	vector<vector<int>> vv;
}

#include"vector.h"

int main()
{
	//test_vector1();
	//test_vector3();

	//bit::test_vector3();
    //bit::test_vector1();
    bit::test_vector2();

	return 0;
}