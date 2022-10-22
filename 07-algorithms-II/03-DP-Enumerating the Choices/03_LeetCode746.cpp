#include<bits/stdc++.h>
using namespace std;

int const MAX = 1000 + 1;
int memory[MAX];

vector<int> costVec;
int minCost(int idx) {
    if(idx >= (int)costVec.size())
        return 0;

    auto &ret = memory[idx];
    if(ret != -1)
        return ret;

    int pickNext = costVec[idx] + minCost(idx + 1);
    int skipNext = costVec[idx] + minCost(idx + 2);

    return ret = min(pickNext, skipNext);
}

class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        costVec = cost;
        memset(memory, -1, sizeof(memory));

        return min(minCost(0), minCost(1));
    }
};

int main(){
    Solution sol;

    cout << sol.minCostClimbingStairs({10,15,20}) << "\n"; // 15
    cout << sol.minCostClimbingStairs({1,100,1,1,1,100,1,1,100,1}) << "\n"; // 6

    return 0;
}
