//
//  SelectSort.cpp
//  Algorithm
//
//  Created by 张木林 on 10/25/24.
//

#include<iostream>
#include<vector>
using namespace std;

//选择排序
void SelectSort(int *a,int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int minIndex = i;
        //找到最小元素的索引
        for(int j = i+1;j<n;++j)
        {
            if(a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        //交换当前元素和最小元素
        if(minIndex != i)
        {
            swap(a[i],a[minIndex]);
        }
    }
}


//下沉调整堆的性质
void AdjustDown(int *a,int n,int root)
{
    int parent = root;
    int child = 2 * parent+1; //左孩子
    
    while(child < n)
    {
        //如果右孩子存在，且右孩子大于左孩子
        if(child + 1<n&& a[child+1]>a[child])
        {
            child++;
        }
        
        //如果孩子节点大于父节点，交换它们位置
        if(a[child] > a[parent])
        {
            swap(a[child],a[parent]);
            parent = child;
            child = 2 * parent + 1;//继续调整
            
        }
        else
        {
            break;
        }
    }
}


//堆排序
void HeapSort(int *a,int n)
{
    //1.建立最大堆
    for(int i = (n-2)/2;i>=0;--i)
    {
        AdjustDown(a, n, i);
    }
    
    //2.交换堆顶元素与数组最后一个元素，并调整堆
    for(int i = n-1;i>0;--i)
    {
        swap(a[0],a[i]);//将最大元素放到数组末尾
        AdjustDown(a, i, 0);//调整剩下的元素，重新构建堆
        
    }
    
}

//测试代码
int main()
{
    int a[] = {5,2,9,1,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    
    //选择排序测试
    SelectSort(a, n);
    cout<<"After SelectSort: ";
    for(int i = 0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    //堆排序测试
    int b[] = {5,2,9,1,5,6};
    HeapSort(b, n);
    cout<<"After HeapSort: ";
    for(int i = 0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
