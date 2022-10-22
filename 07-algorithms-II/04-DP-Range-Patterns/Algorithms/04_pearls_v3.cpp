// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=676
#include<bits/stdc++.h>
using namespace std;


// O(N^2) memory and O(N^2) time

/*

This trick will teach you an interesting thing about dynamic programming.

We want the range sum, right?
- We can sum it in O(N)
- We can use prefix sum: O(N) memory and O(1) time for queries

What if we just kept passing the updated range sum instead of calculating? This looks time-saving: O(1) time and memory

Now the trick is: this function takes 3 arguments, should we use 3D array?
Now, this extra information is deduced from the interval, so it is not actually a new information
That is: the 2 indices are sufficient data

Another context in case you don't get it
Assume our function takes 3 integers (a, b, c) ==> memorize in 3D array
What if also included a 4th variable represents their multiplication?
This variable can be computed from (a, b, c), so no need to memorize it

Tips:
- Pass extra information that makes the code faster
- Don't memoize these extra information!
 */

const int MAX = 100 + 1;
int memory[MAX][MAX];

vector<int> quantity, price;

int best_split(int start_idx, int end_idx, int sum_so_far = 0) {
	if (end_idx >= (int)quantity.size())
		return 0;

	auto &ret = memory[start_idx][end_idx];
	if (ret != -1)
		return ret;

    sum_so_far += quantity[end_idx];

	int cur_block_cost = price[end_idx] * (sum_so_far + 10);
	int finish_split_cost = cur_block_cost + best_split(end_idx + 1, end_idx + 1, 0);

	int next_split_cost = 1e9;
	if(end_idx + 1 < (int)quantity.size())
        next_split_cost = best_split(start_idx, end_idx + 1, sum_so_far);

	return ret = min(finish_split_cost, next_split_cost);
}

int main() {
	//freopen("data.txt", "rt", stdin);

	int cases, n;
	scanf("%d", &cases);

	while (cases--) {
		scanf("%d", &n);
		quantity.resize(n);
		price.resize(n);

		for (int i = 0; i < n; ++i)
			scanf("%d%d", &quantity[i], &price[i]);

		memset(memory, -1, sizeof(memory));

		printf("%d\n", best_split(0, 0));
	}

	return 0;
}


