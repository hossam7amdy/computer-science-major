#include<bits/stdc++.h>
using namespace std;

/*

Let's change the return request:
 Given array, find the longest sequence that is mountain. Let's say MM
 Then what the problem needs is length(array) - MM
 In other words, let's focus on the complement of the problem.
 We may call that: reverse/backward thinking


How to find the longest mountain?
We may write a single DP that tries to solve that
	we need current index, last index, is going up?

A simple observation is: a mountain is actually 2 sub-sequences
The longest increasing subsequence (LIS) ending at X,
	followed by the longest decreasing subsequence  (LDS) starting from X

	Example: Input: 2,1,1,5,6,2,3,1
		The mountain is: 1,5,6,3,1,0
			which is LIS: 1, 5, 6    (end at 6)
			and      LDS: 6, 3, 1, 0 (start from 6)


Coding:
- Let's use the 2nd style of LIS we did before
	- LIS(index): find LIS starting from this index to the end of array, including arr[index]
		This is great definition. We will flip < to > to make it LDS sequence

	- In the problem, we need LIS ending at index NOT starting
		- We will change the code to simply go from the end of the array NOT begin

- After you compute the LIS and LDS, find the max position of LIS[i] + LDS[i] - 1
	why -1? as there is an index SHARED between the 2 sequences

- Special case? Observe the mountain must be increasing then decreasing
	- If one of the LIS[i] or LDS[i] = 1, then there is no mountain

 */

const int MAX = 1000 + 1;
int memory_lds[MAX];
int memory_lis[MAX];

vector<int> numbers;

int LDS(int cur) {
    if(cur == (int)numbers.size())
        return 0;

    int &ret = memory_lds[cur];
    if(ret != -1)
        return ret;

    ret = 0;
    for(int next = cur + 1; next < (int)numbers.size(); ++next)
        if(numbers[cur] > numbers[next])
            ret = max(ret, LDS(next));

    ret += 1;
    return ret;
}

int LIS(int cur){
    if(cur == -1)
        return 0;

    int &ret = memory_lis[cur];
    if(ret != -1)
        return ret;

    ret = 0;
    for(int prev = cur - 1; prev >= 0; --prev)
        if(numbers[prev] < numbers[cur])
            ret = max(ret, LIS(prev));

    ret += 1;
    return ret;
}

class Solution {
public:
    int minimumMountainRemovals(const vector<int>& nums) {
        int sz = (int)nums.size();
        numbers = nums;

        memset(memory_lds, -1, sizeof(memory_lds));
        memset(memory_lis, -1, sizeof(memory_lis));


        int best = 0;
        for(int i = 0; i < sz; ++i){
            if(LIS(i) == 1 || LDS(i) == 1)
                continue;

            int cur = LIS(i) + LDS(i) - 1;
            best = max(best, cur);
        }

        return sz - best;
    }
};

int main(){
    Solution sol;

    cout << sol.minimumMountainRemovals({1,3,1}) << "\n"; // 0
    cout << sol.minimumMountainRemovals({2,1,1,5,6,2,3,1}) << "\n"; // 3
    cout << sol.minimumMountainRemovals({9,8,1,7,6,5,4,3,2,1}) << "\n"; // 2

    return 0;
}
