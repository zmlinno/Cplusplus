#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include<array>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<utility>
#include<assert.h>

struct point
{
	int _x;
	int _y;
};

class A
{
public:
	A(int x, int y)
		:_x(x)
		, _y(y)
	{}

	A(int x)
		:_x(x)
		,_y(x)
	{}


private:
	int _x;
	int _y;
};



//
//struct Point
//{
//	int _x;
//	int _y;
//};
//
//
//int main()
//{
//	int array1[] = { 1,2,3,4,5 };
//	int array2[5] = { 0 };
//	Point p = { 1,2 };
//
//	int* pa = new int[4]{ 1,2,3,4 };
//	cout << *pa << endl;
//	//���д���֮���Դ�ӡ1
//	//����Ϊ���д��붯̬�����˰���4������������
//	//��ʼ�� 1��2��3��4
//	//pa��һ��ָ����������ָ�룬�����õõ����������һ��Ԫ�ص�ֵ��Ҳ����1
//	//������ӡ�����ľ���pa+1 pa+2 pa+3
//	return 0;
//}




//int main()
//{
//	vector<int> v1;
//	vector<int> v2(10, 2);
//	vector<int> v3 = { 1,2,3,4,5 };
//	vector<int> v4{ 10,20,30 };
//	auto il1 = { 10,20,30 };
//	initializer_list<int> il2 = { 10,20,30 };
//	cout << typeid(il1).name() << endl;
//	cout << sizeof(il1) << endl;
//
//	pair<string, string>kv1("sort", "����");
//	pair<string, string>kv2("insert", "����");
//	map<string, string>dict1 = { kv1,kv2 };
//	map<string, string>dict2 = { {"sort","����"},{"insert","����"} };
//	return 0;
//	//pair�������ʽ����ת��
//	//initializer_list<pair>�Ĺ���
//}





//int main()
//{
//	int i = 0;
//	auto x = i;
//	x++;
//	cout << x << endl;
//}




//template<class T>
//class B
//{
//public:
//	T* New(int n)
//	{
//		return new T[n];
//	}
//
//};
//
//auto func1()
//{
//	list<int>lt;
//	auto ret = lt.begin();
//
//	return ret;
//}

//int main()
//{
//	list<int>::iterator it1;
//
//	// typeid�Ƴ�ʱһ���������ַ���
//	cout << typeid(it1).name() << endl;
//	// ���������������
//	//typeid(it1).name() it2;
//
//	// typeid ��һ�������������ڻ�ȡ���ʽ��������Ϣ�������typeid(it1).name() ����һ����ʾ it1 ���͵��ַ�����
//
//
//	decltype(it1) it2;
//	cout << typeid(it2).name() << endl;
//	//decltype �ؼ������ڻ�ȡ���ʽ�����͡�����������У�decltype(it1) ���� it1 �����ͣ�
//	//�� list<int>::iterator��������������һ���µı��� it2��
//
//
//	auto it3 = it1;
//	cout << typeid(it3).name() << endl;
//
//	auto ret3 = func1();
//	B<decltype(ret3)> bb1;
//
//	map<string, string> dict2 = { {"sort", "����"}, {"insert", "����"} };
//	auto it4 = dict2.begin();
//	//auto �ؼ��������Զ��Ƶ����������͡�����������У�auto �Ƶ� it3 ������Ϊ it1 �����ͣ�
//	//�� list<int>::iterator��
//	B<decltype(it4)> bb2;
//	B<std::map<std::string, std::string>::iterator> bb2;
//	// auto��decltype��Щ�ط����Ӵ���������Ѷ�
//
//	return 0;
//}





//int main()
//{
//	map<string, string> dict2 = { { "sort","����" }, {"insert", "����"} };
//
//	for (auto& [x, y] : dict2)
//		//ʹ�ýṹ���󶨱���map
//	{
//		cout << x << ":" << y << endl;
//		y += 2;
//	}
//	return 0;
//
//
//	for (auto [x, y] : dict2)
//		//�ٴα��� map�����ǲ�ʹ�����á�����ζ����ѭ�����ڶ� y ���޸Ĳ���Ӱ�쵽 map �е�ֵ��
//
//
//	{
//		cout << x << ":" << y << endl;
//	}
//	pair<string, string>kv1 = { "sort","����" };
//	//ʹ�ýṹ���󶨳�ʼ��һ�� pair�����ֱ���ʺʹ�ӡ pair �е�Ԫ�ء�
//
//	auto [x, y] = kv1;
//	return 0;
//}








//int main()
//{
//	// ��ֵ��һ�����ʽ������ȡ��ַ��
//	// ��ֵ����ֵ���ܷ�ȡ��ַ
//	// ��ֵ������ȡ��ַ��
//	// ��ֵ��������ȡ��ַ��
//
//	int a = 10;
//	int b = a;
//	const int c = 10;
//	int* p = &a;
//	vector<int>v(10, 1);
//	v[1];
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &(*p) << endl;
//	cout << &(v[1]) << endl;
//
//
//	return 0;
//}



//
//int main()
//{
//	//10��string("11111")�� to_string(123), x + y
//	//	cout << &10 << endl;
//	//cout << &string("11111") << endl;
//	//�����ǲ��ܶ���ֵȡ��ַ
//
//	int x = 1, y = 2;
//	int&& rref1 = (x + y);//��ֵ���ð󶨵����ʽ���
//	string&& rref2 = string("11111");//��ֵ���ð󶨵���ʱ����
//	string&& rref3 = to_string(123);//��ֵ���ð󶨵���ʱ����
//	int&& rref4 = 18;//��ֵ���ð󶨵�����ֵ
//	
//
//	//��ֵ���ð���ֵ
//	const string& rref1 = string("1111");
//	const int& rref2 = 18;
//	string s1("1111");
//	string&& rref5 = move(s1);
//}




//int main() {
//	std::string s1("1111");
//	std::string&& rref5 = std::move(s1); // ��ֵ���ð󶨵��ƶ������ֵ
//
//	std::cout << "s1: " << s1 << std::endl; // ����Ϊ�ջ�δ���������
//	std::cout << "rref5: " << rref5 << std::endl; // "1111"
//
//	return 0;
//}




namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str) -- ����" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		// ��ֵ
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// �ƶ�����
		// ��ֵ(����ֵ)
		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);

			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};

	bit::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		bit::string str;

		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
			str += ('0' + x);
		}
		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());

		return str;
	}
}
int main()
{
	bit::string ret1 = bit::to_string(1234);
	cout << ret1.c_str() << endl;

	/*bit::string ret1;
	ret1 = bit::to_string(1234);*/

	return 0;
}