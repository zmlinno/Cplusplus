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
//		//������ʵ��һ�����ε�this.
//		//This����ջ������ڵġ�
//	}
//	void Print()
//	{
//		cout << _year << "->" << _month << "->" << _day << endl;
//	}
//private:
//	//��������һ������
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
//	//��C++�� const��һ����������
//	//�����������������һ������i��ֵΪ0��
//	//��Ϊ������Ϊ���������ֵ���ܱ��޸�
//	int j = i;
//	const char* p = "xzxxxxx";
//	cout << &i << endl;
//	cout << &j << endl;
//	cout << &p << endl;
//	cout << (void*)p << endl;
//
//	//�ڴ����ϵͳ�У�
//	//�ַ����������洢�ڳ����ֻ�����ݶ��У�
//	//��� p ʵ������ָ��ֻ���ڴ��ָ�롣
//��ˣ�&p �� (void*)p ��ӡ�ĵ�ַ���ַ����������ڴ��е�	//��ַ��
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
//		//����ᱨ���ԭ�����
//		//��Ϊָ��p�ǿ�ָ�룬����ָ���κε���Ч����
//		//���Է��ʳ�Ա����_a�ᵼ�´���
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
//	//������*p����õ�ָ��pָ��Ķ���
//	//.���������ڷ��ʶ���ĳ�Ա����
//	//��Ϊ�������ȼ���
//	//��ָ��p��ָ��Ķ�����ó�Ա����
//	return 0;
//}

// ����ط���Ҫ���»ط� 




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









//����ȱʡֵ
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
	// ������ȱʡֵ
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
			perror("malloc����ռ�ʧ��!!!");
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

// Ĭ�����ɵ��������������캯������
// �������Ͳ��������Զ������͵ĳ�Աȥ������������
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