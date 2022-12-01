// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int n;
    vector<char> path;
    vector<string> result;
    vector<vector<int>> grid;

    bool isValid(int i, int j){
        return 0 <= i && i < n && 0 <= j && j < n && grid[i][j];
    }

    void getPath(int i, int j, char ch){
        if(!isValid(i,j))
            return;

        // do
        grid[i][j] = 0;
        path.push_back(ch);

        if(i == n - 1 && j == n - 1)
            result.push_back(string(path.begin() + 1, path.end()));

        // recurse
        getPath(i - 1, j, 'U');
        getPath(i, j + 1, 'R');
        getPath(i + 1, j, 'D');
        getPath(i, j - 1, 'L');

        // undo
        grid[i][j] = 1;
        path.pop_back();
    }

public:
    vector<string> findPath(vector<vector<int>> &grid_) {
        grid = grid_;
        n = grid.size();

        getPath(0,0,' ');
        return result;
    }
};

int main() {


    return 0;
}
