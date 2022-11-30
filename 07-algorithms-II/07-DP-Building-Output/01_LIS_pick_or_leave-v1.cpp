#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 + 1;
int memo[MAX][MAX];

vector<int> numList;

// pick or leave pattern
int LIS(int cur, int prev){
    if(cur == (int)numList.size())
        return 0;

    int &ret = memo[cur][prev];
    if(ret != -1)
        return ret;

    int pick = 0;
    if(prev >= (int)numList.size() || numList[cur] > numList[prev])
        pick = 1 + LIS(cur + 1, cur);

    int leave = LIS(cur + 1, prev);

    return ret = max(pick, leave);
}

void LIS_print(int cur, int prev){
    if(cur == (int)numList.size())
        return;

    int optimal = LIS(cur, prev);

    int pick = 0;
    if((int)numList.size() || numList[cur] > numList[prev])
        pick = 1 + LIS(cur + 1, cur);

    int leave = LIS(cur + 1, prev);

    if(optimal == pick){
        cout << numList[cur] << " ";
        LIS_print(cur + 1, cur);
    }else {
        LIS_print(cur + 1, prev);
    }
}

int lengthOfLIS(const vector<int> &nums) {
    memset(memo, -1, sizeof(memo));
    numList = nums;

    int ans = LIS(0, (int)numList.size());
    LIS_print(0, (int)numList.size());
    cout << "\n";
    return ans;
}

int main() {
    lengthOfLIS({10,9,2,5,3,7,101,18});
    lengthOfLIS({1,2,3});
    lengthOfLIS({3,5,6,2,5,4,19,5,6,7,12});

    return 0;
}

