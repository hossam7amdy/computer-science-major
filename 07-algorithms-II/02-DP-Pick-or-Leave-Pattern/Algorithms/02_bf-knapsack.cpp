#include <bits/stdc++.h>
using namespace std;

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MAX = 30;
vector<int> weight = {10, 4 , 6, 5, 1};
vector<int> value = {10, 15, 2 , 8, 2};

int memory[MAX][MAX];
int knapsack(int index, int remaining_weight){
    if(index == (int)weight.size())
        return 0;

    auto &ret = memory[index][remaining_weight];
    if(ret != -1)
        return ret;

    // pick
    int option1 = 0;
    if(remaining_weight >= weight[index])
        option1 = value[index] + knapsack(index + 1, remaining_weight - weight[index]);

    // leave
    int option2 = knapsack(index + 1, remaining_weight);

    // Store & Get best of both
    return ret = max(option1, option2);
}

int main(){
    fast_IO();

    memset(memory, -1, sizeof(memory));

    cout << knapsack(0, 21) << endl; // 35
    cout << knapsack(1, 11) << endl; // 25
    cout << knapsack(2, 7) << endl; // 10
    cout << knapsack(3, 7) << endl; // 10
    cout << knapsack(4, 2) << endl; // 2

    return 0;
}
