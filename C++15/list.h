#pragma once
#include<assert.h>

namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& x = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(x)
		{}
	};

	// typedef ListIterator<T, T&, T*> iterator;
	// typedef ListIterator<T, const T&, const T*> const_iterator;

	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;

		Node* _node;

		ListIterator(Node* node)
			:_node(node)
			//将这个私有变量赋值给_node;
		{}

		// *it
		//T& operator*()
		Ref operator*()
		{
			return _node->_data;
		}
		
		// it->
		//T* operator->()
		Ptr operator->()
		{
			return &_node->_data;
			//但是在这里的话，返回的是一个指向成员的指针，而不是成员本身。
		}

		// ++it
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			//在这个地方接受一个int参数来区分于前置递增运算符
			//创建一个临时对象tmp，将当前迭代器的值传递给tmp，
			//然后再将 _node指向下一个节点_next,
			//最后返回创建的临时对象tmp，

			//因为返回的是递增前的迭代器副本，所以称后置运算符。

			_node = _node->_next;

			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	//template<class T>
	//struct ListConstIterator
	//{
	//	typedef ListNode<T> Node;
	//	typedef ListConstIterator<T> Self;

	//	Node* _node;

	//	ListConstIterator(Node* node)
	//		:_node(node)
	//	{}

	//	// *it
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	// it->
	//	const T* operator->()
	//	{
	//		return &_node->_data;
	//	}

	//	// ++it
	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	Self operator++(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_next;

	//		return tmp;
	//	}

	//	Self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	Self operator--(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_prev;

	//		return tmp;
	//	}

	//	bool operator!=(const Self& it)
	//	{
	//		return _node != it._node;
	//	}

	//	bool operator==(const Self& it)
	//	{
	//		return _node == it._node;
	//	}
	//};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		//typedef ListIterator<T> iterator;
		//typedef ListConstIterator<T> const_iterator;

		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		//iterator begin()
		//{
		//	//return iterator(_head->_next);
		//	iterator it(_head->_next);
		//	return it;
		//}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		// const����������Ҫ�ǵ����������޸ģ����ǵ�����ָ������ݣ�
		// ������ָ������ݲ����޸ģ�const iterator����������Ҫconst������

		// T* const p1
		// const T* p2
		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		// ��Ҫ������һ�����Ҫ�Լ�д���
		// ����Ҫ������һ��Ͳ���Ҫ�Լ�д�����Ĭ��ǳ�����Ϳ���

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
			// 至于这里为什么要交换是因为
			// 创建一个新的链表，把lt里面的内容一次性交换到新的链表里面
			// 这样的话，比一个一个直接插入到lt里面效率会更快。
		}

		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		/*void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}*/

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(val);
			Node* prev = cur->_prev;
			//这是指向了cur前一个节点的指针。

			// prev newnode cur;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			_size--;

			return iterator(next);
		}

		size_t size() const
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
			//检查链表是否为空，
			//如果为0就是为空，返回true
			//否则返回false
		}

	private:
		Node* _head;
		size_t _size;
		//size_t 类型通常用于表示数组的大小，循环计数器，容器中元素等
		//由于是无符号整数类型，因为不会有负值，
		//可以更好地用于表示对象的大小和索引，避免一些负值引起的问题。
	};


	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it += 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.pop_back();
		lt.pop_front();
		lt.pop_front();
		
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	struct A
	{
		int _a1;
		int _a2;

		A(int a1 = 0, int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{}
	};

	void test_list2()
	{
		list<A> lt;
		A aa1(1, 1);
		A aa2 = { 1, 1 };
		lt.push_back(aa1);
		lt.push_back(aa2);
		lt.push_back(A(2, 2));
		lt.push_back({3, 3});
		lt.push_back({4, 4});

		A* ptr = &aa1;
		(*ptr)._a1;
		ptr->_a1;

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it += 10;
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			cout << it->_a1 << ":" << it->_a2 << endl;
			cout << it.operator->()->_a1 << ":" << it.operator->()->_a2 << endl;

			++it;
		}
		cout << endl;
	}

	void PrintList(const list<int>& clt)
	{
		list<int>::const_iterator it = clt.begin();
		while (it != clt.end())
		{
			//*it += 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		PrintList(lt);

		list<int> lt1(lt);
		PrintList(lt1);
	}
}
