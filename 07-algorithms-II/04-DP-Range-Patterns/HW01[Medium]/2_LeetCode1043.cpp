#include<bits/stdc++.h>
using namespace std;

/*

Direct consecutive range problem like pearls problem we solved.

The only changes:
- The subarray equation is: length x max
- The subarray's length maximum is k
 */

const int MAX = 500 + 1;
int memory[MAX];

vector<int> arr;
int k;

int partitioning(int start_idx){ // O(n^2)
    if(start_idx == (int)arr.size())
        return 0;

    auto &ret = memory[start_idx];
    if(ret != -1)
        return ret;

    int max_ele = 0, cur_partition = 0;
    for(int end_block = start_idx; end_block < (int)arr.size() && end_block - start_idx < k; ++end_block){
        max_ele = max(max_ele, arr[end_block]);

        int len = end_block - start_idx + 1;
        ret = max(ret, max_ele * len + partitioning(end_block + 1));
    }
    return ret;
}

class Solution {
public:
    int maxSumAfterPartitioning(const vector<int>& arr_, int k_) {
        k = k_;
        arr = arr_;
        memset(memory, -1, sizeof(memory));

        return partitioning(0);
    }
};

int main() {
    Solution sol;

    cout << sol.maxSumAfterPartitioning({1,15,7,9,2,5,10}, 3) << "\n";
    cout << sol.maxSumAfterPartitioning({1,4,1,5,7,3,6,1,9,9,3}, 4) << "\n";

    return 0;
}
