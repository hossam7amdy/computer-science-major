#include<bits/stdc++.h>
using namespace std;

/*

 Let's define cnt_trees(x): Return how many trees that has x as a root

 Then the answer is: the sum for all cnt_trees(x) for the input values

 Assume we have number like 12
 we know 12 = 1 * 12 = 2 * 6 = 3 * 4

 If we know that there are say 10 ways for F(3) and 20 ways for F(4)
 then we have F(3) * F(4) ways to make 12

 So the key idea is
 Find all pairs a, b such that x = a * b
 then accumulate F(a) * F(b)
 */

class Solution {
    const int MOD = 1e9 + 7;

    unordered_set<int> nums;
    unordered_map<int, int> memory;

    // Return how many trees that has x as a root
    long long cnt_trees(int x){ // O(N^2) where N is input array size
        if(memory.count(x))
            return memory[x];

        int cnt = 1;  // use as a leaf

        // Find all my divisors x = a * b, then F(a) * F(b) are possible solutions
        for(auto item : nums){
            if(x % item == 0 && nums.count(x / item)){
                auto sub_tree = (cnt_trees(item) * cnt_trees(x / item)) % MOD;
                cnt += sub_tree;
                cnt %= MOD;
            }
        }

        return memory[x] = cnt;
    }

public:
    int numFactoredBinaryTrees(const vector<int>& arr) {
        nums.insert(arr.begin(), arr.end());

        int ans = 0;
        for(auto root : arr){
            ans += cnt_trees(root);
            ans %= MOD;
        }

        return ans % MOD;
    }
};

int main() {
    Solution sol;

    cout << sol.numFactoredBinaryTrees({1000000000,100000000,500000,5000000}) << "\n";
    cout << sol.numFactoredBinaryTrees({15,13,22,7,11}) << "\n";

    return 0;
}
