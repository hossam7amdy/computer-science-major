// https://leetcode.com/problems/decode-ways/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX];

string str;

bool isValid(int idx){
    if(idx + 1 >= (int)str.size())
        return false;

    int num = stoi(str.substr(idx, 2));
    return 1 <= num && num <= 26;
}

int count(int idx){
    if(idx >= (int)str.size())
        return 1;

    if(str[idx] == '0')
        return 0;

    auto &ret = memory[idx];
    if(ret != -1)
        return ret;

    ret = count(idx + 1);

    if(isValid(idx))
        ret += count(idx + 2);

    return ret;
}

class Solution {
public:
    int numDecodings(string s) {
        str = s;

        memset(memory, -1, sizeof(memory));
        return count(0);
    }
};

int main(){
    Solution sol;

    cout << sol.numDecodings("12") << "\n";
    cout << sol.numDecodings("226") << "\n";

    return 0;
}
