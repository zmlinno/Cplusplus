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


//class Time
//{
//public:
//	~Time()
//	{
//		cout << "Time()" << endl;
//	}
//	Time() = default;
//	Time(const Time& t)
//	{
//		cout << "Time(const Time& t)" << endl;
//		_time = t._time;
//		_minute = t._minute;
//		_second = t._second;
//	}
//private:
//	int _time;
//	int _minute;
//	int _second;
//};
//
//
//int main()
//{
//	Time();
//	Time t1;
//	//t1.~Time;
//	//Time t2 = t1;
//	return 0;
//}





//����������һ��С��ʾ
//class Date
//{
//public:
//	~Date()
//	{
//		cout << "xigou" << endl;
//	}
//	Date(int a = 1)
//	{
//		_a = a;
//		cout << "��������" << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "ceshi" << endl;
//		d._a;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	Date da1(2);
//	Date d1;
//	Date t2 = d1;
//	return 0;
//}








//��������


//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	Date(const Date& d)
//	{
//		//d._year = this->_year;
//		//d._month = this->_month;
//		//d._day = this->_day;
//		//��������ʽ�����ǿ��޸ĵ���ֵ
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "����" << endl;
//	}
//private:
//	//������������
//	int _year;
//	int _month;
//	int _day;
//
//	//�����Զ�������
//	//Time _t;
//};
////int main()
////{
////	//Date d1(1995, 8, 19);
////	Date d1(1995,8,19);
////	Date d2(d1);//����д�Ļ����൱��d2��d1�����˸���
////	d1.Print();
////	d2.Print();
////	//Date d2 = d1;
////	return 0;
////}
//
//
//
//
//void func1(Date d)
//{
//
//}
//
//void func2(Date& rd)
//{
//
//}
//int main()
//{
//	Date d1(1995,8,19);
//	func1(&d1);
//	func2(d1);
//	return 0;
//}





//class Time
//{
//public:
//	Time(int time = 1)
//	{
//		_time = time;
//		cout << "��ӡ" << endl;
//	}
//
//private:
//	int _time;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//void func(Date d)
//{
//
//}
//
//void func1(Date& rd)
//{
//
//}
//int main()
//{
//	Date d1(1995, 8, 19);
//	//d1._t(1);
//	d1.Print();
//	func(d1);
//	func1(d1);
//	return 0;
//}




