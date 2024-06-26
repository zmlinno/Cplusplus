// #include<iostream>
// class A
// {
// public:
//     void Print()
//     {
//         //std::cout<<this<<std::endl;
//         std::cout<<_a<<std::endl;
//     }
// private:
//     int _a;

// };
// int main()
// {
//     A* p = nullptr;
//     p->Print();
//     return 0;
// }



#include <iostream>
#include <vector>

using namespace std;

// bool isLeapYear(int year) {
//     return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
// }

// int main() {
//     int y, n;
//     vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     while(cin >> y >> n) {
//         if(isLeapYear(y)) {
//             daysInMonth[2] = 29;
//         }
//         int day = 1, month = 1;
//         while(n > daysInMonth[month]) {
//             n -= daysInMonth[month];
//             month++;
//         }
//         if(month < 10) {
//             cout << y << "-0" << month << "-";
//         } else {
//             cout << y << "-" << month << "-";
//         }
//         if(n < 10) {
//             cout << "0" << n << endl;
//         } else {
//             cout << n << endl;
//         }
//     }
//     return 0;
// }



#include <iostream>

  using namespace std;

   

  int main()

  {

    int year;

    int day;

     

    int mon[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};   

    while(cin>>year>>day)

    {

      if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))

        mon[1] = 29;

      else

        mon[1] = 28;

        

      for(int i = 0; i < 12; i++)

      {

        if(day <= mon[i])

        {

          printf("%04d-%02d-%02d\n", year, i + 1, day);

          break;

        }

        else

        {

        day = day - mon[i];

        }

    }

    }

    return 0;

  }