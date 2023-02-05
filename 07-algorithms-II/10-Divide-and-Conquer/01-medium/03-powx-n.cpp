// https://leetcode.com/problems/powx-n
#include <bits/stdc++.h>
using namespace std;

class Solution {
    double DC(double x, int n){
        if(n == 0)
            return 1;
        if(n == 1)
            return x;

        double res = DC(x, n/2);
        return  res = res * res * (n%2==1?x:1);
    }

public:
    double myPow(double x, int n) {
        bool isNeg = n < 0;
        double res = DC(x, isNeg ? -(n + 1) : n);

        return isNeg ? 1/ (x * res) : res;
    }
};

int main(){
    cout << Solution().myPow(2,9) << "\n";

    return 0;
}
