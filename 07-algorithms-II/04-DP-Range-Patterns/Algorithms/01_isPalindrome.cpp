// https://leetcode.com/problems/longest-palindromic-substring/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
short memory[MAX][MAX];

string str;
int isPalindrome(int st, int en){
    if(st >= en)
        return 1;

    auto &ret = memory[st][en];
    if(ret != -1)
        return ret;

    if(str[st] != str[en])
        return 0;

    return ret = isPalindrome(st + 1, en - 1);
}

class Solution {
public:
    string longestPalindrome(string s) { // O(n^2)
        memset(memory, -1, sizeof(memory));

        str = s;
        int sz = (int)s.size();
        int st = 0, len = 0;

        for(int i = 0; i < sz; ++i)
            for(int j = i; j < sz; ++j)
                if(isPalindrome(i,j) && j - i > len)
                    st = i, len = j - i;

        return s.substr(st, len + 1);
    }
};

int main(){
    Solution sol;

    cout << sol.longestPalindrome("aacabdkacaa") << "\n";
    cout << sol.longestPalindrome("cbbd") << "\n";
    cout << sol.longestPalindrome("aababa") << "\n";

    return 0;
}
