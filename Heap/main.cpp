//
//  main.cpp
//  Algorithm
//
//  Created by 张木林 on 10/25/24.
//

#include"Heap.cpp"
using namespace std;
int main()
{
    Heap h;
    h.HeapInit();
    
    h.HeapPush(10);
    h.HeapPush(20);
    h.HeapPush(5);
    h.HeapPush(30);
    
    cout<<"Heap top: " <<h.HeapTop()<<endl; //应该输出30
    h.HeapPop();
    cout<<"Heap top after pop: " <<h.HeapTop()<<endl;//应该输出20
    
    while(!h.HeapEmpty())
    {
        cout<<"Popped: "<<h.HeapTop()<<endl;
        h.HeapPop();
    }
    return 0;
}
