#include<iostream>
#include<string>
#include<stdexcept>
#include<string.h>
using namespace std;
class String
{
public:
    typedef char* iterator;
    
    iterator begin()
    {
        return _str;
    }
    iterator end()
    {
        return _str + _size;
    }
    String(const char*str ="")
        :_size(strlen(str))
        ,_capacity(_size)
    {
        cout<<"构造函数之前"<<endl;
        _str = new char[_capacity+1];
        strcpy(_str,str);
    }
    //析构函数
    ~String()
    {
        delete[]_str;
    }
    
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};
int main()
{
    String s("Hello,World");
    for(auto it = s.begin();it != s.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}