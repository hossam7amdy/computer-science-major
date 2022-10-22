#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // nlog(n)

    int sum{};
    for(int i=(int)nums.size()-1; i>0; i-=2) // O(n)
        sum += nums[i-1]; // first pair element

    return sum;
}

int main(){
    vector<int> v{1,4,3,2};
    cout << arrayPairSum(v) << endl;

    return 0;
}
