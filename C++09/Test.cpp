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
//	//�����Ļ��������ͱ�������
//	return 0;
//}

//template<class T>
//class Stack
//{
//public:
//	void push(const T& x)//����T��һ��������
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
////�������������ͱ���
////һ����������һ���Ǹ�����
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
//		//���������const�Ļ������˴���Ľ�׳��
//		//��ʾֻ�ܶ������ܱ��޸�
//		//push�Ĳ�����һ�����ã����Ǽ���һ��const�ͱ���˳�����
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


//T��һ������
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
//	//ͨ��һ��ģ��ʵ��������������
//	//��ΪT�Ƿ��ͣ����ɶ���Ͷ�����
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
		//��������endl�Ļ��ͻ������Ŵ�ӡ��
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
		cout << s1[i] << " ";
		//�����ӡ����ASCLLֵ
		//��C++��char���͵ı������ʽ�ڽ������������ʱ����Զ���Ӧת����ASCLLֵ
	}
	cout << endl;
}



int main()
{
	//Test_string01();
	Test_string02();
	return 0;
}



