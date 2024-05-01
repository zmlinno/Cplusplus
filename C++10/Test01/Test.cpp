#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;
void String_Test01()
{
	string s1("hello world"); 
	cout << s1.size() <<endl;
	string::iterator st = s1.begin();

	while (st != s1.end())
	{
		cout << *st << " ";
		++st;
	}
	cout << endl;
}

// 在这里展示的反向迭代
void String_Test02()
{
	string s1("hello world");
	//string::iterator it = s1.begin();
	string::reverse_iterator it = s1.rbegin();

	//反向迭代中代码函数会发生改变
	while (it != s1.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string s2("hello world");
	string::iterator it1 = s2.begin();
	while (it1 != s2.end())
	{
		*it1 += 3;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

void String_Test03()
{
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;
}

void String_Test04()
{
	string s1("file.c.tar.cpp");
	//拿到文件后缀
	size_t posl = s1.rfind(',');
	//成员函数rfind是从字符串末尾开始向前查找字符的位置。
	//如果找到了返回该字符在字符串中的位置，
	//否则返回 string::npos，表示没有找到。
	if (posl != string::npos)
	{
		string suffix = s1.substr(posl);
		cout << suffix << endl;

	}
	else
	{
		cout << "没有后缀" << endl;
	}

	string url2("https://legacy.cplusplus.com/reference/string/string/substr/");
	string url1("http://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=1&tn=65081411_1_oem_dg&wd=%E5%90%8E%E7%BC%80%20%E8%8B%B1%E6%96%87&fenlei=256&rsv_pq=0xc17a6c03003ede72&rsv_t=7f6eqaxivkivsW9Zwc41K2mIRleeNXjmiMjOgoAC0UgwLzPyVm%2FtSOeppDv%2F&rqlang=en&rsv_dl=ib&rsv_enter=1&rsv_sug3=4&rsv_sug1=3&rsv_sug7=100&rsv_sug2=0&rsv_btype=i&inputT=1588&rsv_sug4=6786");

	string protocol, domain, uri;
	//定义了三个字符串变量
	//用于存储解析出的协议，域名和资源路径
	size_t i1 = url1.find(':');
	if (i1 != string::npos)
	{
		protocol = url1.substr(0, i1 - 0);
		cout << protocol << endl;
	}

	// strchar
	size_t i2 = url1.find('/', i1 + 3);
	if (i2 != string::npos)
	{
		domain = url1.substr(i1 + 3, i2 - (i1 + 3));
		cout << domain << endl;

		uri = url1.substr(i2 + 1);
		cout << uri << endl;
	}

	size_t i3 = url1.find("baidu");
	cout << i3 << endl;
	//打印出来的11表示在索引11处

	string str("Please, replace the vowels in this sentence by asterisks.");
	cout << str << endl;


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
}
int main()
{
	//String_Test01();
	//String_Test02();
	//String_Test03();
	String_Test04();
	return 0;
}