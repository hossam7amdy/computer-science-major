// https://leetcode.com/problems/integer-break/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 58 + 1;
int memory[MAX];

int productSum(int n){ // O(n^2)
    if(n <= 1)
        return 1;

    auto &ret = memory[n];
    if(ret != -1)
        return ret;

    for(int i = 1; i <= n; ++i)
        ret = max(ret, i * productSum(n - i));

    return ret;
}

class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3)
            return n - 1;

        memset(memory, -1, sizeof(memory));
        return productSum(n);
    }
};

int main(){
    Solution sol;

    cout << sol.integerBreak(2) << "\n";
    cout << sol.integerBreak(3) << "\n";
    cout << sol.integerBreak(4) << "\n";
    cout << sol.integerBreak(5) << "\n";
    cout << sol.integerBreak(6) << "\n";
    cout << sol.integerBreak(10) << "\n";
    cout << sol.integerBreak(58) << "\n";

    return 0;
}
