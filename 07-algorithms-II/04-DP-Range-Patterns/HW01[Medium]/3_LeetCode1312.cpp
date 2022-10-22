#include<bits/stdc++.h>
using namespace std;

const int MAX = 500 + 1;
int memory[MAX][MAX];

string str;
int makePalindrome(int start_idx, int end_idx){ // O(n^2)
    if(start_idx >= end_idx)
        return 0;

    auto &ret = memory[start_idx][end_idx];
    if(ret != -1)
        return ret;

    if(str[start_idx] == str[end_idx])
        return makePalindrome(start_idx + 1, end_idx - 1);

    int left = makePalindrome(start_idx, end_idx - 1);
    int right = makePalindrome(start_idx + 1, end_idx);

    return ret = 1 + min(left, right);
}

class Solution {
public:
    int minInsertions(string s) {
        str = s;

        memset(memory, -1, sizeof(memory));
        return makePalindrome(0, (int)s.size() - 1);
    }
};

int main(){
    Solution sol;

    cout << sol.minInsertions("zzazz") << "\n";
    cout << sol.minInsertions("mbadm") << "\n";
    cout << sol.minInsertions("leetcode") << "\n";

    return 0;
}
