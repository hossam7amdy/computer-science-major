// https://leetcode.com/problems/sort-an-array
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> temp;
    void merge(vector<int> &nums, int st, int mid, int en){
        int p1 = st, p2 = mid+1, k = st;
        while(p1 <= mid && p2 <= en){
            if(nums[p1] <= nums[p2])
                temp[k++] = nums[p1++];
            else
                temp[k++] = nums[p2++];
        }
        while(p1 <= mid)
            temp[k++] = nums[p1++];
        while(p2 <= en)
            temp[k++] = nums[p2++];

        while(st <= en)
            nums[st] = temp[st], ++st;
    }

    void mergeSort(vector<int> &nums, int st, int en){
        if(st == en) return;

        int mid = st + (en - st) / 2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, en);

        merge(nums, st, mid, en);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        temp = nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main(){


    return 0;
}
