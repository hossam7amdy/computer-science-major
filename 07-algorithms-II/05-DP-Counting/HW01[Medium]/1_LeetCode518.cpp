#include<bits/stdc++.h>
using namespace std;

/*

Similar to subset sum, we have index and target
	If we don't take item, we move to next with same target
	If we take item, we move to next and subtract from the target

But wait, we want to take the same item several times?
There are 2 approaches:
A) Make an internal loop and keep subtract as much as possible

B) Smart approach: just recurse on the same INDEX again
	Then again it applies leave or take

	Be careful from infinite loops
		As each amount >= 1, we will always move to a smaller state

*/

const int MAX_N = 300 + 1;
const int MAX_T = 5000 + 1;
int memory[MAX_N][MAX_T];

int amount;
vector<int> coins;

int countWays(int idx, int remains){
    if(remains < 0)
        return 0;

    if(remains == 0)
        return 1;

    if(idx == (int)coins.size())
        return 0;

    auto &ret = memory[idx][remains];
    if(ret != -1)
        return ret;

    int take = countWays(idx, remains - coins[idx]);
    int leave = countWays(idx + 1, remains);
    return ret = take + leave;
}

class Solution {
public:
    int change(int amount_, const vector<int>& coins_) {
        coins = coins_;
        amount = amount_;

        memset(memory, -1, sizeof(memory));
        return countWays(0, amount);
    }
};

int main() {
    Solution sol;

    cout << sol.change(5,{1,2,5}) << "\n";
    cout << sol.change(2,{3}) << "\n";
    cout << sol.change(10,{10}) << "\n";

    return 0;
}
