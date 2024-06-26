#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>


void test_vector()
{
    vector<int> v(10,1);
    for(size_t i = 0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for(auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}



void test_vector1()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    //test_vector();
    test_vector1();
    return 0;
}