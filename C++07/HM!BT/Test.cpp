#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"
#include<iostream>
using namespace std;

int main()
{
	Date d1;//Ĭ�Ϲ��캯��
	Date d2(2023, 6, 25);//�������캯��
	Date d3(d2);//�������캯��

	
	cout << "d1: " << d1 << endl;
	return 0;
}