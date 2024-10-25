//
//  Heap.cpp
//  Algorithm
//
//  Created by 张木林 on 10/25/24.
//

//#include "Heap.hpp"
#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
typedef int HPDataType;

class Heap
{
public:
    //构建函数，初始化堆
    Heap():_size(0),_capacity(0){}
    
    //析构函数，释放堆内存
    ~Heap()
    {
        HeapDestory();
    }
    
    //堆的初始化
    void HeapInit()
    {
        _size = 0;
        _capacity = 0;
        _a.clear();//使用vector，自动管理内存
    }
    
    //堆的销毁
    void HeapDestory()
    {
        _a.clear();//晴空vector
        _size = 0;
        _capacity = 0;
    }
    
    //插入元素到堆中
    void HeapPush(HPDataType x)
    {
        if(_size == _capacity)
        {
            _capacity = _capacity == 0?1:_capacity*2;
            _a.resize(_capacity);
        }
        _a[_size] = x;
        ++_size;
        HeapifyUp(_size - 1);//上滤
    }
    
    //删除堆顶元素
    void HeapPop()
    {
        if(HeapEmpty())
        {
            throw std::underflow_error("Heap is empty");
            
        }
        swap(_a[0],_a[_size - 1]);
        --_size;
        HeapifyUp(0);//下滤
    }
    
    //获取堆顶元素
    HPDataType HeapTop()
    {
        if(HeapEmpty())
        {
            throw std::underflow_error("Heap is empty");
        }
        return _a[0];
    }
    
    //获取堆的大小
    int HeapSize()const
    {
        return _size;
    }
    //判断堆是否为空
    bool HeapEmpty()const
    {
        return _size == 0;
    }
private:
    
    //上滤操作，维持堆的性质
    void HeapifyUp(int chindIndex)
    {
        int parentIndex = (chindIndex-1)/2;
        while(chindIndex>0 && _a[chindIndex]>_a[parentIndex])
        {
            swap(_a[chindIndex],_a[parentIndex]);
            chindIndex = parentIndex;
            parentIndex = (chindIndex-1)/2;
        }
    }
    
    //下滤操作，维持堆堆性质
    void HeapifyDown(int parentIndex)
    {
        int largest = parentIndex;
        int leftChild = 2*parentIndex+1;
        int rightChild = 2*parentIndex+2;
        
        if(leftChild < _size && _a[leftChild]>_a[largest])
        {
            largest = leftChild;
        }
        
        if(rightChild < _size && _a[rightChild] > _a[largest])
        {
            largest = rightChild;
        }
        
        if(largest != parentIndex)
        {
            swap(_a[parentIndex],_a[largest]);
            HeapifyDown(largest);
            
        }
    }
    vector<HPDataType>_a;   //使用vector来动态管理堆堆存储
    int _size;  //堆中的元素个数
    int _capacity; //堆的容量
};




