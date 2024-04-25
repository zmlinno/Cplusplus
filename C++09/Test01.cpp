#include<iostream>
using namespace std;

#include<string>
#include<vector>
#include<list>

//int main()
//{
//	int x = 0, y = 1;
//	swap(x, y);
//
//	double m = 1.1, n = 2.2;
//	swap(m, n);
//
//	return 0;
//}

// 模板+函数
// 模板+类

//template<class T>
//class Stack
//{
//public:
//	void push(const T& x)
//	{
//		//...
//	}
//
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//};


//typedef int STDataType;
//typedef double STDataType;
//
//class Stackint
//{
//public:
//	void push(const STDataType& x)
//	{
//		//...
//	}
//
//private:
//	STDataType* _a;
//	int _top;
//	int _capacity;
//};
//
//class Stackdouble
//{
//public:
//	void push(const STDataType& x)
//	{
//		//...
//	}
//
//private:
//	STDataType* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack s1; // int
//	Stack s2; // double
//
//	return 0;
//}

//template<class T>
//class Stack
//{
//public:
//	void push(const T& x);
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//};
//
//template<class T>
//void Stack<T>::push(const T& x)
//{
//	//...
//}
//
//
//int main()
//{
//	// 同一个类模板实例化出的两个类型
//	Stack<int> s1;
//	Stack<double> s2;
//
//	return 0;
//}

void test_string1()
{
	// 21:16
	string s0;
	string s1("hello world");
	string s2(s1);
	string s3(s1, 5, 3);
	string s4(s1, 5, 10);
	string s5(s1, 5);

	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	string s6(10, '#');
	cout << s6 << endl;

	s0 = s6;
	cout << s0 << endl;
}

//class string
//{
//public:
//	char& operator[](size_t pos)
//	{
//		return _str[pos];
//	}
//
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};

// int a[10]
// a[i] 等价于 *(a+i)
void test_string2()
{
	string s1("hello world");

	// 下标+[]
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
		//cout << s1.operator[](i) << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	string s3("hello world");
	s3[0]++;
	cout << s3 << endl;

	const string s2("hello world");
	//s2[0]++;
	cout << s2 << endl;

	cout << s3.size() << endl;
	cout << s3.capacity() << endl;

	string::iterator it3 = s3.begin();
	while (it3 != s3.end())
	{
		*it3 -= 3;
		++it3;
	}
	cout << endl;

	it3 = s3.begin();
	while (it3 != s3.end())
	{
		cout << *it3 << " ";
		++it3;
	}
	cout << endl;

	//cout << typeid(it3).name() << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator itt = lt.begin();
	while (itt != lt.end())
	{
		cout << *itt << " ";
		++itt;
	}
	cout << endl;

	// 底层就是迭代器
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test_string2();

	return 0;
}