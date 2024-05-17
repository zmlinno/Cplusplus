#pragma once
#include<vector>
#include<list>
#include<deque>

namespace bit
{
	/*template<class T>
	class stack
	{
	private:
		T* _a;
		int _top;
		int _capacity;
	};*/

	// 设计模式
	// 适配器模式 -- 转换
	// stack<int, vector<int>> st1;
	// stack<int, list<int>> st2;

	// 写一个模版类，使用适配器模式。
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
    //压入一个元素栈顶
		void push(const T& x)
		{
			_con.push_back(x);
		}
    //弹出栈顶元素
		void pop()
		{
			_con.pop_back();
		}

		size_t size()
		{
			return _con.size();
		}
        //这个函数检查栈是否为空
		bool empty()
		{
			return _con.empty();
		}

        //返回栈顶元素引用
		const T& top()
		{
			return _con.back();
		}
	private:
		Container _con;//用于存储元素的底册容器
	};
}