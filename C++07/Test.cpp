#include<iostream>
using namespace std;

//class ob
//{
//public:
//	void func()
//	{
//		cout << "void func()" << endl;
//	}
//
//};
//typedef void(ob::*pobloc)();
//int main()
//{
//	pobloc p = &ob::func;
//	ob temp;
//	(temp.*p)();
//	
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year)
//		{
//			if (_month < d._month)
//			{
//				return true;
//			}
//			else if (_month == d._month)
//			{
//				if (_day < d._day)
//				{
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//
//	Date& operator = (const Date& d)
//	{
//		//这一段是允许你将一个日期对象赋值给另一个日期对象
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//
//	
//	void Print()
//	{
//		cout << _year <<"->" << _month <<"->"<< _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////Date& operator = (Date& left, const Date& right)
////{
////	if (&left != &right)
////	{
////		left._year = right._year;
////		//这个写法和成员函数那个赋值写法是一样的
////		//上面那一种的风格更好
////	}
////
////}
//int main()
//{
//	//Date d1;
//	//d1.Print();
//	Date d1(1995, 8, 19);
//	Date d2(1995, 8, 22);
//	//
//	//bool str1 = d1 < d2;
//	//cout << str1 << endl;
//	//d1 = d2;
//	//d1.Print();
//	bool ret1 = d1 < d2;
//	bool ret2 = d1.operator<(d2);
//	int j = 0;
//	int i = 1;
//	bool ret3 = j < i;
//	Date d3(d1);
//	d2 = d3;
//	int a = 0, b = 1;
//	(a = b) = 10;
//	cout << (a = b = 10) << endl;
//	//这是拷贝构造
//	d2.Print();
//	d3.Print();
//	cout << ret1 << endl;
//	cout << ret2 << endl;
//	cout << ret3 << endl;
//	return 0;
//}



#include"Date.h"

int main()
{
	Date d1(2014, 4, 16);
	Date d2 = d1 + 100;
	d2.Print();
	d1.Print();
}