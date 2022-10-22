#include <bits/stdc++.h>
using namespace std;

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<int> weight, value;
const int MAX = 2000 + 1;
int memory[MAX][MAX];

int knapsack(int idx, int remains){
    if(idx == (int)weight.size())
        return 0;

    auto &ret = memory[idx][remains];
    if(ret != -1)
        return ret;

    // leave
    int choice1 = knapsack(idx + 1, remains);
    int choice2 = 0;

    // pick
    if(remains >= weight[idx])
        choice2 = value[idx] + knapsack(idx + 1, remains - weight[idx]);

    return ret = max(choice1, choice2);
}

int main(){
    fast_IO();

    int max_weight, n;
    cin >> max_weight >> n;

    weight.resize(n);
    value.resize(n);

    for(int i = 0; i < n; ++i)
        cin >> weight[i] >> value[i];

    // Memoization approach O(nw)
    memset(memory, -1, sizeof(memory));

    cout << knapsack(0, max_weight) << "\n";

    return 0;
}
