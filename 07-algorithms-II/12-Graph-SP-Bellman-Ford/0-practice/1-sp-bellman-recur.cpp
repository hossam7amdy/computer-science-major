#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
vector<vector<int>> graph, memo;

// O(VE)
int bellman(int dst, int at_most_edges){
    if(at_most_edges == 1)
        return graph[0][dst];

    auto &ret = memo[dst][at_most_edges];
    if(ret != -1)
        return ret;

    int leave = bellman(dst, at_most_edges - 1);

    int use_k = INF;
    for(int k = 0; k < graph[dst].size(); ++k)
        if(graph[k][dst] != INF){
            use_k = min(use_k, graph[k][dst] + bellman(k, at_most_edges - 1));
        }

    return ret = min(use_k, leave);
}

int main(){
    int v, e;
    cin >> v >> e;

    memo.resize(v, vector<int>(e, -1));
    graph.resize(v, vector<int>(v,INF));

    for(int i = 0; i < e; ++i){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = cost;
    }

    cout << bellman(3, e - 1) << "\n";

    return 0;
}

/*
6 7
0 1 1
1 2 99
1 4 1
2 3 5
4 2 3
4 5 6
5 3 7
*/
