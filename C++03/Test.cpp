
#include<iostream>
#include<typeinfo>
#include<map>
#include<string>
using namespace std;

// int Add(int a,int b)
// {
//     int sum;
//     sum = a+b;
//     return sum;
// }
// int main()
// {
//     int ret = Add(1,2);
//     cout << ret << endl;
//     return 0;
// }



// int main()
// {
//     int x = 1;
//     cout << typeid(x).name() << endl;
//     return 0;
// }







// auto f2()
// {
//     auto ret = 1;
//     return ret;
// }
// auto f1()
// {
//     auto x = f2();
//     return x;

// }
// auto TestAuto()
// {
//     auto a = f1();
//     return a;
// }

// void func(int x,int y)
// {
//     std::cout << "Function called with arguments: " << x << " and " << y << std::endl;
// }
// int main()
// {
// 	int i = 0;
// 	int j = i;
// 	auto k = i;
// 	// auto x;
// 	auto p1 = &i;
// 	auto* p2 = &i;
// 	//auto* p3 = i;
// 	auto& r = i;

// 	void(*pf1)(int, int) = func;
// 	auto pf2 = func;

// 	cout << typeid(pf1).name() << endl;
// 	cout << typeid(pf2).name() << endl;

//     pf1(10,20);
//     pf1(30,40);

// 	// std::map<std::string, std::string> dict;
// 	// //std::map<std::string, std::string>::iterator it = dict.begin();
// 	// auto it = dict.begin();

// 	// cout << typeid(it).name() << endl;

// 	// auto it2 = TestAuto();

// 	return 0;
// }





int main()
{
    int array[] = {1,2,3,4,5};
    for(int i = 0; i<sizeof(array)/sizeof(array[0]);i++)
    array[i] *= 2;

    for(int *p = array;p< array + sizeof(array)/ sizeof(array[0]);++p)
    cout << *p << endl;


    return 0;
}








