#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX];

vector<vector<int>> boxes;

bool operator <= (const vector<int> &b1, const vector<int> &b2){
    return b1[1] <= b2[1] && b1[2] <= b2[2];
}

int max_height(int i){
    if(i == (int)boxes.size())
        return 0;

    auto &ret = memory[i];
    if(ret)
        return ret;

    for(int j = i + 1; j < (int)boxes.size(); ++j) // pick (valid only)
        if(boxes[i] <= boxes[j])
            ret = max(ret, max_height(j));

    ret += boxes[i][2];
    return ret;
}

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {

		// Given that we can rearrange the data,
		// then we better sort from large to small
		// then observe, the longest decreasing sequence
		// is actually the answer
		// For simplicity, sort small to large and use LIS

        for(auto &c : cuboids)
            sort(c.begin(), c.end());

        sort(cuboids.begin(), cuboids.end());

        boxes = cuboids;
        boxes.insert(boxes.begin(), {0,0,0}); // dummy
        memset(memory, 0, sizeof(memory));
        return max_height(0);
    }
};

int main(){
    Solution sol;

    vector<vector<int>> test = {{50,45,20},{95,37,53},{45,23,12}};
    cout << sol.maxHeight(test) << "\n";

    return 0;
}
