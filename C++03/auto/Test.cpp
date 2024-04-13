#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
    auto i = 10;
    std::cout << "this is:" << i << std::endl;
    // auto x = 10; // x的类型将会被推导为int
    // std::cout << "The value of x is: " << x <<  std::endl;

   return 0;
}