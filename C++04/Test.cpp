#include<iostream>
using namespace std;


//int main()
//{
//	auto i = 10;
//	auto q = 2.74;
//	//cout << i << q << endl;
//	//这样打印为啥是 102.74呢？
//	cout << i << endl;
//
//
//	return 0;
//}






//int main()
//{
//	int array[] = { 1,2,3,4,5 };
//	//for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
//	//	array[i] *= 2;
//	//for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//	//	cout << *p << endl;
//
//
//	//for (auto& e : array)
//	//{
//	//	e *= 2;
//	//	
//	//}
//	//cout << endl;
//	//for (auto e : array)
//	//{
//	//	 cout<< e << endl;
//	//}
//	//cout << endl;
//
//	for (auto e : array)
//	{
//		e *= 2;
//		cout << e << endl;
//	}
//	//这样写是可能的
//
//	return 0;
//}
//和上面相比，依次取数组中值赋值给e，自动迭代，自动判断结束



//int main()
//{
//	int x = 5;
//	f(&x);
//	return 0;
//}
//
//void f(int* p)
//{
//	cout << "f(int*)" << endl;
//}
//一会这个地方需要单独听下
//10：45之前





// 简单一个类
class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
//private:
	int _year;
	int _month;
	int _day;
};

//
//int main()
//{
//	Date d1;
//	//d1._year++;
//	cout << sizeof(d1) << endl;
//	d1.Init(2024, 1, 23);
//	d1._day++;
//	d1.Print();
//	//cout << sizeof(d1) << endl;
//	//d1.Init(2014, 1, 24);
//	//
//	//d1.Print();
//	return 0;
//}


//auto f2()
//{
//	auto ret = 1;
//	return ret;
//}
//class A2
//{
//public:
//	void f2(){}
//};
//class A3
//{
//
//};
//int main()
//{
//	//Date d1;
//	//Date d2;
//	//d1._year;
//	//d2._year;
//
//	//d1.Print();
//	//d2.Print();
//	//A2 a2;
//	//a2.f2();
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	//cout << a2 << endl;
//	return 0;
//}
// 一会研究下，为啥两个打印结果是1呢

class A2
{
public:
	void f2()
	{
		cout << "void f2()" << endl;
	}
};
int main()
{
	A2 a2;
	A2* p1 = &a2;
	p1->f2();

	A2* p2 = nullptr;
	p2->f2();

	return 0;
}

