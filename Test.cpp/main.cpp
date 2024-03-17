//
//  main.cpp
//  Test.cpp
//
//  Created by 张木林 on 2/25/24.
//

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//int x = 10;
//int main()
//{
//    //int x = 1;
//    printf("%d\n",x);
//    //根据就近原则是会打印main函数里面的
//    //如果屏蔽掉那么就打印全局变量里面的x了。
//    return 0;
//}




namespace zml 
{
int rand = 10;
int x = 0;
int Add(int left,int right)
{
    return left+right;
}
struct Node
{
    struct Node *next;
    int val;
};
}

namespace lmz
{
int x = 1;
}

int main()
{
    printf("%d\n",zml::x);//这样的写法就能访问到其他函数里面的成员变量了。
    printf("%d\n",lmz::x);
    
    struct zml::Node phead;
    return 0;
}

//int& fun()
//{
//    int a = 22;
//    return a;
//}
//
//int fx()
//{
//    int b = 1;
//    return b;
//    
//}
//int main()
//{
//    
//    int& ret = fun();
////    printf("%d\n",ret);
////    return 0;
//
//    cout << ret << endl;
//    fx();
//    cout << ret << endl;
//    
//}
// 问题1 为啥不是随机值呢？返回的都是我输入的数字呢



//int fun(int a,int b)
//{
//    
//    return a+b;
//}
//
//int main()
//{
//    
//    cout << fun(3,4) << endl;
//    for(int i = 0;i<=10;i++)
//    {
//        cout << i << endl;
//    }
////    int arr[0] = {1,2,3,4,5,6};
////    int sum;
////    int sum = sizeof(arr[i])/sizeof(arr);
//    int a = 0;
//    int&b = a;
//    cout << &b << endl;
//    //这个地方访问的就是地址
//    
//}



//namespace zml {
//namespace  qq
//{
//    void Push()
//{
//    cout << "haha" << endl;
//}
//}
//}
//int main()
//{
//    
//    int i = 100;
//    i = i << 1; //左移+100；
//    const char *p = "hello world";
//    char a = '\n';
//    zml::qq::Push();
//    
//    cout << i << endl;
//    cout << p << endl;
//    printf("%s%c\n",p,a); // 具有自动识别功能，不像C语言一样，还要手动识别
//    // %s打印的char类型？？
//    cout << i << p << a << endl;
//    
//}







//int main()
//{
//    int i;
//    int a;
//    cin >> i >> a;
//    cout << i << a << endl;
    //    输入22和33 打印结果是223 是因为cin操作符会被22解释为一个整数，而33会解释为一个字符
    //    因为cin操作符遇到空格会停止读取，所以只能读到22 这个数字，33没有成功读取，因为空格的存在只读取到了 3 这个字符，所以打印223
    //    要想正确 读取 22 33 即使有空格，使用getline 和 stringstream来实现
    //    如下
    
//}






