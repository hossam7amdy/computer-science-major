#include <bits/stdc++.h>
using namespace std;

vector<int> seq;
const int MAX = 2500 + 1;
int memory[MAX];

int LIS(int i){
    if(i == (int)seq.size())
        return 0;

    auto &ret = memory[i];
    if(ret != -1)
        return ret;

    ret = 0; // maximize among all valid choices
    for(int j = i + 1; j < (int)seq.size(); ++j)
        if(seq[i] < seq[j])
            ret =  max(ret, LIS(j)); // choose only valid jth after ith

    ret += 1; // add ith position
    return ret;
}

class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) { // O(n^2)
        memset(memory, -1, sizeof(memory));
        seq = nums;

        // We can do simple workarounds to remove the loop
        seq.insert(seq.begin(), -1e9);

        return LIS(0) - 1; // remove dummy value
    }

    int lengthOfLIS_(const vector<int>& nums) { // O(n^2)
        memset(memory, -1, sizeof(memory));
        seq = nums;

        int res = 0;
        for(int j = 0; j < (int)nums.size(); ++j){
            int start = LIS(j);
            res = max(res, start);
        }

        return res;
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
