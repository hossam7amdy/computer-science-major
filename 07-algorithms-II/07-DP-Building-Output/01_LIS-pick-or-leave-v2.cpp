#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 + 1;
int memo[MAX];

vector<int> numList;

// find next position pattern
int LIS(int idx){
    int &ret = memo[idx];
    if(ret != -1)
        return ret;

    ret = 0; // new start
    for(int i = idx + 1; i < (int)numList.size(); ++i){
        if(numList[idx] < numList[i])
            ret = max(ret, LIS(i));
    }

    ret += 1; // update reference memory
    return ret;
}

void LIS_print(int idx){
    if(idx) // don't print dummy value
        cout << numList[idx] << " ";

    int optimal = LIS(idx);
    for(int i = 0; i < MAX; ++i){
        if(optimal == 1 + LIS(i)){
            LIS_print(i);
            return;
        }
    }
}

int lengthOfLIS(const vector<int> &nums) {
    memset(memo, -1, sizeof(memo));
    numList = nums;

    // 1- enforce the first element and remove the loop
    numList.insert(numList.begin(), INT_MIN);
    int ans = LIS(0) - 1; // 2- remove it from the answer

    LIS_print(0);
    cout << "\n";

    return ans;
}

int main() {
    lengthOfLIS({10,9,2,5,3,7,101,18});
    lengthOfLIS({1,2,3});
    lengthOfLIS({3,5,6,2,5,4,19,5,6,7,12});

    return 0;
}
