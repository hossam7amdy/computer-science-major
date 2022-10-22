#include<iostream>
#include<set>
#include<vector>
using namespace std;


// My direct solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sum = 0;
        if(!(int)nums.size())
            return sum;

        sort(nums.begin(), nums.end());

        int sub_seq = 1;
        for(int i = 1; i < (int)nums.size(); ++i){
            if(nums[i] == nums[i-1]) continue;

            if(nums[i] - nums[i-1] == 1){
                ++sub_seq;
                continue;
            }

            sum = max(sum, sub_seq);
            sub_seq = 1;
        }

        sum = max(sum, sub_seq);
        return sum;
    }
};

int main(){
    vector<int> t1 {100,4,200,1,3,2};
    vector<int> t2 {0,3,7,2,5,8,4,6,0,1};

    Solution s;
    cout << s.longestConsecutive(t1) << endl;
    cout << s.longestConsecutive(t2) << endl;

    return 0;
}
