#include<iostream>
#include<assert.h>
#include"Stack.h"
#include"Stack.cpp"
#include<string>
#include<map>
using namespace std;
//类和对象
// int main()
// {
//     int a = 0;

//     //引用
//     int&b = a;
//     cout << &b << endl;
//     cout << &a << endl;
//     //在这里的引用可以证明b和a是同一个，
//     //b就是a的别名，地址是一样的。


//     b++;
//     a++;

//     int &c = a;
//     int &d = c;

//     d++;

//     cout << d << endl;
//     return 0;

    
// }



// void Swap(int *a,int *b)
// {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }


// void Swap(int& a,int& b)
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
// int main()
// {
//     int x = 0,y = 1;
//     Swap(&x,&y);
//     //这一步往上传回去的是指针

//     Swap(x,y);
//     //这个传回去的是引用
// }







// int main()
// {
//     int a = 0;
//     //引用必须初始化

//     int& b = a;
//     int c = 2;
//     b = c;
//     //在这个地方不是改变指向，而是赋值

//     int &d = b;
//     //一个变量可以有多个引用，多个别名
// }



class A2 {
public:
	void f2()
	{
		cout << "void f2()" << endl;
	}
};

int main()
{
	/*int i = 0;
	int j;*/

	A2 a2;
	A2* p1 = &a2;
	p1->f2();

	// 编译错误
	// 运行错误
	// 正常运行
	A2* p2 = nullptr;
	p2->f2();

	return 0;
}
