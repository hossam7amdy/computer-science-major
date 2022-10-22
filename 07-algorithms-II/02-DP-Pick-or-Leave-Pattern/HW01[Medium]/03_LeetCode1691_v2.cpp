// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

/*


 The problem also can be solved using topological sort
 https://leetcode.com/problems/maximum-height-by-stacking-cuboids/discuss/970288/PythonC%2B%2B-O(n2)-Topological-Sort
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<int>> cuboidsg;
const int MAX = 100 + 1;
int memory[MAX][MAX];

bool less_eq(int i, int j) {
	// you don't need to compare on [0] as sorting does
	return cuboidsg[i][1] <= cuboidsg[j][1] && cuboidsg[i][2] <= cuboidsg[j][2];
}

int LIS(int cur, int prev) {
	if (cur == (int) cuboidsg.size())
		return 0;

	auto &ret = memory[cur][prev];

	if (ret != -1)
		return ret;

	int choice1 = LIS(cur + 1, prev);		// Leave
	int choice2 = 0;

	if (prev == (int) cuboidsg.size() || less_eq(prev, cur))
		choice2 = cuboidsg[cur][2] + LIS(cur + 1, cur);	// Take height: cuboidsg[cur][2]

	return ret = max(choice1, choice2);
}

class Solution {
public:
	int maxHeight(vector<vector<int>> &cuboids) {
		// Given that we can rearrange the data,
		// then we better sort from large to small
		// then observe, the longest decreasing sequence
		// is actually the answer
		// For simplicity, sort small to large and use LIS

		// Sort each cube ==> Now we can compare easily
		for (auto &c : cuboids)	// &c important
			sort(c.begin(), c.end());

		// Sort all cubes ==> Answer is just LIS of the cubes
		// Observe cube[2] now is longest side so we maximize height
		sort(cuboids.begin(), cuboids.end());

		cuboidsg = cuboids;
		memset(memory, -1, sizeof(memory));
		return LIS(0, cuboidsg.size());
	}
};

int main() {

	return 0;
}
