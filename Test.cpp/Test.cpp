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
//	//这行代码之所以打印1
//	//是因为这行代码动态分配了包含4个整数的数组
//	//初始化 1，2，3，4
//	//pa是一个指向这个数组的指针，解引用得到的是数组第一个元素的值，也就是1
//	//如果想打印其它的就是pa+1 pa+2 pa+3
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
//	pair<string, string>kv1("sort", "排序");
//	pair<string, string>kv2("insert", "插入");
//	map<string, string>dict1 = { kv1,kv2 };
//	map<string, string>dict2 = { {"sort","排序"},{"insert","插入"} };
//	return 0;
//	//pair多参数隐式类型转换
//	//initializer_list<pair>的构造
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
//	// typeid推出时一个单纯的字符串
//	cout << typeid(it1).name() << endl;
//	// 不能用来定义对象
//	//typeid(it1).name() it2;
//
//	// typeid 是一个操作符，用于获取表达式的类型信息。在这里，typeid(it1).name() 返回一个表示 it1 类型的字符串。
//
//
//	decltype(it1) it2;
//	cout << typeid(it2).name() << endl;
//	//decltype 关键字用于获取表达式的类型。在这个例子中，decltype(it1) 返回 it1 的类型，
//	//即 list<int>::iterator，并用它定义了一个新的变量 it2。
//
//
//	auto it3 = it1;
//	cout << typeid(it3).name() << endl;
//
//	auto ret3 = func1();
//	B<decltype(ret3)> bb1;
//
//	map<string, string> dict2 = { {"sort", "排序"}, {"insert", "插入"} };
//	auto it4 = dict2.begin();
//	//auto 关键字用于自动推导变量的类型。在这个例子中，auto 推导 it3 的类型为 it1 的类型，
//	//即 list<int>::iterator。
//	B<decltype(it4)> bb2;
//	B<std::map<std::string, std::string>::iterator> bb2;
//	// auto和decltype有些地方增加代码读起来难度
//
//	return 0;
//}





//int main()
//{
//	map<string, string> dict2 = { { "sort","排序" }, {"insert", "插入"} };
//
//	for (auto& [x, y] : dict2)
//		//使用结构化绑定遍历map
//	{
//		cout << x << ":" << y << endl;
//		y += 2;
//	}
//	return 0;
//
//
//	for (auto [x, y] : dict2)
//		//再次遍历 map，但是不使用引用。这意味着在循环体内对 y 的修改不会影响到 map 中的值。
//
//
//	{
//		cout << x << ":" << y << endl;
//	}
//	pair<string, string>kv1 = { "sort","排序" };
//	//使用结构化绑定初始化一个 pair，并分别访问和打印 pair 中的元素。
//
//	auto [x, y] = kv1;
//	return 0;
//}








//int main()
//{
//	// 左值是一个表达式，可以取地址的
//	// 左值和右值，能否取地址
//	// 左值：可以取地址的
//	// 右值：不可以取地址的
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
//	//10、string("11111")、 to_string(123), x + y
//	//	cout << &10 << endl;
//	//cout << &string("11111") << endl;
//	//首先是不能对右值取地址
//
//	int x = 1, y = 2;
//	int&& rref1 = (x + y);//右值引用绑定到表达式结果
//	string&& rref2 = string("11111");//右值引用绑定到临时对象
//	string&& rref3 = to_string(123);//右值引用绑定到临时对象
//	int&& rref4 = 18;//右值引用绑定到字面值
//	
//
//	//左值引用绑定右值
//	const string& rref1 = string("1111");
//	const int& rref2 = 18;
//	string s1("1111");
//	string&& rref5 = move(s1);
//}




//int main() {
//	std::string s1("1111");
//	std::string&& rref5 = std::move(s1); // 右值引用绑定到移动后的左值
//
//	std::cout << "s1: " << s1 << std::endl; // 可能为空或未定义的内容
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
			cout << "string(char* str) -- 构造" << endl;

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

		// 拷贝构造
		// 左值
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// 移动构造
		// 右值(将亡值)
		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
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
		size_t _capacity; // 不包含最后做标识的\0
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