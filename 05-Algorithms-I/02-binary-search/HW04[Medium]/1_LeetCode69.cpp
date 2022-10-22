#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    long long power(const int& n, const int& e){
        long long sum = 1;
        for(int i = 0; i < e; ++i)
            sum *= n;

        return sum;
    }
    int mySqrt(int x) {
        int st = 0, en = x, ans = 0;
        while(st <= en){
            int mid = st + (en - st) / 2;
            if(power(mid, 2) <= x)
                st = mid + 1, ans = mid;
            else
                en = mid - 1;
        }
            return ans;
    }
};

int main(){
    Solution s;
    cout << INT_MAX << endl;
    cout << s.mySqrt(20) << endl;
    cout << s.mySqrt(8) << endl;
    cout << s.mySqrt(4) << endl;
    cout << s.mySqrt(25) << endl;
    cout << s.mySqrt(16) << endl;
    cout << s.mySqrt(INT_MAX) << endl;

    return 0;
}
