#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
 * This is a greedy algorithm :)
 * 		It involves smart decisions that convert the problem to a sub-problem
 */

void wiggleSort(vector<int> &nums){
    sort(nums.begin(), nums.end()); // time nlog(n)

    const int sz {(int)nums.size()};
    vector<int> ans(sz); // O(n) space

    int steps{};
    for(int i=0; i<sz; ++i){
        if(i%2==0)
            ans[i] = nums[steps];
        else{
            ++steps;
            ans[i] = nums[sz-steps];
        }
    }
    nums = ans;
}


//
void wiggleSort_v2(vector<int> &nums){ // time nlog(n) - space O(1)
    sort(nums.begin(), nums.end());

    for(int i=1; i + 1 < (int)nums.size(); i+=2)
        swap(nums[i], nums[i + 1]);
}

int main(){
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    wiggleSort(v);

    for(const auto &item : v)
        cout << item << " ";

    return 0;
}
