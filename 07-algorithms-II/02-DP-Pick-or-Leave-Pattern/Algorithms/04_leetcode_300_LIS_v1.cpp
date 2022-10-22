#include <bits/stdc++.h>
using namespace std;

vector<int> seq;
const int MAX = 2500 + 1;
int memory[MAX][MAX];

int LIS(int cur, int prev){
    if(cur == (int)seq.size())
        return 0;

    auto &ret = memory[cur][prev];
    if(ret != -1)
        return ret;

    // pick
    int option1 = 0;
    if(prev >= (int)seq.size() || seq[prev] < seq[cur])
        option1 = 1 + LIS(cur + 1, cur);

    // leave
    int option2 = LIS(cur + 1, prev);

    return ret = max(option1, option2);
}

class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) { // O(n^2)
        seq = nums;

        memset(memory, -1, sizeof(memory));
        return LIS(0, (int)seq.size());
    }
};

int main(){
    Solution sol;

    cout << sol.lengthOfLIS({7,7,7,7,7,7,7}) << "\n"; // 1
    cout << sol.lengthOfLIS({0,1,0,3,2,3}) << "\n"; // 4
    cout << sol.lengthOfLIS({10,9,2,5,3,7,101,18}) << "\n"; // 4
    cout << sol.lengthOfLIS({0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}) << "\n"; // 6

    return 0;
}
