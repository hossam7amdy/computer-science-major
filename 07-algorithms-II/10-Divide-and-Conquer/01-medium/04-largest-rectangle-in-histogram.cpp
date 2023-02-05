// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include<bits/stdc++.h>
using namespace std;

/// Instructor Notes ///
/*

The idea is simple!

Say we have the array:   10 20 30 7 40 15 37 50
	The minimum value is 7
	What is the largest rectangle containing this 7?
	Clearly, all the range, so: 7 * 8

	Now, where is the max rectangle.
		Either this one passing with the minimum
		Or on left side
		Or on the right side
		It can't be something in the middle, as 7 took whole range!


Time complexity
	Assume given range of N elements, we find the min index in log(N)

	Let T(n) represents total number of operations

	In the worst case, the minimum will be in first element, creating sub-problem of N-1 values!
	So
	T(n) = T(n-1) + log(n)
	by substitution
	T(n) = log(n)+log(n-1)+log(n-2)+.....1
	Overall, N terms, with max value log(n)
	so in total this is O(nlogn) complexity

 */

class Solution {
private:
    static const int MAXN = 100002;
    typedef long long ll;
    int Log[MAXN];
    ll stable[MAXN][17];
    ll arr[MAXN];
    int n;

    void build() {
        int cnt = -1;
        for (int i = 0; i < n; i++) {
            if (!((i + 1) & i))
                cnt++;
            stable[i][0] = i;
            Log[i + 1] = cnt;
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j)) <= n; i++) {
                int a = stable[i][j - 1];
                int b = stable[i + (1 << (j - 1))][j - 1];
                stable[i][j] = ((arr[a] < arr[b]) ? a : b);
            }
        }
    }

    // Return minimum index in this range in O(n)
    int getMinIdx_slow(int l, int r) {
        int minIdx = l;

        for (int i = l + 1; i <= r; i++)
            if (arr[minIdx] > arr[i])
                minIdx = i;

        return minIdx;
    }

    // This is well known sub-problem (Range Minimum Query (RMQ))
    // Can be solved in O(logn)
    int getMinIdx(int st, int en) {
        int L = Log[en - st + 1];
        int a = stable[st][L], b = stable[en - (1 << L) + 1][L];
        return ((arr[a] < arr[b]) ? a : b);
    }

    void prepare(vector<int> &heights) {
        n = heights.size();
        for (int i = 0; i < n; ++i)
            arr[i] = heights[i];

        build();
    }

    int getMaxArea(vector<int> &heights, int st, int en) {
        if(st > en)
            return 0;

        int min_idx = getMinIdx(st, en);	// ready for you

        int cur_rec_area = (en - st + 1) * heights[min_idx];
        int left_rec_area = getMaxArea(heights, st, min_idx - 1);
        int right_rec_area = getMaxArea(heights, min_idx + 1, en);

        return max(left_rec_area,max(right_rec_area,cur_rec_area));
    }

public:
    int largestRectangleArea(vector<int> &heights) {
        prepare(heights);

        return getMaxArea(heights, 0, heights.size() - 1);
    }

};

int main(){

    return 0;
}
