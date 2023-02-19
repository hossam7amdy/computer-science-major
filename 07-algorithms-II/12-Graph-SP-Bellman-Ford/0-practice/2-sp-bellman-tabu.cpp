#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define from first
#define cost second
#define edge pair<int,int>

vector<int> bellman(vector<vector<edge>> &adjList, int src){
    int n = adjList.size();

    vector<int> dist(n, INF);
    dist[src] = 0;

    for(int it = 0; it < n - 1; ++it)
        for(int to = 0; to < n; ++to)
            for(auto &ed : adjList[to])
                dist[to] = min(dist[to], dist[ed.from] + ed.cost);

    return dist;
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<edge>> adjList(v);

    for(int i = 0; i < e; ++i){
        int from, to, cost;
        cin >> from >> to >> cost;
        adjList[to].push_back({from, cost});
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
