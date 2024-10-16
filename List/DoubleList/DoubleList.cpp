//
//  DoubleList.cpp
//  Algorithm
//
//  Created by 张木林 on 10/15/24.
//
//双链表的增删查找

#include<iostream>
#include<cassert>
using namespace std;

typedef int LTDataType;

struct ListNode
{
    LTDataType _data;
    ListNode* _next;
    ListNode* _prev;
    
    ListNode(LTDataType data = LTDataType())
    :_data(data),_next(nullptr),_prev(nullptr){}
    
};


//创建返回链表的头节点
ListNode* ListCreate()
{
    //头节点初始化，头节点指向自己
    ListNode* pHead = new ListNode();
    pHead->_next = pHead;
    pHead->_prev = pHead;
    return pHead;
}


//双向链表打印
void ListPrint(ListNode* pHead)
{
    assert(pHead);
    ListNode* cur = pHead->_next;
    while(cur != pHead)
    {
        cout<<cur->_data<<" ";
        cur = cur->_next;
    }
    cout<<endl;
}


//双向列表销毁
void ListDestory(ListNode* pHead)
{
    assert(pHead);
    ListNode* cur = pHead->_next;
    while(cur != pHead)
    {
        ListNode* next = cur->_next;
        delete cur;
        cur = next;
    }
    delete pHead;//销毁头节点
}


//双向链表尾插
void ListPushBack(ListNode* pHead,LTDataType x)
{
    assert(pHead);
    ListNode* newNode = new ListNode(x);
    ListNode* tail = pHead->_prev;
    
    //插入节点
    tail->_next = newNode;
    newNode->_prev = tail;
    newNode->_next = pHead;
    pHead->_prev = newNode;
}


//双向链表尾删
void ListPopBack(ListNode* pHead)
{
    assert(pHead && pHead->_next != pHead);//链表不为空
    ListNode* tail = pHead->_prev;
    ListNode* prevNode = tail->_prev;
    
    prevNode->_next = pHead;
    pHead->_prev = prevNode;
    delete tail;
}



//双向链表头插
void ListPushFront(ListNode* pHead,LTDataType x)
{
    assert(pHead);
    ListNode* newNode = new ListNode(x);
    ListNode* first = pHead->_next;
    
    pHead->_next = newNode;
    newNode->_prev = pHead;
    newNode->_next = first;
    first->_prev = newNode;
}


//双向列表头删
void ListPopFront(ListNode* pHead)
{
    assert(pHead && pHead->_next != pHead);//链表不为空
    ListNode* first = pHead->_next;
    ListNode* second = first->_next;
    
    pHead->_next = second;
    second->_prev = pHead;
    delete first;
}


//双向链表查找
ListNode* ListFind(ListNode* pHead,LTDataType x)
{
    assert(pHead);
    ListNode* cur = pHead->_next;
    while(cur != pHead)
    {
        if(cur->_data == x)
        {
            return cur;
        }
        cur = cur->_next;
    }
    return nullptr;//未找到
    
}

//双向链表在pos的前面进行插入
void ListInsert(ListNode* pos,LTDataType x)
{
    assert(pos);
    ListNode* newNode = new ListNode(x);
    ListNode* prevNode = pos->_prev;
    
    //插入节点
    prevNode->_next = newNode;
    newNode->_prev = prevNode;
    newNode->_next = pos;
    pos->_prev = newNode;
}

//双向链表删除pos位置节点
void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* prevNode = pos->_prev;
    ListNode* nextNode = pos->_next;
    
    //重新链接前后节点
    prevNode->_next = nextNode;
    nextNode->_prev = prevNode;
    
    delete pos;
}
