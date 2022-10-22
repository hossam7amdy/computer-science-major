#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution { /// O(n log n)
public:
    bool isValid(const vector<int>& nums, const int &div, const int &threshold){ // O(n)
        long long sum = 0;

        for(int i = (int)nums.size() - 1; i >= 0; --i){
            sum += (nums[i] + div - 1) / div;

            if(threshold < sum)
                return false;
        }
        return threshold >= sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) { // O(log n)
        int divisor = 0, st = 1, en = *max_element(nums.begin(), nums.end());

        while(st <= en){
            int mid = st + (en - st) / 2;

            if(isValid(nums, mid, threshold))
                en = mid - 1, divisor = mid;
            else
                st = mid + 1;
        }

        return divisor;
    }
};

int main(){
    Solution s;

    vector<int> v1{1,2,5,9};
    cout << s.smallestDivisor(v1, 4) << endl;
    cout << s.smallestDivisor(v1, 5) << endl;
    cout << s.smallestDivisor(v1, 6) << endl;
    cout << s.smallestDivisor(v1, 7) << endl;
    cout << s.smallestDivisor(v1, 8) << endl;
    cout << s.smallestDivisor(v1, 9) << endl;

    return 0;
}
