#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    set<int>numbers;
    for(int i = 0;i<2;++i)
    {
        int num;
        cin>>num;
        numbers.insert(num);
    }

    //计算剩余的数字
    int sum = 0;
    for(int j = 1;j<=N;j++)
    {
        if(numbers.find(j) == numbers.end())
       // if(numbers.find[j] == numbers.end())
        {
            sum += j;
        }
    }
    cout<<sum<<endl;
    cout<<endl;
    
}