#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<list>
#include<assert.h>
#include<algorithm>
using namespace std;


// class A
// {
// public:
//     A(int x) : value(x)
//     {
//         cout<<"Constructor called with value;"<<endl;
//     }

//     void display()const{
//         cout<<"Value:"<<endl;
//     }

// private:

//     int value;
// };



// int main()
// {
//     //使用单参数隐式类型转换，初始化，调用A(int)构造函数
//     A aa2 = 1; 
    

//     //使用列表初始化
//     A aa3 = {3};
//     A aa4{4}; //这是直接列表初始化，调用A(int)构造函数
//     aa2.display();
//     aa3.display();
//     aa4.display();
    
//     return 0;
// }




// template<typename Y>
// class Vector
// {
// public:
//     Vector(const Y& x1)
//     {
//         cout<<"Vector1"<<endl;
//     }
//     Vector(const Y& x1,const Y& x2)
//     {
//         cout<<"Vector2"<<endl;
//     }
//     Vector(const Y& x1,const Y& x2,const Y& x3)
//     {
//         cout<<"Vector3"<<endl;
//     }
//     Vector(const Y& x1,const Y& x2,const Y& x3,const Y& x4)
//     {
//         cout<<"Vector4"<<endl;
//     }

// };
// int main()
// {
//     Vector<int>v1(1);
//     Vector<int>v2(1,2);
//     Vector<int>v3(1,2,3);
//     Vector<int>v4(1,2,3,4);
//     return 0;
// }





//关于模板
// template<class T>
// class B
// {
// public:
//     T* New(int n)
//     {
//         return new T[n];
//     }
// };


// int main()
// {
//     B<int> intArrayCreator;
//     int *intArray = intArrayCreator.New(5);

//     for(int i = 0;i<5;i++)
//     {
//         intArray[i] = i*2;
//         cout<<"intArray"<<i<<"j ="<<intArray[i]<<endl;
//     }


//     //创建一个 B<double>对象
//     B<double>doubleArrayCreator;
//     double*doubleArray = doubleArrayCreator.New(3);

//     for(int i = 0;i<3;i++)
//     {
//         doubleArray[i] = i*1.1;
//         cout<<"doubleArray"<<i<<" = "<<doubleArray[i]<<endl;
//     }

//     //记得释放内存
//     delete[] intArray;
//     delete[] doubleArray;
//     return 0;
// }






//左值引用 右值引用
//move 需要包含头文件
// #include<utility>
// int main()
// {
//     string s1("1111");
//     string&& rrfe1 = move(s1);
//     cout<<s1<<endl;
//     cout<<rrfe1<<endl;
//     return 0;
// }

#include<string.h>

namespace bit
{
    class String
    {
    public:
        typedef char* iterator;
        //表示指向字符的指针，
        //这个别名通常用于定义类的迭代器类型
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
            //这个是返回指向_Str末尾后一个位置的指针
            //这样可以用于STL兼容的迭代器操作
        }

        String(const char* str = "")
        //接受一个C风格字符串作为参数，默认值为空字符
            :_size(strlen(str))
            ,_capacity(_size)
            //第二步初始化成员列表
            //在构造函数体之前执行
        {
            cout<<"String(char* str) -- 构造"<<endl;
            _str = new char[_capacity+1];
            strcpy(_str,str);
        }

    void Swap(String& s)
    {
        ::swap(_str,s._str);
        ::swap(_size,s._size);
        ::swap(_capacity,s._capacity);
    }


    //拷贝构造
    //左值
    //在这个地方要这样记住
    //1.因为我们是拷贝构造，那么就代表有了数据
    //我们只是负责把这个数据拷贝到新的里面
    //所以第一步我们肯定先初始化列表
    //先分配新的内存空间
    //然后复制大小
    //在复制容量
    String(const String& s)
        :_str(nullptr)
    {
        cout<<"深拷贝"<<endl;


        _str = new char[s._capacity+1];
        //这个+1是多出的一个字符用于存储字符串的终止字符'\0'
        //这样做的原因是确保新对象有足够的空间容纳原对象的字符串
        //这也是防止内存溢出的必要步骤
        strcpy(_str,s._str);
        //这一步是深拷贝操作
        _size = s._size;
        _capacity = s._capacity;
    }


    //移动构造
    //右值
    String(String&& s)
        :_str(s._str)
        ,_size(s._size)
        ,_capacity(s._capacity)
        {
            s._str = nullptr;
            s._size = 0;
            s._capacity = 0;
        }

    //赋值重载  
    String& operator=(const String& s)
    {
        cout<<"深拷贝:"<<endl;
        char* tmp = new char(_capacity+1);
        _str = tmp;
        _size = s._size;
        _capacity = s._capacity;
        return *this;
    }
    ~String()
    {
        delete[]_str;
        _str = nullptr;
    }

    char& operator[](size_t pos)
    {
        assert(pos<_size);
        return _str[pos];

    }

    void reserve(size_t n)
    {
        if(n>_capacity)
        {
            char* tmp = new char[n+1];
            strcpy(tmp,_str);
            delete[]_str;
            _str = tmp;
            _capacity = n;

        }
    }

    void Push_Back(char ch)
    {
        if(_size>=_capacity)
        //如果当前大小大于等于容量，需要扩展容量
        {
            size_t newcapacity = _capacity == 0?4:_capacity*2;  
            //新的容量太小，如果当前容量为0，则初始化为4，否则容量加倍      
            reserve(newcapacity);    
            //调用reserve函数来扩展容量
        }
        _str[_size] = ch;
        //将字符添加到字符串末尾
        ++_size;
        //更新字符串大小
        _str[_size] = '\0';
        //在字符串末尾添加终止字符'\0'
    }


        
    private:
        char* _str;
        size_t _size;
        size_t _capacity;//不包含最后做标识的'\0'

    };


    bit::String to_string(int value)
    {
        bool flag = true;
        //1.判断是不是负数
        //2.如果是负数，那么负负得正，value = 0 - value
        if(value<0)
        {
            flag = false;
            value = 0 - value;
        }

        bit::String str;
        while(value>0)
        {
            int x = value%10;
            value /= 10;
            str += ('0'+x);
        }
        if(flag == false)
        {
            str += '-';
        }
        reverse(str.begin(),str.end());
        return str;
    }
}


int main()
{
	bit::String ret1 = bit::to_string(1234);
	cout<<ret1.c_str()<<end;

	/*bit::string ret1;
	ret1 = bit::to_string(1234);*/

	return 0;
}