#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 300 + 1;
const int MAX_AMOUNT = 5000 + 1;

int dp[MAX_LEN][MAX_AMOUNT];

int answer(int idx, int target){
    if(target < 0)
        return 0;

    if(target == 0)
        return 1;

    if(idx == -1)
        return 0;

    return dp[idx][target];
}

int change(int amount, const vector<int>& coins) {
    int n = (int)coins.size();
    memset(dp, 0, sizeof(dp));

    for(int idx = 0; idx < n; ++idx){
        for(int target = 0; target <= amount; ++target){

            int leave = answer(idx + 1, amount);
            int take = answer(idx, amount - coins[target]);

            dp[idx][target] = leave + take;
        }
    }

    return dp[n-1][amount];
}

int main() {
    cout << change(5, {1,2,3}) << "\n";

    return 0;
}
