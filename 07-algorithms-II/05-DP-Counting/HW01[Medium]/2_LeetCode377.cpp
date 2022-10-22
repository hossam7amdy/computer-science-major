#include<bits/stdc++.h>
using namespace std;

/*

The key difference with coin-change-2 problem, all valid permutations of an answer is counted

The problem, we used to do pick or leave based on the index, but this enforces an ORDER

To handle that, we simply won't send index any more. Inside the DP, we loop on all the choices

 */

const int MAX = 1000 + 1;
int memory[MAX];

vector<int> nums;

int countWays(int remains){
    if(remains < 0)
        return 0;

    if(remains == 0)
        return 1;

    auto &ret = memory[remains];
    if(ret != -1)
        return ret;

    ret = 0;
    for(int i = 0; i < (int)nums.size(); ++i)
        ret += countWays(remains - nums[i]);

    return ret;
}

class Solution {
public:
    int combinationSum4(const vector<int>& nums_, int target) {
        nums = nums_;

        memset(memory, -1, sizeof(memory));
        return countWays(target);
    }
};

int main() {
    Solution sol;

    cout << sol.combinationSum4({1,2,3}, 4) << "\n";
    cout << sol.combinationSum4({9}, 3) << "\n";

    return 0;
}
