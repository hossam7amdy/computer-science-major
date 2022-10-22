#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// A triangle is valid if:
    // A + B > C &&  B + C > A && C + A > B

int largestPerimeter(vector<int>& nums) {

    sort(nums.rbegin(), nums.rend()); // nlog(n)

    for(int i=1; i < (int) nums.size() - 1; ++i){ // O(n)
        int a{ nums[i-1] }, b{ nums[i] }, c{ nums[i+1] };

        if(a+b>c && b+c>a && c+a>b)

            return a + b + c;
    }
    return 0;
}

int main(){
    /*
    [2,1,2]
    [1,2,1]
    [3,2,3,4]
    [3,6,2,3]
    [6, 6, 6, 6, 6, 3, 3, 3, 3, 3]
    [2,6,2,5,4,15,1]
    */

    vector<int> v{2,6,2,5,4,15,1};
    cout << largestPerimeter(v) << endl;

    return 0;
}
