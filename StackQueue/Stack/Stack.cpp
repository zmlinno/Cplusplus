//
//  Stack.cpp
//  Algorithm
//
//  Created by 张木林 on 10/16/24.
//

//#include "Stack.h"
#include<iostream>
#include<cassert>
using namespace std;
typedef int STDataType;
class Stack
{
public:
    Stack()
    : _a(nullptr),_top(0),_capacity(0)
    {
        StackInit();
    }
    ~Stack()
    {
        StackDestroy();
    }
    
    //入栈
    void StackPush(STDataType data)
    {
        //扩容检查
        if(_top == _capacity)
        {
            _capacity = _capacity == 0?4 :_capacity * 2;
            _a = (STDataType*)realloc(_a,_capacity*sizeof(STDataType));
            if(_a == nullptr)
            {
                cout<<"内存分配失败!"<<endl;
                exit(-1);
            }
        }
        _a[_top++] = data;
    }
    
    //出栈
    void StackPop()
    {
        assert(_top > 0);//保证栈不为空
        --_top;
    }
    
    //获取栈顶元素
    STDataType StackTop()const
    {
        assert(_top > 0);//保证栈不为空
        return _a[_top - 1];
    }
    
    //获取栈中元素个数
    int StackSize()const
    {
        return _top;
    }
    //检测栈是否为空
    bool StackEmpty()const
    {
        return _top == 0;
    }
private:
    //初始化栈
    void StackInit()
    {
        _capacity = 4;
        _a = (STDataType*)malloc(_capacity * sizeof(STDataType));
        _top = 0;
    }
    
    //销毁栈
    void StackDestroy()
    {
        if(_a != nullptr)
        {
            free(_a);
            _a = nullptr;
            _top = 0;
            _capacity = 0;
        }
    }
    STDataType* _a; //动态数组，用来存储栈元素
    int _top;   //栈顶指针
    int _capacity;  //栈的容量
    
};
