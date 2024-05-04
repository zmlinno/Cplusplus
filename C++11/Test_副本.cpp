#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

//int main()
//{
//	string str;
//	cin >> str;
//	char ch;
//	ch = getchar();
//	//使用 getchar 函数从标准输入流中获取一个字符，并将其赋值给变量 ch
//	while (ch != '\0')
//	{
//		str += ch;
//		ch = getchar();
//	}
//	size_t pos = str.rfind(' ');
//	cout << str.size() - (pos + 1) << endl;
//
//}





int main()
{
	char ch1;
	wchar_t ch2;
	char16_t ch3;
	char32_t ch4;
	cout << sizeof(ch1) << endl;
	cout << sizeof(ch2) << endl;
	cout << sizeof(ch3) << endl;
	cout << sizeof(ch4) << endl;

	char c1 = 'a';
	cout << c1 << endl;
	

}