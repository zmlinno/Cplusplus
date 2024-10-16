//
//  STack.c
//  Algorithm
//
//  Created by 张木林 on 10/16/24.
//

#include "STack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

typedef struct STack
{
    STDataType* _a;
    int _top;
    int _capacity;
}STack;


//初始化栈
void StackInit(Stack* ps)
{
    ps->_a = (STDataType*)malloc(4*sizeof(STDataType)); //初始化容量为4
    if(ps->_a == NULL)
    {
        printf("内存分配失败");
        exit(-1);
    }
    ps->_top = 0; //栈顶初始化为0，表示栈为空
    ps->_capacity = 4;//初始容量
}

void StackPush(Stack* ps, STDataType data)
{
    
}
