#include<iostream>
#include<vector>
using namespace std;

/// p2
vector<int> sortArray(vector<int>& nums){ // time O(n+k) - memory O(k)
    int n = 100001, shift{50000};
    vector<int> freq(n);
    for(int i=0; i<(int)nums.size(); ++i)
        freq[nums[i] + shift]++;

    int idx{};
    for(int i=0; i < n; ++i)
        while(freq[i]--)
            nums[idx++] = i - shift;

    return nums;
}

/// p3
vector<int> sortArray_v2(vector<int>& nums){ // time O(n+k) - memory O(k)
    int n = { 100001 }, shift{nums[0]};
    for(int i=1; i<(int)nums.size(); ++i)
        shift = max(shift, nums[i]);

    vector<int> freq(n);
    for(int i=0; i<(int)nums.size(); ++i)
        freq[shift - nums[i]]++;

    int idx{};
    for(int i=n-1; i >= 0; --i) // stored reversed
        while(freq[i]--)
            nums[idx++] = shift - i;

    return nums;
}

vector<int> sortArray_v2_refined(vector<int>& nums){ // time O(n+k) - memory O(k)

    int mxValue{nums[0]}, mnValue{nums[0]};

    for(int i=1; i<(int)nums.size(); ++i){
        mxValue = max(mxValue, nums[i]);
        mnValue = min(mnValue, nums[i]);
    }

    int new_max = mxValue - mnValue;
    vector<int> freq(new_max+1);
    for(int i=0; i<(int)nums.size(); ++i)
        freq[nums[i] - mnValue]++;

    int idx{};
    for(int i=0; i < (int)freq.size(); ++i)
        while(freq[i]--)
            nums[idx++] = i + mnValue;

    return nums;
}

int main(){
    vector<int> v{3,2,1,0,-3,-2,-1};
    sortArray_v2(v);

    for(const auto &item : v)
        cout << item << " ";

    return 0;
}
