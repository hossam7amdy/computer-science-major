#include<bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX][MAX];

int m, n;
vector<vector<int>> grid;

int countPathes(int r, int c){
    if(r >= m || c >= n || grid[r][c] == 1)
        return 0;

    if(r == m - 1 && c == n - 1)
        return 1;

    auto &ret = memory[r][c];
    if(ret != -1)
        return ret;

    return ret = countPathes(r + 1, c) + countPathes(r ,c + 1);
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        m = (int)grid.size(), n = (int)grid[0].size();

        memset(memory, -1, sizeof(memory));
        return countPathes(0,0);
    }
};

int main() {

    return 0;
}
