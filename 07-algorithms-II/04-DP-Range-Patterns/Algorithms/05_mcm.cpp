#include<bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX][MAX];

vector<int> rows, cols;

int mcm(int start_idx, int end_idx){ // O(n^2)
    if(start_idx == end_idx)
        return 0;

    auto &ret = memory[start_idx][end_idx];
    if(ret != -1)
        return ret;

    ret = 1e9;
    for(int k = start_idx; k < end_idx; ++k){
        int cost = rows[start_idx] * cols[k] * cols[end_idx];
        int sub1 = mcm(start_idx, k);
        int sub2 = mcm(k + 1, end_idx);
        int total_k = cost + sub1 + sub2;

        ret = min(ret, total_k);
    }

    return ret;
}

int pre(const vector<vector<int>> &matrix){
    int n = (int)matrix.size();
    rows.resize(n);
    cols.resize(n);

    for(int i = 0; i < n; ++i)
        rows[i] = matrix[i][0], cols[i] = matrix[i][1];

    memset(memory, -1, sizeof(memory));
    return mcm(0, n - 1);
}

int main(){
    cout << pre({ {1, 2}, {2, 3}, {3, 4} }) << "\n";
    cout << pre({ {5, 10}, {10, 19}, {19, 7} }) << "\n";

    return 0;
}
