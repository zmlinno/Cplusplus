#include<iostream>
using namespace std;

//#pragma pack(1)
//struct A
//{
//private:
//	int _a;
//	char _i;
//};
//
//struct B
//{
//private:
//	char _i;
//	int _a;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//
//	return 0;
//}




//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//		//这里其实有一个隐形的this.
//		//This是在栈里面存在的。
//	}
//	void Print()
//	{
//		cout << _year << "->" << _month << "->" << _day << endl;
//	}
//private:
//	//在这里是一个声明
//	int _year;
//	int _month;
//	int _day;
//
//};
////int main()
////{
////	Date d1;
////	d1.Init(2024, 1, 23);
////
////	Date d2;
////	d2.Init(2024, 1, 24);
////
////	//d1.Print(&d1);
////	//d2.Print(&d2);
////	d1.Print();
////	d2.Print();
////	return 0;
////}
//
//
//
//
//
//int main()
//{
//	Date d1;
//	d1.Init(1995, 8, 19);
//
//	Date d2;
//	d2.Init(2014, 2, 22);
//
//	const int i = 0;
//	//在C++中 const是一个声明常量
//	//在这个代码中声明了一个常量i，值为0，
//	//因为被定义为常量，因此值不能被修改
//	int j = i;
//	const char* p = "xzxxxxx";
//	cout << &i << endl;
//	cout << &j << endl;
//	cout << &p << endl;
//	cout << (void*)p << endl;
//
//	//在大多数系统中，
//	//字符串常量被存储在程序的只读数据段中，
//	//因此 p 实际上是指向只读内存的指针。
//因此，&p 和 (void*)p 打印的地址是字符串常量在内存中的	//地址。
//
//
//	return 0;
//}







///*class A
//{
//public:
//	void PrintA()
//	{
//	*/	cout << this << endl;
//		
//		cout << _a << endl;
//		//这里会报错的原因就是
//		//因为指针p是空指针，它不指向任何的有效对象
//		//所以访问成员变量_a会导致错误
//
//		cout << "Print()" << endl;
//		
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	(*p).PrintA();
//	//解引用*p，会得到指针p指向的对象
//	//.操作符用于访问对象的成员函数
//	//因为这个代码等价于
//	//对指针p所指向的对象调用成员函数
//	return 0;
//}

// 这个地方需要看下回放 




//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2024, 02, 22);
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
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//Date func();
//	//Date d1();
//	Date d1;
//	d1.Print();
//
//	Date d2(1995, 8, 19);
//	d2.Print();
//
//	Date d3(1995);
//	d3.Print();
//	
//	return 0;
//}




//class A
//{
//public:
//	void AB()
//	{
//		cout << "A()" << endl;
//	}
//};
//int main()
//{
//	A* p = nullptr;
//	p->AB();
//	return 0;
//}









//关于缺省值
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}









class Date
{
public:
	Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << this << endl;
		cout << "~Date()" << endl;
	}

private:
	// 声明给缺省值
	int _year = 1;
	int _month = 1;
	int _day;
};

void func()
{
	Date d2;
}

class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (int*)malloc(sizeof(int) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}

	void Push(int data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	bool Empty()
	{
		return _size == 0;
	}

	int Top()
	{
		return _array[_size - 1];
	}

	void Pop()
	{
		//..
	}

	~Stack()
	{
		cout << "~Stack()" << endl;
		if (_array)
		{
			free(_array);
			_array = nullptr;
		}

		_size = _capacity = 0;
	}

private:
	int* _array;
	int _capacity;
	int _size;
};

// 默认生成的析构函数跟构造函数类似
// 内置类型不做处理，自定义类型的成员去调用他的析构
class MyQueue
{
private:
	Stack _st1;
	Stack _st2;
	Stack _st3;
};

bool isValid(const char* s) {
	Stack st;

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			st.Push(*s);
		}
		else
		{
			if (st.Empty())
			{
				return false;
			}
			char topVal = st.Top();
			st.Pop();
			if ((*s == ']' && topVal != '[')
				|| (*s == ')' && topVal != '(')
				|| (*s == '}' && topVal != '{'))
			{
				return false;
			}
		}

		++s;
	}

	return st.Empty();
}

int main()
{
	/*func();

	Date d1;
	d1.Print();

	Stack st1;*/

	isValid("()[]{}");

	//MyQueue q;

	return 0;
}