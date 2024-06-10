#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void test_vector()
{
        vector<int> v(10,1);
        for(size_t i = 0;i<v.size();i++)
        {
                cout << v[i] << " ";
        }
        cout << endl;

        for(auto e: v)
        {
                cout << e << " ";
        }
        cout << endl;
}

int main()
{
        test_vector();
        return 0;
}