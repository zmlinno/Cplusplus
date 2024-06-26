#include<iostream>
// //这是一个Date类的拷贝构造函数的具体作用
// class Date
// {
// public:
//     Date(int year,int month,int day)
//     :_year(year),_month(month),_day(day)
//     {}

//     Date(const Date& d)
//     {
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }

    
//     void Print()
//     {
//         std::cout << _year<<"-"<<_month<<"-"<<_day<<std::endl;
//     }
// private:
//     int _year;
//     int _month;
//     int _day;

// };



// int main()
// {
//     Date d1(1992,8,19);//// 创建一个 Date 对象 d1
    
//     Date d2(d1);//// 使用拷贝构造函数创建一个新的 Date 对象 d2
    
//     std::cout<<"d1: ";
//     d1.Print();

//     std::cout<<"d2: ";
//     d2.Print();
//     return 0;
// }





//写一个自动生成的默认构造函数的行为
// class Myclass
// {
// public:
//     Myclass() = default;
//     //显式定义
//     //可以更好维护代码的可读性
//     void Print()
//     {
//         std::cout<<"x: "<<x<<"y: "<<y<<std::endl;
//     }
// private:
//     int x;
//     double y;
// };



// int main()
// {
//     Myclass obj;
//     obj.Print();
//     return 0;
// }


// #include <climits>

// using namespace std;

// #include <iostream>
// using namespace std;
// int main()
// {
//     int year,mon,day;
//     int data[]={31,28,31,30,31,30,31,31,30,31,30,31};
//     while(cin>>year>>mon)
//     {
//         int sum;
//         for(int i=0;i<mon-1;i++)
//         {
//               sum=sum+data[i];
//         }
//         if((year%400==0||(year%4==0&&year%100!=0))&&mon>2)
//             sum=sum+1+day;
//         else 
//             sum=sum+day;
//         cout<<sum<<endl;

//     }
//     return 0;
//}




#include<iostream>
#include <vector>
#include <string>
using namespace std;



// #include <iostream>
// #include <vector>

using namespace std;

//判断是否是闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 根据年和天数计算月份和日期
void findDate(int year, int dayOfYear) {
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 如果是闰年，二月有29天
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    int month = 0;
    while (dayOfYear > daysInMonth[month]) {
        dayOfYear -= daysInMonth[month];
        month++;
    }

    // 输出结果
    cout << year << "-";
    if (month + 1 < 10) {
        cout << "0";
    }
    cout << month + 1 << "-";
    if (dayOfYear < 10) {
        cout << "0";
    }
    cout << dayOfYear << endl;
}

int main() {
    int year, dayOfYear;

    while (cin >> year >> dayOfYear) {
        findDate(year, dayOfYear);
    }

    return 0;
}