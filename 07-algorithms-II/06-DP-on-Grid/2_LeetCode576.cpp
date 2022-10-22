#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 50 + 1;
int memory[MAX][MAX][MAX];

int m,n;

bool outOfBoundary(int r, int c){
    return 0 > r || r >= m || 0 > c || c >= n;
}

int countPathes(int r, int c, int steps){
    if(outOfBoundary(r, c))
        return 1;

    if(steps == 0)
        return 0;

    auto &ret = memory[r][c][steps];
    if(ret != -1)
        return ret;

    ret =  countPathes(r, c + 1, steps - 1);

    ret += countPathes(r + 1, c, steps - 1);
    ret %= MOD;

    ret += countPathes(r, c - 1, steps - 1);
    ret %= MOD;

    ret += countPathes(r - 1, c, steps - 1);
    ret %= MOD;

    return ret;
}

class Solution {
public:
    int findPaths(int m_, int n_, int maxMove, int startRow, int startColumn) {
        m = m_, n = n_;
        memset(memory, -1, sizeof(memory));

        return countPathes(startRow, startColumn, maxMove);
    }
};

int main(){

    return 0;
}
