#include<bits/stdc++.h>
using namespace std;

const int MAX = 100 + 2 + 1; // 2 for two extra values we add
int memory[MAX][MAX];

int n;
vector<int> cuts;

// Find the best cut in this sorted range, exclusively
int best_cut(int i, int j){ // O(N^3) time
    if(i + 1 == j)
        return 0;

    auto &ret = memory[i][j];
    if(ret != -1)
        return ret;

    ret = 1e9;
    for(int k = i + 1; k < j; ++k){
        int left = best_cut(i, k);
        int right = best_cut(k, j);

        int cut_cost = cuts[j] - cuts[i];
        ret = min(ret, left + right + cut_cost);
    }

    return ret;
}

class Solution {
public:
    int minCost(int n_, const vector<int>& cuts_) {
        n = n_;
        cuts = cuts_;

        cuts.push_back(0);
		cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        memset(memory, -1, sizeof(memory));
        return best_cut(0 , (int)cuts.size() - 1);
    }
};

int main(){
    Solution sol;

    cout << sol.minCost(7, {1,3,4,5}) << "\n";
    cout << sol.minCost(9, {5,6,1,4,2}) << "\n";

    return 0;
}
