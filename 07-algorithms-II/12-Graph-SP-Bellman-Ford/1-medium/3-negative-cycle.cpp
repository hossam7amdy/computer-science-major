#include<bits/stdc++.h>
using namespace std;

/*
How can we know there is a negative cycle?

Based on a simple observation.
Assume there is no negative cycle
then we know every path must have maximum N-1 edges
So we relax N-1 full iterations

What if one extra iteration also relaxed?
	Then we have a shorter path of N edges
	This means there is a negative cycle


So just iterate one more iteration. If anything relaxed, we have -ve cycle
*/

const int OO = (int) 1e9;
struct edge {
    int from, to, cost;
    edge(int from, int to, int cost) :
        from(from), to(to), cost(cost){
    }
};

bool bellman_cycle(vector<edge>& edgeList, int n, int src){
    vector<int> dist(n, OO);
    dist[src] = 0;

    for(int it = 0; it < n; ++it){
        bool updated = false;

        for(int to = 0; to < (int) edgeList.size(); ++to){
            edge &ne = edgeList[to];

            if( dist[ne.to] > dist[ne.from] + ne.cost ){
                dist[ne.to] = dist[ne.from] + ne.cost;
                updated = true;
            }
        }
        if(!updated)
            break;
        if(it == n - 1)
            return true;
    }

    return false;
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

    cout << bellman_cycle(edgeList, v, src) << "\n";

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

6 8 0
0 1 1
1 2 99
1 4 1
2 3 5
4 2 3
4 5 6
5 3 7
3 1 -1000
*/
