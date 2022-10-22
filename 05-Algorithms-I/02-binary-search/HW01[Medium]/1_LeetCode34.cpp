#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    /// My Implementation ///
    int lower(vector<int> &nums, int target){
        int st = 0, en = (int)nums.size() - 1;

        while(st <= en){
            int mid = st + (en - st) / 2;

            if(nums[mid] > target)
                en = mid - 1;
            else if(nums[mid] < target)
                st = mid + 1;
            else{
                if(mid == 0 || nums[mid - 1] != target)
                    return mid;
                en = mid - 1;
            }
        }
        return -1;
    }
    int upper(vector<int> &nums, int target){
        int st = 0, en = (int)nums.size() - 1;

        while(st <= en){
            int mid = st + (en - st) / 2;

            if(nums[mid] < target)
                st = mid + 1;
            else if(nums[mid] > target)
                en = mid - 1;
            else{
                if(mid == (int)nums.size() - 1 || nums[mid + 1] != target)
                    return mid;
                st = mid + 1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower(nums, target), upper(nums, target)};
    }

    /// Using STL ///
    vector<int> searchRangeSTL(vector<int>& nums, int target) {
        auto p = equal_range(nums.begin(), nums.end(), target);

        if(p.first == nums.end())
            return {-1, -1};

        int lo = p.first - nums.begin();
        int up = p.second - nums.begin();

        if(nums[lo] != target)
            return {-1, -1};

        return {lo, up - 1};
    }
};

int main(){
    vector<int> v{1,2,4,4,4,5};

    Solution s;
    vector<int> res = s.searchRangeSTL(v, 4);

    for(const auto &val : res)
        cout << val << " ";

    return 0;
}
