//
//  Sort.hpp
//  Algorithm
//
//  Created by 张木林 on 10/25/24.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>

#endif /* Sort_hpp */
// 冒泡排序
void BubbleSort(int* a, int n)

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
