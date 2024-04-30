#pragma once
#include<assert.h>

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		/*	string()
				:_str(new char[1])
				,_size(0)
				,_capacity(0)
			{
				_str[0] = '\0';
			}

			string(const char* str)
				:_size(strlen(str))
				,_str(new char[strlen(str)+1])
				,_capacity(strlen(str))
			{
				strcpy(_str, str);
			}*/

		const char* c_str()
		{
			return _str;
		}

		//string(const char* str = "\0")
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s2(s1)
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// s1 = s3;
		string& operator=(const string& s)
		{
			char* tmp = new char[s._capacity+1];
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
			_size = _capacity = 0;
		}

		// 遍历
		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			// 扩容2倍
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			// 扩容
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			// 扩容2倍
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			size_t end = _size+1;
			while (end > pos)
			{
				_str[end] = _str[end-1];
				--end;
			}

			_str[pos] = ch;
			++_size;
		}

		void insert(size_t pos, const char* str)
		{

		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || len >= _size-pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		static const int npos;
	};

	const int string::npos = -1;

	void test_string1()
	{
		string s1("hello world");
		string s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
		}
		cout << endl;

		// s1[100];

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		const string s3("xxxx");
		for (size_t i = 0; i < s3.size(); i++)
		{
			//s3[i]++;
			cout << s3[i] << " ";
		}
		cout << endl;


		// 越界检查是一种抽查
		//int a[10];
		// a[10];
		// a[11];
		// //a[10] = 1;
		// a[15] = 1;
	}

	void test_string2()
	{
		string s3("hello world");
		for (auto ch : s3)
		{
			cout << ch << " ";
		}
		cout << endl;

		string::iterator it3 = s3.begin();
		while (it3 != s3.end())
		{
			*it3 -= 1;
			cout << *it3 << " ";
			++it3;
		}
		cout << endl;

		const string s4("xxxx");
		string::const_iterator it4 = s4.begin();
		while (it4 != s4.end())
		{
			//*it4 += 3;
			cout << *it4 << " ";
			++it4;
		}
		cout << endl;

		for (auto ch : s4)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string3()
	{
		string s3("hello world");
		s3.push_back('1');
		s3.push_back('2');
		cout << s3.c_str() << endl;
		s3 += 'x';
		s3 += "yyyyyy";
		cout << s3.c_str() << endl;

		string s1("hello world");
		s1.insert(11, 'x');
		cout << s1.c_str() << endl;

		s1.insert(0, 'x');
		cout << s1.c_str() << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.erase(6, 3);
		cout << s1.c_str() << endl;

		s1.erase(6, 30);
		cout << s1.c_str() << endl;

		s1.erase(3);
		cout << s1.c_str() << endl;

		string s2("hello world");
		cout << s2.c_str() << endl;

		s2.resize(5);
		cout << s2.c_str() << endl;

		s2.resize(20, 'x');
		cout << s2.c_str() << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2(s1);
		cout << s2.c_str() << endl;

		s1[0] = 'x';

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3("xxxxx");
		s1 = s3;

		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
	}
}
