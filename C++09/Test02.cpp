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

	string s3("hello world");
	s3[0]++;
	cout << s3 << endl;
	//��Ϊ����û��ѭ��
	//���Ը������棬C++��char�����ڽ��������������ʱ����ӡ����Ӧ��ASCLL��ֵ

	string s2("hello world");
	cout << s2 << endl;

	cout << s3.size() << endl;
	cout << s3.capacity() << endl;
	//����һ�����ַ���12���ַ�
	//����C++�ı�׼��
	//��׼����ܻ���������ڴ�������ÿ�������ַ�������ʱ��Ҫ���·����ڴ�Ŀ�������������ܷ����˸�����ڴ档
	//���ԣ�s3.capacity() ���ص����ַ��� s3 �ڲ��������������
	//����Ϊ15����ȡ���ڱ�׼��ľ���ʵ��


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
		//������*it3�ǽ����á������ǵ�ַ
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
	//�ײ���ǵ�����
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
	////�ײ���ǵ�����
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



