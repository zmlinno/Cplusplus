#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"
#include<iostream>
using namespace std;

int main()
{
	Date d1;//默认构造函数
	Date d2(2023, 6, 25);//参数构造函数
	Date d3(d2);//拷贝构造函数

	
	cout << "d1: " << d1 << endl;
	return 0;
}