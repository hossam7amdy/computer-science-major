// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=676
#include<bits/stdc++.h>
using namespace std;


const int MAX = 100 + 1;
int memory[MAX][MAX];

vector<int> quantity, price;

// O(N^2) memory and O(N^3) time
int best_split(int start_idx, int end_idx) {
	if (end_idx >= (int)quantity.size())
		return 0;

	auto &ret = memory[start_idx][end_idx];
	if (ret != -1)
		return ret;

	int sum = 0;    for(int i = start_idx; i <= end_idx; ++i)
        sum += quantity[i];

	int cur_block_cost = price[end_idx] * (sum + 10);
	int finish_split_cost = cur_block_cost + best_split(end_idx + 1, end_idx + 1);

	int next_split_cost = 1e9;
	if(end_idx + 1 < (int)quantity.size())
        next_split_cost = best_split(start_idx, end_idx + 1);

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


