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

	string s3("hello world");
	s3[0]++;
	cout << s3 << endl;
	//因为这里没有循环
	//所以根据上面，C++中char类型在进行算数运算符的时候会打印出对应的ASCLL的值

	string s2("hello world");
	cout << s2 << endl;

	cout << s3.size() << endl;
	cout << s3.capacity() << endl;
	//算上一个空字符是12个字符
	//但是C++的标准库
	//标准库可能会分配额外的内存来避免每次增加字符串长度时都要重新分配内存的开销，因此它可能分配了更多的内存。
	//所以，s3.capacity() 返回的是字符串 s3 内部分配的总容量，
	//这里为15，这取决于标准库的具体实现


	string::iterator it3 = s3.begin();
	//while (it3 != s3.end())
	//{
	//	*it3 -= 3;
	//	cout << *it3 << " ";
	//	it3++;
	//	//cout << *it3 << " ";
	//}
	//cout << endl;

	it3 = s3.begin();
	while (it3 != s3.end())
	{
		cout << *it3 << " ";
		//在这里*it3是解引用。而不是地址
		it3++;
	}
	cout << endl;
}


void Test_string03()
{
	string s1("hello world");
	string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		it1[0]++;
		cout << *it1 <<" ";
		it1++;
	}
	cout << endl;
}


void Test_string04()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator itt = lt.begin();
	while (itt != lt.end())
	{
		cout << *itt << endl;
		itt++;
	}
	cout << endl;

	string s1("hello world");
	//底层就是迭代器
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	
	for (auto e : lt)
	{
		cout << e << " ";
	}

	
}



void Test_string05()
{
	string s1("hello world");
	//vector<int>::iterator i = s1.begin();

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
	//string s1("hello world");
	////底层就是迭代器
	//for (auto e : s1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
}


int main()
{
	//Test_string01();
	//Test_string02();
	//Test_string03();
	//Test_string04();
	Test_string05();
	return 0;
}



