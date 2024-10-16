//
//  main.cpp
//  Algorithm
//
//  Created by 张木林 on 10/16/24.
//

#include"DoubleList.cpp"

int main()
{
    ListNode* pHead = ListCreate();
    
    ListPushBack(pHead,1);
    ListPushBack(pHead,2);
    ListPushBack(pHead,3);
    
    ListPrint(pHead); //输出 1 2 3
    
    ListPushFront(pHead,0);
    ListPrint(pHead);//输出0 1 2 3
    
    ListPopBack(pHead);
    ListPrint(pHead); //输出0 1 2
    
    ListPopFront(pHead);
    ListPrint(pHead);
    
    ListDestory(pHead);
    return 0;
}
