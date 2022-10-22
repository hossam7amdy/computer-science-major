#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
private:
    typedef vector<vector<int>> GRAPH;

    void add_undirected_edge(GRAPH &adjList, const int &from, const int &to){
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    bool BFS_cycle(const GRAPH &adjList, const int &start){
        queue<int> nodes;
        vector<bool> visited((int)adjList.size(), 0);
        vector<bool> parents((int)adjList.size(), 0);

        nodes.push(start);
        visited[start] = true;

        while(!nodes.empty()){
            int cur = nodes.front();
            nodes.pop();
            parents[cur] = true;

            for(const auto &neighbor : adjList[cur]){
                if(!visited[neighbor]){
                    nodes.push(neighbor);
                    visited[neighbor] = true;
                    continue;
                }
                if(visited[neighbor] && !parents[neighbor])
                    return false;
            }
        }
        return true;
    }

public:
    bool validTree(int nodes, const vector<vector<int>> &edges){
        if((int)edges.size() != nodes - 1)
            return false;

        GRAPH adjList(nodes);

        // building graph
        for(const auto &vec : edges)
            add_undirected_edge(adjList, vec[0], vec[1]);

        return BFS_cycle(adjList, 0);
    }
};

int main(){
    Solution s;

    cout << s.validTree(5, {{0,1}, {0,2}, {0,3}, {1,4}}) << "\n"; // 1
    cout << s.validTree(5, {{0,1}, {1,2}, {2,3}, {1,3}, {1,4}}) << "\n"; // 0
    cout << s.validTree(5, {{0, 1}, {1, 2},{2,3}, {3, 4}, {3,1}}) << "\n"; // 0
    cout << s.validTree(6, {{0,4},{0,5},{4,5}}) << "\n"; // 0

    return 0;
}
