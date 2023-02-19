#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MAX = 2500 + 1;
    int dp[MAX];
public:
    int lengthOfLIS_(vector<int> nums) { // O(n^2)
        nums.push_back(1e4 + 1);
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        int n = (int)nums.size();
        for(int i = 1; i < n; ++i){
            auto &ret = dp[i];
            ret = 1;
            for(int j = i - 1; j >= 0; --j){
                if(nums[i] > nums[j])
                    ret = max(ret, 1 + dp[j]);
            }
        }

        return dp[n-1] - 1;
    }

    int lengthOfLIS(const vector<int>& nums) { // O(nlogn)
        vector<int> dp;
        dp.push_back(nums[0]);

        for(int i = 1; i < (int)nums.size(); ++i){
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }else{
                int best = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[best] = nums[i];
            }
        }
        return (int)dp.size();
    }
};

int main() {

    cout << Solution().lengthOfLIS({10, 20, 7, 9, 1, 15, 25}) << "\n";
    cout << Solution().lengthOfLIS({7,7,7}) << "\n";
    cout << Solution().lengthOfLIS({3,2,1}) << "\n";

    return 0;
}
