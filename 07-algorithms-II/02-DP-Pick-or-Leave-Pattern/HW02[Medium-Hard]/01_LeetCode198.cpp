#include<bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX];

vector<int> numbers;

int max_rob(int index){
    if(index >= (int)numbers.size())
        return 0;

    int &ret = memory[index];
    if(ret != -1)
        return ret;

    int skip = max_rob(index + 1); // leave
    int rob = numbers[index] + max_rob(index + 2); // pick

    return ret = max(skip, rob);
}

class Solution {
public:
    int rob(const vector<int>& nums) {
        memset(memory, -1, sizeof(memory));
        numbers = nums;
        return max_rob(0);
    }
};

int main() {
    Solution sol;

    cout << sol.rob({2,7,9,3,1}) << "\n";
    cout << sol.rob({6,1,1,6,7}) << "\n";
    cout << sol.rob({1,2,3,1}) << "\n";

    return 0;
}
