#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
struct edge {
    int from, to, cost;
    edge(int from, int to, int cost):
        from(from), to(to), cost(cost){
    }
};

vector<int> bellman(vector<vector<edge>>& adjList, int src){
    int n = adjList.size();
    vector<int> dist(n, INF);

    dist[src] = 0;
    for(int i = 0; i < n - 1; ++i)
        for(int to = 0; to < n; ++to)
            for(auto& ne : adjList[to])
                dist[ne.to] = min(dist[ne.to], dist[ne.from] + ne.cost);

    return dist;
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<edge>> adjList(v);

    for(int i = 0; i < e; ++i){
        int from, to, cost;
        cin >> from >> to >> cost;
        adjList[to].push_back({from, to, cost});
    }

    vector<int> res = bellman(adjList, 0);
    for(int i = 0; i < v; ++i)
        cout << i << " " << res[i] << "\n";


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
