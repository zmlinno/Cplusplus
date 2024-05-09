//#pragma once
//
//#include<algorithm>
//
//namespace bit
//{
//    template<class T>
//    class vector
//    {
//    public:
//        typedef T* iterator;
//        typedef const T* const_iteartor;
//
//        iterator begin()
//        {
//            return _start;
//
//        }
//        iterator end()
//        {
//            return _finish;
//        }
//
//        const_iteartor begin() const
//        {
//            return _start;
//        }
//        const_iteartor end() const
//        {
//            return _finish;
//        }
//
//        vector<>
//        {}
//
//
//
//        vector(const vector<T>& v)
//        {
//            reserve(v.capacity());
//            for (auto e : v)
//            {
//                push_back(e);
//            }
//        }
//
//        ~vector()
//        {
//            delete[] _start;
//            _start = _finish = _endofstorage = nullptr;
//        }
//
//        size_t size() const
//        {
//            return _finish - _start;
//        }
//        T& operator[](size_t pos)
//        {
//            assert(pos < size());
//            return _start[pos];
//        }
//
//        const T& operator[](size_t pos)const
//        {
//            assert(pos > size());
//            return _start[pos];
//        }
//
//        size_t capacity()const
//        {
//            return _endofstorage - _start;
//        }
//
//        void reserve(size_t n)
//        {
//            if (n > capacity())
//            {
//                T* tmp = new T[n];
//                //分配了一个长度为n的数组
//                //tmp指向了长度为n的数组的指针。
//                size_t old_size = size();
//                memcpy(tmp, _start, size, sizeof(T));
//                //就是把_start的数据复制到
//                //tmp指向的新的分配的内存空间
//                //start指的是源内存区域
//
//
//
//                //元素个数✖️ 元素的字节数
//                //size,sizeof(T)
//                delete[] _start;
//                //释放原来的容器所使用的空间
//                //以避免内存泄漏
//                _start = tmp;
//                _finish = tmp + old_size;
//                endofstorage = tmp + n;
//            }
//        }
//
//        void resize(size_t n, const T& val = T())
//        {
//            if (n > size())
//            {
//                reserve(n);
//                //插入
//                while (_finish < _start + n)
//                {
//                    //因为这里+n代表了空间的扩容
//                    *_finish = val;
//                    ++_finish;
//                }
//            }
//            else
//            {
//                //删除
//                _finish = _start + n;
//            }
//        }
//
//
//
//        void push_back(const T& val)
//        {
//            insert(end(), val);
//            //这里就是尾插
//        }
//
//
//
//        void pop_back()
//        {
//            erase(--end());
//        }
//
//
//
//        void empty()
//        {
//            return _start == _finish;
//        }
//
//
//        void insert(iterator pos, const T& val)
//        {
//            assert(pos >= _start);
//            assert(pos <= _finish);
//            if (_finish == _endofstorage)
//            {
//                size_t len = pos - _start;
//                reserve(capacity() == 0 ? 4 : capacity() * 2);
//
//                pos = _start + len;
//                //如果扩容了更新pos
//            }
//
//            iterator it = _finish - 1;
//            while (it >= pos)
//            {
//                *(it + 1) = *it;
//                --it;
//            }
//            *pos = val;
//            _finish++;
//        }
//
//
//        void erase(inerator pos)
//        {
//            assert(pos >= _start);
//            assert(pos <= _finish);
//
//            iterator it = pos + 1;
//            while (it < _finish)
//            {
//                *(it - 1) = *it;
//                ++it;
//            }
//            --_finish;
//
//
//        }
//
//    private:
//        iterator _start = nullptr;
//        iterator _finish = nullptr;
//        iterator _endofstorage = nullptr;
//
//    };
//
//
//
//    //函数模版
//    template<class T>
//
//    void print_vector(const vector<T>& v)
//    {
//        for (int i = 0; i < v.size(); i++)
//        {
//            cout << v[i] << " ";
//        }
//        cout << endl;
//
//    }
//    void test_vector3()
//    {
//        vector<int> v1;
//        v1.push_back(1);
//        v1.push_back(2);
//        v1.push_back(3);
//        v1.push_back(4);
//        print_vector(v1);
//
//        vector<int> v2;
//        print_vector(v2);
//
//    }
//
//}




#pragma once

#include<assert.h>

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
		{
		}

		// v2(v1)
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}


		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t old_size = size();
				memcpy(tmp, _start, size() * sizeof(T));
				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_endofstorage = tmp + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n > size())
			{
				reserve(n);
				// 插入
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				// 删除
				_finish = _start + n;
			}
		}

		void push_back(const T& val)
		{
			/*if (_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = val;
			++_finish;*/

			insert(end(), val);
		}

		void pop_back()
		{
			/*assert(!empty());

			--_finish;*/

			erase(--end());
		}

		bool empty()
		{
			return _start == _finish;
		}

		void insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);

				// 如果扩容了要更新pos
				pos = _start + len;
			}

			iterator it = _finish - 1;
			while (it >= pos)
			{
				*(it + 1) = *it;
				--it;
			}
			*pos = val;
			++_finish;
		}

		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};

	//template<typename T>
	// 函数模板
	template<class T>
	void print_vector(const vector<T>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		//typename vector<T>::const_iterator it = v.begin();
		/*auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;*/
	}

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(4);
		v1.push_back(4);
		print_vector(v1);

		vector<double> v2;
		v2.push_back(1.1);
		v2.push_back(2.2);
		v2.push_back(3.1);
		print_vector(v2);

		v2.insert(v2.begin(), 11.11);
		print_vector(v2);

		v2.insert(v2.begin(), 11.11);
		print_vector(v2);

		v2.insert(v2.begin(), 11.11);
		print_vector(v2);

		v2.insert(v2.begin(), 11.11);
		print_vector(v2);

		v2.insert(v2.begin(), 11.11);
		print_vector(v2);

		v2.erase(v2.begin());
		print_vector(v2);

		v2.erase(v2.begin() + 4);
		print_vector(v2);

		/*for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;*/
	}

	void test_vector2()
	{
		int i = 1;
		int j = int();
		int k = int(2);

		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(4);
		v1.push_back(4);
		print_vector(v1);

		v1.resize(10);
		print_vector(v1);

		v1.resize(3);
		print_vector(v1);
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(4);
		v1.push_back(4);
		print_vector(v1);

		vector<int> v2(v1);
		print_vector(v2);
	}
}