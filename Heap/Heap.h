//
//  Heap.hpp
//  Algorithm
//
//  Created by 张木林 on 10/25/24.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>

#endif /* Heap_hpp */
typedef int HPDataType;
typedef struct Heap
{
    HPDataType* _a;
    int _size;
    int _capacity;
}Heap;

void HeapInit(HP* php);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
