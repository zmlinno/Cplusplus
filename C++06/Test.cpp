#include<iostream>
using namespace std;

//class Time
//{
//public:
//	//û��Ĭ�Ϲ��캯��
//	Time(int hour)
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//private:
//	//���ǻ������ͣ���������
//	int _year;
//	int _month;
//	int _day;
//
//	//�������Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	return 0;
//}



//class Date
//{
//public:
//	Date(int year = 1)
//	{
//		_year = year;
//	}
//	~Date()
//	{
//		cout << "Date->()" << _year << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void func()
//{
//	Date d5(222);
//}
//Date d6(77);
//static Date d7(88);
////�ֲ�����(����������) -�� �ֲ���̬ -��ȫ�ֶ���(����������)
//int main()
//{
//	Date d3(1);
//	Date d4(12);
//	func();
//	return 0;
//}


//
//class Date
//{
//public:
//	Date(int year = 1)
//	{
//		_year = year;
//	}
//	~Date()
//	{
//		cout << "date->" << _year << endl;
//	}
//private:
//	int _year;
//};
//
//
//int main()
//{
//	Date d1(22);
//
//	return 0;
//}


class Time
{
public:
	~Time()
	{
		cout << "Time()" << endl;
	}
	Time() = default;
	Time(const Time& t)
	{
		cout << "Time(const Time& t)" << endl;
		_time = t._time;
		_minute = t._minute;
		_second = t._second;
	}
private:
	int _time;
	int _minute;
	int _second;
};


int main()
{
	Time();
	return 0;
}