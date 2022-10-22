// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=676
#include<bits/stdc++.h>
using namespace std;

// O(N) memory and O(N^2) time

const int MAX = 100 + 1;
int memory[MAX];

vector<int> quantity, price;

// Find the best split of the array starting from this index
int best_split(int start_idx) {
	if (start_idx >= (int)quantity.size())
		return 0;

	auto &ret = memory[start_idx];
	if (ret != -1)
		return ret;

	ret = 1e9;
	int sum = 0;
	for(int block_end = start_idx; block_end < (int)quantity.size(); ++block_end){
        sum += quantity[block_end];
        int cost_cur_block = price[block_end] * (sum + 10);
        int total_cost = cost_cur_block + best_split(block_end + 1);

        ret = min(ret, total_cost);
	}

	return ret;
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

		memset(memory, -1, n * sizeof(int));

		printf("%d\n", best_split(0));
	}

	return 0;
}


