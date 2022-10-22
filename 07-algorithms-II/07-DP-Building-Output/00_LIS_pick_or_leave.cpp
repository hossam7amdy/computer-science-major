#include <bits/stdc++.h>
using namespace std;

int const MAX = 15 + 1;
int memory[MAX][MAX];

vector<int> numList;

/*
10, 9, 2, 5, 3, 7, 100, 18

10 100
10 18

9 100
9 18

2 5 7 100
2 5 7 18
2 3 7 100
2 3 7 18

5 7 100
5 7 18

3 7 100
3 7 18

7 100
7 18

100

18
*/

int LIS(int cur, int prev){
    if(cur == (int)numList.size())
        return 0;

    auto &ret = memory[cur][prev];
    if(ret != -1)
        return ret;

    int pick = 0;
    if(prev == (int)numList.size() || numList[prev] < numList[cur])
        pick = 1 + LIS(cur + 1, cur);

    int leave = LIS(cur + 1, prev);

    return ret = max(pick, leave);
}

void LIS_print(int cur, int prev){
    if(cur == (int)numList.size())
        return;

    int optimal = LIS(cur, prev);

    int leave = LIS(cur + 1, prev);
    int pick = (prev >= (int)numList.size() || numList[prev] < numList[cur]) ? pick = 1 + LIS(cur + 1, cur) : 0;

    if(optimal == leave)
        LIS_print(cur + 1, prev);
    else{
        cout << numList[cur] << " ";
        LIS_print(cur + 1, cur);
    }
    return;
}

class Solution {
public:
	int lengthOfLIS(const vector<int> &nums) {
		numList = nums;
		memset(memory, -1, sizeof(memory));

		int listSize = (int)numList.size();

		int ans = LIS(0, listSize);
		LIS_print(0, listSize);

		cout << " size = ";

		return ans;
	}
};

int main() {

    cout << Solution().lengthOfLIS({0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}) << "\n"; // 6

    for(int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j)
            cout << memory[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
