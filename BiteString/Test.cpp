#define _CRT_SECURE_NO_WARNINGS 1
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

void test_string3()
{
	string s1("hello world");
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// 可读可写
	string::iterator it2 = s1.begin();
	while (it2 != s1.end())
	{
		*it2 += 3;

		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	// 只读
	const string s3("hello world");
	string::const_iterator it3 = s3.begin();
	while (it3 != s3.end())
	{
		// *it3 += 3;

		cout << *it3 << " ";
		++it3;
	}
	cout << endl;

	// const_reverse_iterator
}

// reserve // 保留
// reverse // 反转 翻转
void test_string4()
{
	string s1("hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	cout << s1.size() << endl;
	cout << s1.length() << endl;

	cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;

	// 查看扩容机制
	string s;
	s.reserve(100);

	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;


	s1.clear();
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;

	// 缩容
	s1.shrink_to_fit();
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
}


void test_string5()
{
	string s1("hello worldxxxxxx");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	// 比当前capacity大才会扩容
	s1.reserve(200);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

	string s2("hello worldxxxxxx");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.resize(10);

	cout << s2.size() << endl;
	cout << s2.capacity() << endl<<endl;

	s2.resize(20);

	cout << s2.size() << endl;
	cout << s2.capacity() << endl<<endl;

	s2.resize(100, 'x');

	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;
}

void test_string6()
{
	string s1("xhello world");
	cout << s1[5] << endl;
	cout << s1.at(5) << endl;

	try
	{
		//s1[15];
		//s1.at(15);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}

void test_string7()
{
	string s1("xhello world");
	s1.push_back('!');
	cout << s1 << endl;

	s1.append("hello bit");
	cout << s1 << endl;

	s1.append(10, 'x');
	cout << s1 << endl;

	string s2("  apple ");
	//s1.append(s2);
	//cout << s1 << endl;
	s1.append(++s2.begin(), --s2.end());
	cout << s1 << endl;

	string s3("hello world");
	s3 += ' ';
	s3 += "apple";
	cout << s3 << endl;
}

void test_string8()
{
	string s1("xhello world");
	cout << s1 << endl;

	s1.assign(" xxxxx");
	cout <<s1<< endl;

	s1.insert(0, "yyyy");
	cout << s1 << endl;

	s1.erase(5, 3);
	cout << s1 << endl;

	s1.erase();
	cout << s1 << endl;

	// 21：10继续
	string s2("hello world hello bit");
	/*s2.replace(5, 1, "20%");
	cout << s2 << endl;*/

	/*size_t pos = s2.find(' ');
	while (pos != string::npos)
	{
		s2.replace(pos, 1, "20%");
		pos = s2.find(' ');
	}
	cout << s2 << endl;*/

	// insert/erase/replace
	// 能少用就要少用，因为基本都要挪动数据，效率不高
	string s3;
	s3.reserve(s2.size());
	for (auto ch : s2)
	{
		if (ch != ' ')
		{
			s3 += ch;
		}
		else
		{
			s3 += "20%";
		}
	}
	cout << s3 << endl;
	s2.swap(s3);
	cout << s2 << endl;
}

void test_string9()
{
	string s1("hello world");

	string filename("test.cpp");
	FILE* fout = fopen(filename.c_str(), "r");
}

//[0, 9]
//[0, 10)
void test_string10()
{
	//string s1("file.cpp");
	string s1("file.c.tar.zip");

	// 拿到文件的后缀
	size_t pos1 = s1.rfind('.');
	if (pos1 != string::npos)
	{
		string suffix = s1.substr(pos1);
		//string suffix = s1.substr(pos1, s1.size()-pos1);

		cout << suffix << endl;
	}
	else
	{
		cout << "没有后缀" << endl;
	}

	string url2("https://legacy.cplusplus.com/reference/string/string/substr/");
	string url1("http://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=1&tn=65081411_1_oem_dg&wd=%E5%90%8E%E7%BC%80%20%E8%8B%B1%E6%96%87&fenlei=256&rsv_pq=0xc17a6c03003ede72&rsv_t=7f6eqaxivkivsW9Zwc41K2mIRleeNXjmiMjOgoAC0UgwLzPyVm%2FtSOeppDv%2F&rqlang=en&rsv_dl=ib&rsv_enter=1&rsv_sug3=4&rsv_sug1=3&rsv_sug7=100&rsv_sug2=0&rsv_btype=i&inputT=1588&rsv_sug4=6786");

	string protocol, domain, uri;
	size_t i1 = url1.find(':');
	if (i1 != string::npos)
	{
		protocol = url1.substr(0, i1 - 0);
		cout << protocol << endl;
	}

	// strchar
	size_t i2 = url1.find('/', i1+3);
	if (i2 != string::npos)
	{
		domain = url1.substr(i1+3, i2-(i1+3));
		cout << domain << endl;

		uri = url1.substr(i2 + 1);
		cout << uri << endl;
	}

	// strstr  10:40继续
	size_t i3 = url1.find("baidu");
	cout << i3 << endl;

	std::string str("Please, replace the vowels in this sentence by asterisks.");
	cout << str << endl;

	// strtok
	std::size_t found = str.find_first_not_of("aeiou");
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_not_of("aeiou", found + 1);
	}
	cout << str << endl;

	cout << (url1 < url2) << endl;

	string ss1 = "xxx";
	string ss2 = "yyy";

	string ret = ss1 + ss2;
	cout << ret << endl;

	string ret1 = ss1 + "yyyy";
	string ret2 = "yyyy" + ss2;
}

// 字符数组
struct Person
{
private:
	int _age;

	string _address;
	//char _address[1024];
	//char _tel[36];
	//char _name[36];
};

//int main()
//{
//	test_string10();
//
//	return 0;
//}

#include <iostream>
using namespace std;

//int main()
//{
//	string str;
//	//cin >> str;
//	char ch;
//	ch = getchar();
//	while (ch != '\n')
//	{
//		str += ch;
//		ch = getchar();
//	}
//
//	size_t pos = str.rfind(' ');
//	cout << str.size() - (pos + 1) << endl;
//}

//int main()
//{
//	char ch1;
//	wchar_t ch2;
//	char16_t ch3;
//	char32_t ch4;
//
//	cout << sizeof(ch1) << endl;
//	cout << sizeof(ch2) << endl;
//	cout << sizeof(ch3) << endl;
//	cout << sizeof(ch4) << endl;
//
//	// 编码   文字计算机的存储和表示
//	// ascll
//
//	char c1 = 'a';
//	cout << c1 << endl;
//
//	char c2 = 98;
//	cout << c2 << endl;
//
//	return 0;
//}

//int main()
//{
//	// 净网行动
//	char buff[] = "吃饭";
//	cout << sizeof(buff) << endl;
//	buff[3]--;
//	buff[3]--;
//
//	buff[1]--;
//	buff[1]--;
//
//	char buff1[128];
//	cout << buff1 << endl;
//
//	// gbk
//
//	return 0;
//}

#include"string.h"

int main()
{
	/*int i = 1234;
	double d = 11.22;
	string s1 = to_string(i);
	string s2 = to_string(d);

	string s3("45.55");
	double d3 = stod(s3);*/

	bit::test_string5();

	return 0;
}