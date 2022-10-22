#include<bits/stdc++.h>
using namespace std;

/*

The first impression, this is nested ranges as MCM problem.
	We can see how we have a group that splits to group that splits to groups etc

This is true, but we can't implement efficiently
	Assume we have values like: 1, 3, 5, 7, 9, 11, 13
	We want to remove 5. Now 3 and 7 should be neighbors!
	More wose; we can't define 2 separate DP problems; actually still one, of smaller size

The critical observation is instead of forward simulation of the first balloon to select
	We think what is the last balloon to select (backward thinking)
	Why? Assume 7 is the last balloon
		Then we literally have 2 completely separate problems
			1, 3, 5, 7  and 7, 9, 11, 13  where no neighbors problems


When comes to implementation; we need to be careful!
	No one ever reuse our last balloon

Let dp(start_idx, end_idx)
	is balloon range: start_idx-1, start_idx, start_idx+1, ....., end_idx-1, end_idx

	In other words, the value before and value after are part of the range
	BUT marked as LAST baloons

For easier coding, change the input array by adding number before and after
	[3, 6, 2, 8] ==> [1, 3, 6, 2, 8, 1]

Overall, the code is very similar to MCM

 */


const int MAX = 300 + 2 + 1;
int memory[MAX][MAX];

vector<int> nums;

int best_cost(int start_idx, int end_idx){  // O(N^3) time
    if(start_idx > end_idx)
        return 0;

    auto &ret = memory[start_idx][end_idx];
    if(ret != -1)
        return ret;

    for(int k = start_idx; k <= end_idx; ++k){
        int cost = nums[start_idx - 1] * nums[k] * nums[end_idx + 1];
        // Now K should be fixed and next sub-calls don't use our LAST baloon
        int sub1 = best_cost(start_idx, k - 1);
        int sub2 = best_cost(k + 1, end_idx);

        ret = max(ret, cost + sub1 + sub2);
    }

    return ret;
}

class Solution {
public:
    int maxCoins(const vector<int>& nums_) {
        nums = nums_;

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(memory, -1, sizeof(memory));
        return best_cost(1, (int)nums.size() - 2);
    }
};


int main(){
    Solution sol;

    cout << sol.maxCoins({3,1,5,8}) << "\n";

    return 0;
}
