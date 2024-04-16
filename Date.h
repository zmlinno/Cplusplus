#pragma once
#include<iostream>
#include<assert.h>
using namespace std;


class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);
	
		
		bool operator<(const Date & d);
		bool operator<=(const Date & d);
		bool operator>(const Date & d);
		bool operator>=(const Date & d);
		bool operator==(const Date & d);
		bool operator!=(const Date & d);

		// d1 + 100
		Date& operator+=(int day);
		Date operator+(int day);
		// d1 - 100
		Date operator-(int day);
		Date& operator-=(int day);
	
	int GetMontDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return monthDay[month];
	}
	void Print()
	{
		cout << _year << "->" << _month << "->" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
