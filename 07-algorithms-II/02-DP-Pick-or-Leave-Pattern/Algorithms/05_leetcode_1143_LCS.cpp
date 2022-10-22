#include<bits/stdc++.h>
using namespace std;

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MAX = 1000 + 1;
int memory[MAX][MAX];

string t1,t2;
int LCS(int i, int j){
    if(i == (int)t1.size() || j == (int)t2.size())
        return 0;

    int &ret = memory[i][j];
    if(ret != -1)
        return ret;

    if(t1[i] == t2[j])
        return ret = 1 + LCS(i + 1, j + 1);

    return ret = max(LCS(i + 1, j), LCS(i, j + 1));
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(memory, -1, sizeof(memory));

        t1 = text1;
        t2 = text2;

        return LCS(0,0);
    }
};

int main(){
    fast_IO();

    Solution sol;
    cout << sol.longestCommonSubsequence("pmjghexybyrgzczy", "hafcdqbgncrcbihkd");

    return 0;
}
