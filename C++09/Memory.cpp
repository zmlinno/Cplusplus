#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A();" <<this<< endl;
//
//	}
//	~A()
//	{
//		cout << "~A()" << this<<endl;
//	}
//
//private:
//	int _a;
//};
//
//
//class Stack
//{
//public:
//	Stack()
//	{
//		_a = (int*)malloc(sizeof(int)*4);
//		_top = 0;
//		_capcaity = 4;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capcaity;
//};
//int main()
//{
//	int* p1 = (int*)operator new(10 * 4);
//	A* ptr1 = new A;
//	A* ptr2 = new A[10];
//	cout << sizeof(A) << endl;
//	delete ptr1;
//	delete[] ptr2;
//
//	return 0;
//}



//int main()
//{
//	//这是关于内存泄漏
//	//没有进行释放
//	int* p1 = new int[1024 * 1024 * 100];
//	cout << p1 << endl;
//}



//void swap(int& n, int& m)
//{
//	int tmp = n;
//	n = m;
//	m = tmp;
//}
//
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	cout << a << b << endl;
//	swap(a, b);
//	cout << a << b << endl;
//	double c = 1.1, d = 1.2;
//	Swap(c, d);
//	cout << c << d << endl;
//}




template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	int a = 1;
	int b = 2;
	double c = 1.2;
	double d = 1.3;
	//int sum = Add(a, b);
	//cout << Add(a, b) << endl;
	//cout << Add(c, d) << endl;


	//在这里显示实例化
	cout << Add<double>(a, c) << endl;
	cout << Add<int>(b, d) << endl;
	return 0;
}