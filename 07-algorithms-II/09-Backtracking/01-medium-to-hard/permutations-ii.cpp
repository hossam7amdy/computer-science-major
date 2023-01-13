// https://leetcode.com/problems/permutations-ii
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int,int> valueFreq;
    vector<int> nums;

    vector<int> curPerm;
    vector<vector<int>> resPerms;

    void getNextPerm(){
        if(curPerm.size() == nums.size()){
            resPerms.push_back(curPerm);
            return;
        }

        for(auto [value,freq] : valueFreq) if(freq) {
            --valueFreq[value];
            curPerm.push_back(value);

            getNextPerm();

            curPerm.pop_back();
            ++valueFreq[value];
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums_) {
        nums = nums_;

        for(auto num : nums)
            ++valueFreq[num];


        getNextPerm();
        return resPerms;
    }
};

int main() {
    vector<vector<int>> res = Solution().permute({1,3,5,4,2,8,7,6});

    for(auto row : res){
        for(auto val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
