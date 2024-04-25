#include<iostream>
using namespace std;

#include<string>
#include<vector>
#include<list>
//int main()
//{
//	int x = 0,y = 1;
//	swap(x, y);
//
//	double m = 1.1, n = 2.2;
//	swap(m, n);
//	cout << m << n << endl;
//	//这样的话两个数就被调换了
//	return 0;
//}

//template<class T>
//class Stack
//{
//public:
//	void push(const T& x)//这里T是一个常引用
//	{
//		//
//	}
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//};
//
//typedef int STDataType;
//typedef double STDataType;
////定义了两个类型别名
////一个是整数，一个是浮点型
//
//class Stackint
//{
//public:
//	void push(const STDataType& x)
//	{
//		//
//	}
//private:
//	STDataType* _a;
//	int _top;
//	int _capacity;
//};
//
//class Stackdouble
//{
//public:
//	void push(const STDataType& x)
//	{
//		//
//	}
//private:
//	STDataType* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack s1;
//	Stack s2;
//
//	return 0;
//}



//template<class T>
//class Stack
//{
//public:
//	void push(const T& x)
//		//在这里加上const的话增加了代码的健壮性
//		//表示只能读，不能被修改
//		//push的参数是一个引用，但是加上一个const就变成了常引用
//	{
//		//...
//	}
//
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//};
//
//
//typedef int STDataType;
//typedef double STDataType;
//
//class Stackint
//{
//public:
//	void push(const STDataType& x)
//	{
//		//...
//	}
//
//private:
//	STDataType* _a;
//	int _top;
//	int _capacity;
//};
//
//class Stackdouble
//{
//public:
//	void push(const STDataType& x)
//	{
//		//...
//	}
//
//private:
//	STDataType* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack s1; // int
//	Stack s2; // double
//
//	return 0;
//}


//T是一个泛型
//template<class T>
//class Stack
//{
//public:
//	void push(const T& x)
//	{
//		//
//	}
//	
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//};
//
//template<class T>
//void Stack<T>::push(const T& x)
//{
//	//...
//}
//
//int main()
//{
//	Stack<int> s1;
//	Stack<double> s2;
//	//通过一个模板实例化出两个类型
//	//因为T是泛型，变成啥类型都可以
//	return 0;
//}
//
//void Test_string01()
//{
//	string s0;
//	string s1("hello,world");
//	string s2(s1);
//	string s3(s1, 5, 3);
//	string s4(s1, 5, 10);
//	string s5(s1,5);
//
//	string s6(10, '*');
//
//	s0 = s6;
//
//	cout << s0 << endl;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	cout << s6 << endl;
//	cout << s0 << endl;
//
//	//return 0;
//
//
//}

void Test_string02()
{
	string s1("hello world");
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
		//如果后面加endl的话就会变成竖着打印了
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
		cout << s1[i] << " ";
		//这个打印的是ASCLL值
		//在C++中char类型的变量表达式在进行算术运算的时候会自动对应转换成ASCLL值
	}
	cout << endl;
}



int main()
{
	//Test_string01();
	Test_string02();
	return 0;
}



