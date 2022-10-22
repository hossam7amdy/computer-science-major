#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
- Case 1) Assume that all the array values >= 0
- Case 2) Assume that some of the values are negative
*/

int largestSumAfterKNegations_v1(vector<int>& nums, int k) { // nlog(n)
    sort(nums.begin(), nums.end());

    for(int i=0; i<(int)nums.size() && k > 0; ++i, --k){
        if(nums[i] < 0)
            nums[i] = -nums[i];
        else if(nums[i] > 0 && i)
            return largestSumAfterKNegations_v1(nums, k);
        else{
            if(k%2!=0)
                nums[i] = -nums[i];
            k = 0;
            break;
        }
    }
    if(k)
        return largestSumAfterKNegations_v1(nums, k);

    int sum{};
    for(int i=0; i<(int)nums.size(); ++i)
        sum += nums[i];

    return sum;
}

// shorter and smarter
int largestSumAfterKNegations(vector<int>& nums, int k) { // nlog(n)
    sort(nums.begin(), nums.end());

    int mn{ INT_MAX }, sum{};
    for(int i=0; i<(int)nums.size(); ++i){
        if(nums[i] < 0 && k > 0)
            --k, nums[i] = -nums[i];

        sum += nums[i];
        mn = min(mn, nums[i]);
    }

    if(k % 2)
        sum -= 2 * mn;

    return sum;
}

int main(){
    vector<int> v1{-4,2,-3},  v2{3,-4,0,2}, v3{-4, -3, -2};

    cout << largestSumAfterKNegations(v1,5) << endl;
    cout << largestSumAfterKNegations(v2,3) << endl;
    cout << largestSumAfterKNegations(v3,4) << endl;

    return 0;
}

