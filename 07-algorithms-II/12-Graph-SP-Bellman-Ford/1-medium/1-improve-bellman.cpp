// https://leetcode.com/problems/network-delay-time/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<edge> edgeList;
        for(auto& ed : times){
            edge e { ed[0] - 1, ed[1] - 1, ed[2] };
            edgeList.push_back(e);
        }

        vector<int> sp = bellman(edgeList, n, k - 1);

        int res = *max_element(sp.begin(), sp.end());
        return res == OO ? -1 : res;
    }

private:
    const int OO = (int) 1e9;
    struct edge {
        int from, to, cost;

        edge(int from, int to, int cost) :
            from(from), to(to), cost(cost){
        }
    };

    vector<int> bellman(vector<edge>& edgeList, int n, int src){
        vector<int> dist(n, OO);
        dist[src] = 0;

        for(int it = 0; it < n - 1; ++it){
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
        }
        return dist;
    }
};

int main(){

    return 0;
}
