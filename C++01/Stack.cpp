#include"Stack.h"
void Stack::Init(int n)
{
    a = (int*)malloc(sizeof(int)*n);
    if(nullptr == a)
    {
        perror("malloc fail");
        return;
    }
    capacity = n;
    top = 0;

}

void Stack::Push(int x)
{
    a[top++] = x;
}