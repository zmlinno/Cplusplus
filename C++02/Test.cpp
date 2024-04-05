#include<iostream>
using namespace std;
//类和对象中

// struct A
// {
//     private:
//     int _a;
//     char _i;
// };

// struct B
// {
//     private:
//     char _i;
//     int _a;
// };


// int main()
// {
//     cout <<sizeof(A) << endl;
//     cout <<sizeof(B) << endl;
//     //打印是8个字节
//     //实际上int为4个，char为1一个自己，打印出来为5个字节
//     //8个字节是因为内存对齐的优点，补充为4个和4个
//     //cpu一次只能从内存中读取特定大小的数据，如果数据不是按照大小对齐存放的话
//     //需要进行额外处理

//     char i = 1;
//     int j = 10;
//     return 0;
// }





//日期类
// class Date
// {
//     public:
//     void Init(int year,int month,int day)
//     {
//         // _year = year;
//         // _month = _month;
//         // _day = _day;
//         //1.第一个错误在这里
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//    // const Date *const p;

//     // *void Print(Date *const this)
//     // {
//     //     cout <<this->_year <<"-"<<this->_month<<"-"<<this->_day<<"-"<< endl;
//     // }*
    
//     void Print()
//     {
//        //this = nullptr;
//         cout <<this->_year <<"-"<<this->_month<<"-"<<this->_day<< endl;
//     }
//     private:
//     //声明
//     int _year;
//     int _month;
//     int _day;
// };


// int main()
// {
//     Date d1;
//     d1.Init(2024,4,5);
//     Date d2;
//     d2.Init(1995,8,19);

//     d1.Print();
//     d2.Print();

//     return 0;
// }

//this是存在栈里面的
//这个要仔细看看

// class A
// {
//     public:
//     void PrintA()
//     {
//         cout<< this << endl;
//         //cout<< "Print()" << endl;
//         cout << _a << endl;
//     }
//     private:
//     int _a;
// };

// int main()
// {
//     A*p = nullptr;
    
//     p->PrintA();
//     //在这个地方
//     //因为null赋值给了p，所以上面那个隐形指针this打印出来的地址是
//     //00
//     // A p;
//     // p.PrintA();
//     // A *p = nullptr
//     // (*p).PrintA();
//     //这里报错是因为试图调用一个空指针。
//     //而nullptr不是函数或函数指针类型，因为无法像函数一样调用
//     //因为*p是一个空指针，编译器认为你在尝试对一个空指针进行函数调用
//     //这是不允许的，解决这个错误的话，需要确保p指向一个有效的对象
//     //或者使用动态内存分配来分配一个对象并将其地址赋值给p
//     return 0;
// }






// class Date
// {
//     public:
//     void Init(int year,int month,int day)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }

//     void Print()
//     {
//         cout << _year <<"-"<<_month<<"-"<<_day<< endl;
//     }
//     private:
//     int _year;
//     int _month;
//     int _day;
// };


// int main()
// {
//     Date d1;
//     d1.Init(1995,8,19);
//     d1.Print();
    
//     return 0;
// }





//特殊的成员函数
// class Date
// {
//     public:
//     // Date()
//     // {
//     //     _year = 1;
//     //     _month = 1;
//     //     _day = 1;
//     // }

//     // Date(int year,int month,int day)
//     // {
//     //     _year = year;
//     //     _month = month;
//     //     _day = day;
//     // }

//     Date(int year = 1,int month = 1,int day = 1)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }

//     Date(int year)
//     {
//         _year = year;
//     }
    
//     void Print()
//     {
//         cout << _year <<"-"<<_month<<"-"<<_day<< endl;
//         //cout << _year << endl;
//     }

//     // void Print2()
//     // {
//     //      cout << _year << endl;
//     // }
//     private:
//     int _year;
//     int _month;
//     int _day;
// };

// int main()
// {
//    // Date d1();
//     Date d1;
//     d1.Print();

//     Date d2(1995,8,19);
//     d2.Print();

//     // Date d3(2024);
//     // d3.Print2();

//     // Date d4(2,3);
//     // d4.Print();
//     return 0;
// }



class Date
{
    public:
    Date()
    {
        _year = 1;
        _month = 1;
        _day = 1;
    }
    Date(int year,int month,int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    void Print()
    {
        cout << _year <<"-"<<_month<<"-"<<_day<< endl;
    }

    ~Date()
    {
        cout << this << endl;
        cout << "~Date() " << endl;
    }
    private:
    //声明缺省值
    int _year = 1;
    int _month = 1;
    int _day;
};

void fun()
{
    Date d2;
}

class Stack
{
    public:
    Stack(size_t capacity = 3)
    {
        _array = (int*)malloc(sizeof(int)*capacity);
        {
            if(NULL == _array)
            {
                perror("malloc fail");
                return;
            }
            _capacity = capacity;
            _size = 0;
        }

    void Push(int data)
    {
        _array[_size] = data;
        _size++;
    }    

    bool Empty()
    {
        return _size == 0;
    }

    int Top()
    {
        return _array[_size-1];
    }

    void Pop()
    {

    }
    ～Stack()
    {
        cout << "~Stack()" << endl;
        if(_array)
        {
            free(_array);
            _array = nullptr;
        }
        _size = _capacity = 0;
    }
    private:
    int *_array;
    int _capacity;
    int _size;
    }
};


class MyQueue
{
    private:
    Stack _st1;
    Stack _st2;

};

bool isValid(const char *s)
{
    Stack st;

    while(*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
		{
			st.Push(*s);
		}
		else
		{
			if (st.Empty())
			{
				return false;
			}
			char topVal = st.Top();
			st.Pop();
			if ((*s == ']' && topVal != '[')
				|| (*s == ')' && topVal != '(')
				|| (*s == '}' && topVal != '{'))
			{
				return false;
			}
		}

		++s;
    }
    return st.Empty();
}

int main()
{

    MyQueue q;
    return 0;
}
