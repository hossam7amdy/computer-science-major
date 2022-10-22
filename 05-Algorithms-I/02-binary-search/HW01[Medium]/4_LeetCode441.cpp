#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


class Solution {
public:
    int arrangeCoins_v1(int n) {
        if(n == 1) return n;

        int k = 0;
        for(int i = 1; i <= n; ++i){
            n -= i;
            ++k;
        }

        return k;
    }
    // can you build given levels with n coins?
    bool possible(long long levels, int n){
        levels = levels * (levels + 1) / 2;
        return levels <= n;
    }
    int arrangeCoins_v2(int n){
        int st = 0, en = n, staircase = 0;

        while(st <= en){
            int mid = st + (en - st) / 2;

            if(possible(mid, n))
                st = mid + 1, staircase = mid;
            else
                en = mid - 1;
        }

        return staircase;
    }
};

int main(){
    Solution s;
    cout << s.arrangeCoins_v2(1) << endl;
    cout << s.arrangeCoins_v2(2) << endl;
    cout << s.arrangeCoins_v2(3) << endl;
    cout << s.arrangeCoins_v2(4) << endl;
    cout << s.arrangeCoins_v2(8) << endl;
    cout << s.arrangeCoins_v2(9) << endl;
    cout << s.arrangeCoins_v2(INT_MAX) << endl;

    return 0;
}
