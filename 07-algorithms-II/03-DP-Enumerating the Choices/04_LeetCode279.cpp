#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000 + 1;
int memory[MAX];

int minPerfectSquares(int n){
    if(n <= 0)
        return 0;

    auto &ret = memory[n];
    if(ret != -1)
        return ret;

    ret = n;
    for(int i = 1; i * i <= n ; ++i)
        ret = min(ret, 1 + minPerfectSquares(n - i * i));

    return ret;
}

class Solution {
public:
    int numSquares(int n) {
        memset(memory, -1, sizeof(memory));

        return minPerfectSquares(n);
    }
};

int main(){
    Solution sol;

    cout << sol.numSquares(12) << "\n";
    cout << sol.numSquares(13) << "\n";
    cout << sol.numSquares(7852) << "\n";

    return 0;
}
