#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

const int MAX_N = 30 + 1;
const int MAX_T = 1000 + 1;
int memory[MAX_N][MAX_T];

int dice, faces;

int countWays(int die, int remains) {
    if(remains < 0 || die > dice)
        return 0;

    if(remains == 0 && die == dice)
        return 1;

    auto &ret = memory[die][remains];
    if(ret != -1)
        return ret;

    ret = 0;
    for(int face = 1; face <= faces; ++face){
        ret += countWays(die + 1, remains - face);
        ret %= MOD;
    }

    return ret;
}


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        dice = n, faces = k;
        memset(memory, -1, sizeof(memory));

        return countWays(0, target);
    }
};

int main() {
    Solution sol;

    cout << sol.numRollsToTarget(1,6,3) << "\n";
    cout << sol.numRollsToTarget(2,6,7) << "\n";
    cout << sol.numRollsToTarget(30, 30, 500) << "\n";

    return 0;
}
