#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
void bfs(int startNode,vector<vector<int>>& garph)
{
    int n = garph.size();
    vector<bool>visited(n,false);
    queue<int>q;//队列

    //初始化bfs
    q.push(startNode);
    visited[startNode] = true;

    cout<<"BFS traversal order: ";

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout<<current<<" ";
        //cout<<endl;

        for(int neighbor: garph[current])
        {
            if(!visited[neighbor])
            {
                q.push(neighbor); //将未访问的邻居加入队列
                visited[neighbor] = true;   //已经访问的返回true
            }
        }
    }
}
int main()
{
    vector<vector<int>> garph =
    {
                {1,2},
        {0,3,4},
        {0,4},
        {1,5},
        {1,2,5},
        {3,4}
    };
    bfs(0,garph);
    cout<<endl;
    return 0;
}