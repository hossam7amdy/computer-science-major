#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
struct edge {
    int from, to, cost;
    edge(int from, int to, int cost):
        from(from), to(to), cost(cost){
    }
};

vector<int> bellman(vector<vector<edge>>& edgeList, int src){
    int n = edgeList.size();
    vector<int> dist(n, INF);

    dist[src] = 0;
    for(int i = 0; i < n - 1; ++i)
        for(int to = 0; to < n; ++to){
            cout << "relax node " << to << " :";
            for(auto& ne : edgeList[to])
                dist[ne.to] = min(dist[ne.to], dist[ne.from] + ne.cost);
            for(auto val : dist)
                cout << val << " ";
            cout << "\n";
        }

    return dist;
}

int main(){
    int v, e, src;
    cin >> v >> e >> src;

    vector<vector<edge>> edgeList(v);

    for(int i = 0; i < e; ++i){
        int from, to, cost;
        cin >> from >> to >> cost;
        edgeList[to].push_back({from, to, cost});
    }

    vector<int> res = bellman(edgeList, src);
    for(int i = 0; i < v; ++i)
        cout << i << " " << res[i] << "\n";


    return 0;
}

/*
6 7 0
0 1 1
1 2 99
1 4 1
2 3 5
4 2 3
4 5 6
5 3 7

4 3 1
1 0 1
1 2 1
2 3 1
*/
