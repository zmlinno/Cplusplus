//
//  Sort.cpp
//  Algorithm
//
//  Created by 张木林 on 10/25/24.
//

#include<iostream>
#include<stack>
using namespace std;

//冒泡排序
void BubbleSort(int *a,int n)
{
    for(int i = 0;i<n-1;i++)
    {
        bool swapped = false;
        
        //每一轮循环都将较大的元素冒泡到末尾
        for(int j = 0;j<n-i-1;++j)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
                swapped = true;
            }
        }
        
        //如果某一轮没有发生交换，说明已经排序完成
        if(!swapped)
        {
            break;
        }
    }
}


//快速排序-Hoare版本划分
int PartSort1(int *a,int left,int right)
{
    int pivot = a[left];
    int l = left, r = right;
    while(l<r)
    {
        //从右向左找到比pviot小的元素
        while(l<r && a[r] >= pivot)
        {
            r--;
        }
        
        //从左向右找到比pviot大的元素
        while(l<r && a[l] <= pivot)
        {
            l++;
        }
        if(l<r)
        {
            swap(a[l],a[r]);
        }
    }
        //将基准放到最终位置
        swap(a[left],a[l]);
        return  l;
    
}


//快速排序-挖坑法
int PartSort2(int *a,int left,int right)
{
    int pivot = a[left];//基准值
    int hole = left; //当前 坑 的位置
    
    while(left < right)
    {
        //从右向左找到小于基准值的元素，填到 坑中
        while(left < right && a[right] >= pivot)
        {
            right--;
        }
        a[hole] = a[right]; //将a[right]放入hole
        hole = right;//右边形成新坑
        
        //从左向右找到大于基准值的元素，填到 坑中
        while(left < right && a[left] <= pivot)
        {
            left++;
        }
        a[hole] = a[left];//将a[left]放入hole
        hole = left;//左边形成新坑
    }
    
    //最后将基准值放入 坑中
    a[hole] = pivot;
    return hole;
}


//快速排序-前后指针法
int PartSort3(int *a,int left,int right)
{
    int pivot = a[right];//基准值
    int i = left - 1;//前指针
    
    for(int j = left;j<right;++j)
    {
        if(a[j] > pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    
    //将基准值放入正确位置
    swap(a[i+1],a[right]);
    return i+1;
}




//递归快速排序实现
void QuickSort(int *a,int left,int right)
{
    if(left < right)
    {
        //选择一种划分法，这里以Hoare为例
        int pivot = PartSort1(a,left,right);
        QuickSort(a, left, pivot - 1);//左半部分递归
        QuickSort(a, pivot+1, right);//右半部分递归
    }
}



//快速排序，非递归实现
void QuickSortNonR(int *a,int left,int right)
{
    stack<int>s;
    s.push(left);
    s.push(right);
    
    while(!s.empty())
    {
        int r = s.top();s.pop();
        int l = s.top();s.pop();
        
        if(l<r)
        {
            int pivot = PartSort1(a,l,r);//使用Hoare划分法
            if(pivot - 1 >l)
            {
                s.push(l);
                s.push(pivot - 1);
            }
            
            if(pivot+1<r)
            {
                s.push(pivot+1);
                s.push(r);
            }
        }
    }
}



int main()
{
    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //测试冒泡排序
    BubbleSort(arr, n);
    cout<<"Sortte array (Bubble Sort): ";
    for(int i = 0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    //测试快速排序(递归)
    int arr2[] = {10,7,8,9,1,5};
    QuickSort(arr2,0,n-1);
    cout<<"Sorted array (Quick Sort - Recursion): ";
    for(int i = 0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    
    
    
    //测试快速排序(非递归)
    int arr3[] = {10,7,8,9,1,5};
    QuickSort(arr3, n, n-1);
    cout<<"Sorted array (Quick Sort - Non-Recursion): ";
    for(int i = 0;i<n;++i)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    return 0;
}
