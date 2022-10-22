#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
   vector<int> max_vals;
   multiset<int> ms;
   for(int i=0; i<k; i++){
        ms.insert(nums[i]);
   }
   max_vals.push_back(*ms.rbegin());
   int sz = (int)nums.size();
   for(int i=k; i<sz; i++){
        ms.erase(ms.find(nums[i-k]));
        ms.insert(nums[i]);
        max_vals.push_back(*ms.rbegin());
   }
   return max_vals;
}


int main(){
    vector<int> nums{4,-2}; //1,3,-1,-3,5,3,6,7
    int k;
    cin >> k;
    vector<int> max_vals = maxSlidingWindow(nums, k);
    for(auto ele : max_vals)
        cout << ele << " ";

    return 0;
}
