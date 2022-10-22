// https://leetcode.com/problems/edit-distance/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 500 + 1;
int memory[MAX][MAX];

string str1, str2;
int edit_dist(int i, int j){
    if(i == -1 || j == -1)
        return max(i, j) + 1;

    auto &ret = memory[i][j];
    if(ret != -1)
        return ret;

    if(str1[i] == str2[j])
        return ret = edit_dist(i - 1, j - 1);

    int change  = 1 + edit_dist(i - 1, j - 1);
    int insert_ = 1 + edit_dist(i - 1, j);
    int delete_ = 1 + edit_dist(i,     j - 1);

    return ret = min(insert_ , min(delete_, change));
}

class Solution {
public:
    int minDistance(string word1, string word2) { // O(n^2)
        str1 = word1, str2 = word2;

        memset(memory, -1, sizeof(memory));

        return edit_dist((int)str1.size() - 1, (int)str2.size() - 1);
    }
};

int main(){
    Solution sol;
    cout << sol.minDistance("horse", "ros") << "\n";
    cout << sol.minDistance("intention", "execution") << "\n";

    return 0;
}
