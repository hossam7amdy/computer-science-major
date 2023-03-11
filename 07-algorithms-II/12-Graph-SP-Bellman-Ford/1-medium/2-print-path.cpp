#include<bits/stdc++.h>
using namespace std;

const int OO = (int) 1e9;
struct edge {
    int from, to, cost;
    edge(int from, int to, int cost) :
        from(from), to(to), cost(cost){
    }
};

vector<int> bellman(vector<edge>& edgeList, int n, int src, vector<int>& prev){
    vector<int> dist(n, OO);
    prev = vector<int>(n, -1);

    dist[src] = 0;

    for(int it = 0; it < n - 1; ++it){
        bool updated = false;

        for(int to = 0; to < (int) edgeList.size(); ++to){
            edge &ne = edgeList[to];

            if( dist[ne.to] > dist[ne.from] + ne.cost ){
                dist[ne.to] = dist[ne.from] + ne.cost;
                prev[ne.to] = ne.from;
                updated = true;
            }
        }
        if(!updated)
            break;
    }

    return dist;
}

vector<int> buildPath(vector<int>& prev, int target){
    vector<int> path;

    for(int i = target; i != -1; i = prev[i])
        path.push_back(i);

    reverse(path.begin(), path.end());
    return path;
}

int main(){
    int v, e, src;
    cin >> v >> e >> src;

    vector<edge> edgeList;

    for(int i = 0; i < e; ++i){
        int from, to, cost;
        cin >> from >> to >> cost;
        edgeList.push_back({from, to, cost});
    }

    vector<int> prev;
    vector<int> res = bellman(edgeList, v, src, prev);

    vector<int> path = buildPath(prev, 3);
    for(auto& node : path)
        cout << node << " ";

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
