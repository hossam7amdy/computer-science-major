#include<bits/stdc++.h>
using namespace std;

/*

Direct Consecutive range pattern
We want to find a good blocks split

dp(idx)
	Try all consecutive ranges as long as total width <= shelfWidth
		For each choice [idx, k] subarray, recurse on the remaining dp(k+1)
		The choice cost is the max height in the subarray [idx, k]

 */

const int MAX = 1000 + 1;
int memory[MAX];

vector<vector<int>> books;
int shelfWidth;

int min_height(int start_idx){ // O(n^2)
    if(start_idx >= (int)books.size())
        return 0;

    auto &ret = memory[start_idx];
    if(ret != -1)
        return ret;

    ret = 1e9;
    int cur_width = 0, cur_height = 0;

    for(int i = start_idx; i < (int)books.size(); ++i){
        if(cur_width + books[i][0] > shelfWidth)
            break;

        cur_width += books[i][0];
        cur_height = max(cur_height, books[i][1]);

        int total_height = cur_height + min_height(i + 1);
        ret = min(ret, total_height);
    }
    return ret;
}

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books_, int shelfWidth_) {
        books = books_;
        shelfWidth = shelfWidth_;

        memset(memory, -1, sizeof(memory));

        return min_height(0);
    }
};

int main(){

    return 0;
}
