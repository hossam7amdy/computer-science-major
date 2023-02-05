// 125 - Numbering Paths
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=61
#include<bits/stdc++.h>
using namespace std;

void run(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
}

void count_paths(vector<vector<int>> &graph) {
    int n = graph.size();

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                graph[i][j] += graph[i][k] * graph[k][j];

    }

    for(int k = 0; k < n; ++k)
        if(graph[k][k])
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(graph[i][k] && graph[k][j])
                        graph[i][j] = -1;
}

int main() {
	run();

	int m, n, test = 0, x, y;
	int cnt[31][31] = { };

	while (scanf("%d", &m) == 1) {
		memset(cnt, 0, sizeof(cnt));

		n = 0;
		while (m--) {
			scanf("%d %d", &x, &y);
			cnt[x][y]++;
			if (x > n)
				n = x;
			if (y > n)
				n = y;
		}
		n += 1;

		vector<vector<int>> graph(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				graph[i][j] = cnt[i][j];

		count_paths(graph);

		printf("matrix for city %d\n", test++);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j)
					putchar(' ');
				printf("%d", graph[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
