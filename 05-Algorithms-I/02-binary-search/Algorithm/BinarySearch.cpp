#include<iostream>
#include<vector>
using namespace std;

int Search(const vector<int>& nums, int target) { // O(Log n)
    int st = 0, en = (int)nums.size() - 1;

    while(st <= en){
        int mid = st + (en - st)/2;
        cout << mid << " "; // max search jumps = 4
        if(target == nums[mid]) return mid;

        if(nums[mid] < target)
            st = mid + 1;
        else
            en = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> v{0, 5, 13, 19, 22, 41, 55, 68, 72, 81, 98};

    cout << Search(v, 0) << endl;
    cout << Search(v, 98) << endl;
    cout << Search(v, 13) << endl;
    cout << Search(v, 81) << endl;
    cout << Search(v, 55) << endl;
    cout << Search(v, -10) << endl;
    cout << Search(v, 100) << endl;

    return 0;
}
