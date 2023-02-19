// https://leetcode.com/problems/network-delay-time/
#include<bits/stdc++.h>
using namespace std;


class Solution {
    #define INF 1e9
    #define from first
    #define cost second
    #define edge pair<int,int>
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<edge>> adjList(n+1);
        for(auto& ed : times){
            int from = ed[0], to = ed[1], cost = ed[2];
            adjList[to].push_back({from, cost});
        }

        vector<int> dist = bellman(adjList, k);

        int res = 0;
        for(int i = 1; i < n + 1; ++i){
            if(dist[i] == INF)
                return -1;
            res += dist[i];
        }

        return res;
    }

private:
    vector<int> bellman(vector<vector<edge>>& adjList, int src){
        int n = adjList.size();
        vector<int> dist(n, INF);

        dist[src] = 0;
        for(int i = 0; i < n - 1; ++i)
            for(int to = 0; to < n; ++to)
                for(auto& ed : adjList[to])
                    dist[to] = min(dist[to], dist[ed.from] + ed.cost);

        return dist;
    }
};

int main(){

    return 0;
}

