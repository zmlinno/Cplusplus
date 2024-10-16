//
//  Queue.cpp
//  Algorithm
//
//  Created by 张木林 on 10/16/24.
//

//#include "Queue.h"
#include<iostream>
#include<cassert>
using namespace std;

typedef int QDataType;

//队列节点类
struct QListNode
{
    QDataType _data;
    QListNode* _next;
    
    QListNode(QDataType data)
    :_data(data),_next(nullptr){}
};


//队列类
class Queue
{
public:
    //构造函数
    Queue()
    :_front(nullptr),_rear(nullptr){}
    
    
    //析构函数
    ~Queue()
    {
        QueueDestory();
    }
    
    //初始化队列(构造函数中已完成)
    void QueueInit()
    {
        _front = _rear = nullptr;
    }
    
    //队尾入队列
    void QueuePush(QDataType data)
    {
        QListNode* newNode = new QListNode(data);
        if(_rear == nullptr)
        {
            //如果队列为空
            _front = _rear = newNode;
        }
        else
        {
            _rear->_next = newNode;
            _rear = newNode;
        }
    }
    
    //队头出队列
    void QueuePop()
    {
        assert(_front != nullptr && "Queue is empty!");//确保队列不为空
        QListNode* temp = _front;
        _front = _front->_next;
        if(_front ==  nullptr)
        {
            _rear = nullptr; //如果队列为空，队尾也为空
        }
        delete temp;
    }
    
    //获取队列头部元素
    QDataType QueueFront()const
    {
        assert(_front != nullptr && "Queue is empty!");//确保队列不为空
        return _front->_data;
    }
    
    //获取队列队尾元素
    QDataType QueueBack()const
    {
        assert(_rear != nullptr && "Queue is empty!");//确保队列部位空
        return _rear->_data;
    }
    
    //获取队列中有效元素个数
    int QueueSize()const
    {
        int size = 0;
        QListNode* cur = _front;
        while(cur != nullptr)
        {
            ++size;
            cur = cur->_next;
        }
        return size;
    }
    
    //检测队列是否为空
    bool QueueEmpty()const
    {
        return _front == nullptr;
        
    }
    
    //销毁队列
    void QueueDestory()
    {
        while(_front != nullptr)
        {
            QListNode* temp = _front;
            _front = _front->_next;
            delete temp;
        }
        _rear = nullptr;
    }
    
    
private:
    QListNode* _front; //队列头指针
    QListNode* _rear;//队列的尾指针
};
