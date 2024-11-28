#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

//定义方向数组 上下左右
// const int dx[4] = {-1,1,0,0};
// const int dy[4] = {0,0,-1,1};

// //深度优先搜索 计算连通块的和
// int dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int x,int y)
// {
//     int sum = 0;
//     int rows = grid.size();
//     int cols = grid[0].size();
    
//     //使用栈模拟递归
//     vector<pair<int,int>> stack = {{x,y}};
//     visited[x][y] = true;
    
//     while(!stack.empty())
//     {
//         auto[cx,cy] = stack.back();
//         stack.pop_back();
//         sum += grid[cx][cy] = '0';//转换字符为数字累加
        
//         //遍历四个方向
//         for(int i = 0;i<4;i++)
//         {
//             int nx = cx + dx[i];
//             int ny = cy + dy[i];
            
//             //检查边界条件和未访问条件
//             if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && grid[nx][ny] != 'X')
//             {
//                 visited[nx][ny] = true;
//                 stack.push_back({nx,ny});
//             }
//         }
//     }
//     return sum;
// }
// vector<int> solution(vector<string> maps) 
// {
//     int rows = maps.size();
//     int cols = maps[0].size();
    
//     //转换地图为字符矩阵
//     vector<vector<char>> grid(rows,vector<char>(cols));
//     for(int i = 0;i<rows;i++)
//     {
//         for(int j = 0;j<cols;j++)
//         {
//             grid[i][j] = maps[i][j];
//         }
//     }
    
//     //标记访问的矩阵
//     vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    
//     //结果存储
//     vector<int>regionSums;
    
//     //遍历整个矩阵
//     for(int i = 0;i<rows;i++)
//     {
//         for(int j = 0;j<cols;j++)
//         {
//             if(!visited[i][j] && grid[i][j] != 'X')
//             {
//                 //对未访问的数字快进行 DFS
//                 int regionSum = dfs(grid,visited,i,j);
//                 regionSums.push_back(regionSum);
//             }
//         }
//     }
    
//     //如果没有任何数字块，返回-1
//     if(regionSums.empty())
//     {
//         return {-1};
//     }
    
//     //按升序排序
//     sort(regionSums.begin(),regionSums.end());
//     return regionSums;
// }



vector<int> solution(vector<string> maps) {
    int rows = maps.size();                // 地图的行数
    int cols = maps[0].size();             // 地图的列数
    vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // 访问标记
    vector<int> result;                    // 保存每个岛屿的资源总和

    // 方向数组：上、下、左、右
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 广度优先搜索（BFS）函数
    auto bfs = [&](int x, int y) -> int {
        int sum = 0;                        // 当前岛屿的资源总和
        queue<pair<int, int>> q;            // 队列用于 BFS
        q.push({x, y});
        visited[x][y] = true;               // 标记起点为访问过

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            sum += maps[cx][cy] - '0';      // 累加资源值

            // 遍历上下左右四个方向
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                // 检查边界条件、未访问、以及不是海洋
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                    !visited[nx][ny] && maps[nx][ny] != 'X') {
                    visited[nx][ny] = true; // 标记访问
                    q.push({nx, ny});      // 加入队列
                }
            }
        }
        return sum;
    };

    // 遍历地图的每个点
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j] && maps[i][j] != 'X') { // 未访问且是陆地
                int islandSum = bfs(i, j);             // 计算岛屿的资源总和
                result.push_back(islandSum);           // 加入结果
            }
        }
    }

    if (result.empty()) return {-1};       // 如果没有岛屿，返回 -1
    sort(result.begin(), result.end());    // 按升序排列
    return result;
}