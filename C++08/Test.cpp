#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string word;
//	//cin >> word;
//	while (cin >> word)
//	{
//		cout << word << endl;
//		//这个就是一个死循环的输入法了
//		//但是如果在两个字母之间输入空格的话，会变成竖排形式
//	}
//	return 0;
//}



//int main()
//{
//	//string a(10, 'c');
//	//string a1("value");
//	//
//	//cout << a << endl;
//	//cout << a1 << endl;
//	
//	//string a2 = "zhang";//这属于拷贝初始化
//	//string a3{ "mu" };//直接初始化
//	//string a4(10, 'b');//这也是直接初始化
//
//
//	//string temp(11, 'b');
//	//string a = temp;
//	//cout << a << endl;
//	//return 0;
//
//
//
//	//string s1, s2;
//	//cin >> s1 >> s2;
//	//cout << s1 << s2 << endl;
//	//return 0;
//
//
//	string s1;
//	cin >> s1;
//	cout << s1 << endl;
//	return 0;
//	//输入hello world的话只能打印出hello，
//	//遇到空格就结束的性质
//
//
//}





int main()
{
	//string line;
	////cin >> line;
	//while (getline(cin, line))
	//{
	//	cout << line << endl;
	//}

	//return 0;


	string line;
	while (getline(cin, line))
	{
		if (!line.empty())
		{
			cout << line << endl;
		}
	}
	return 0;
}