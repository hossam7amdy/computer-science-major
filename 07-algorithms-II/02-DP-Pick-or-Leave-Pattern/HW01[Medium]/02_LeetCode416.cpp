#include <bits/stdc++.h>
using namespace std;

/*
- Observe: the sum of the values must be even, otherwise no way to split
- Assume the sum is 20. This means we need 2 groups each is sum to 10
- Then, if we can find a group, this implies there is another group
- Which is a simple problem, the subset sum problem!
- Reductions is a great tool in solving hard problems
 */

const int MAX_N = 200;
const int MAX_R = (200 * 100 / 2) + 1; // maximum possible sum divided by 2;
int memory[MAX_N][MAX_R];

vector<int> numbers;

bool can_partition_sum(int idx, int remains){
    if(remains == 0)
        return true;

    if(remains < 0)
        return false;

    if(idx == (int)numbers.size())
        return 0;

    auto &ret = memory[idx][remains];
    if(ret != -1)
        return ret;

    if(can_partition_sum(idx + 1, remains))
        return ret = true;

    return ret = can_partition_sum(idx + 1, remains - numbers[idx]);
}

class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        int sum_of_elems = accumulate(nums.begin(), nums.end(), 0);

        if(sum_of_elems % 2 != 0)
            return false;

        numbers = nums;
        memset(memory, -1, sizeof(memory));
        return can_partition_sum(0, sum_of_elems / 2);
    }
};


int main(){
    Solution sol;

    cout << sol.canPartition({100,100,100,100,100,100,100,100}) << "\n";

    return 0;
}
