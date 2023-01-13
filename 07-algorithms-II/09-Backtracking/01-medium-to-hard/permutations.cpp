// https://leetcode.com/problems/permutations/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nums;
    bool exist[20 + 1];
    vector<int> curPerm;
    vector<vector<int>> resPerms;

    void getPerm(){
        if(curPerm.size() == nums.size()){
            resPerms.push_back(curPerm);
            return;
        }

        for(auto num : nums){
            if(!exist[num + 10]){
                exist[num + 10] = 1;
                curPerm.push_back(num);

                getPerm();

                curPerm.pop_back();
                exist[num + 10] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(const vector<int>& nums_) {
        nums = nums_;
        memset(exist, 0, sizeof(exist));

        getPerm();
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
