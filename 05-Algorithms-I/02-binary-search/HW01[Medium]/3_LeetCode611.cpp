#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    /// My Implementation ///
    int BSfindFirst(vector<int> &nums, int st, int target){
        int en = (int)nums.size() - 1;
        int position = nums.size(); // assume: all is valid

        while(st <= en){
            int mid = st + (en - st) / 2;

            if(nums[mid] < target)
                st = mid + 1;
            else
                en = mid - 1, position = mid;
        }
        return position;
    }

    int triangleNumber(vector<int>& nums) {
        int sz = (int)nums.size(), sum = 0;

        if(sz < 3)
            return sum;

        sort(nums.begin(), nums.end());

        for(int i = 0; i + 2 < sz; ++i){
            for(int j = i + 1; j + 1 < sz; ++j){
                int idx_first = BSfindFirst(nums, j + 1, nums[i]+nums[j]);

                sum += idx_first - j - 1;
            }
        }

        return sum;
    }

    /// Using STL ///
    int triangleNumberSTL(vector<int>& nums) {
        int sz = (int)nums.size(), sum = 0;

        if(sz < 3)
            return sum;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < sz; ++i){
            for(int j = i + 1; j < sz; ++j){
                auto first_occur = lower_bound(nums.begin()+j+1, nums.end(), nums[i]+nums[j]);

                sum += (first_occur - nums.begin()) - j - 1;
            }
        }

        return sum;
    }
};

int main(){
    //freopen ("myfile.txt","w",stdout);
    //for(int i=1; i<1001; ++i)
      //  cout << i << ",";

    vector<int> v{2,2,3,4};
    Solution s;
    cout << s.triangleNumber(v) << endl;

    return 0;
}
