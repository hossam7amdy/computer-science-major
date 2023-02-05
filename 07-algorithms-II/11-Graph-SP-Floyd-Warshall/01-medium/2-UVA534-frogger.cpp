// UVA 534 - Frogger
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=475
#include<bits/stdc++.h>
using namespace std;

void run(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
}

const int INF = 1e9;

void compute_min_max(vector<vector<int>> &graph) {
    int n = graph.size();

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
    }
}

int main() {
    run();

	for (int test = 1;; test++) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		vector<int> x(n), y(n);
		vector<vector<int>> graph(n, vector<int>(n));

		for (int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				int dx = x[i] - x[j], dy = y[i] - y[j];
				graph[i][j] = dx * dx + dy * dy;
			}

		compute_min_max(graph);

		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", test, sqrt(graph[0][1]));
	}

	return 0;
}
