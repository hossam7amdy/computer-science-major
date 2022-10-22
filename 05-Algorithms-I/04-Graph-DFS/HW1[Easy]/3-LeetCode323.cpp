#include<iostream>
#include<vector>
using namespace std;

/*
 * If we started from a node, performed dfs(node), we can mark all reachable nodes
 * Now, all these nodes are a connected component
 *
 * If there is a node NOT marked, then not reachable. Hence ANOTHER component
 * Again do DFS from it and so on
 *
 * Overall: minor code changes to the lecture reachability code
 *
 * The time & memory complexity is the same O(E+V)
 * As in each call, we cover a sub-graph
 *
 * In graph theory, this problem can be done in other several ways
 * 		Graph BFS
 * 		Graph Union-Find (Disjoint set)
 */

class Solution{
private:
    typedef vector<vector<int>> GRAPH;

public:
    void add_edge(GRAPH &graph, int from, int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    void build_graph(GRAPH &graph, const GRAPH &edges){
        for(const auto &vec : edges)
            add_edge(graph, vec[0], vec[1]);
    }

    void dfs(const GRAPH &graph, vector<bool> &visited, int node){
        visited[node] = true;
        for(const auto &neighbor : graph[node]){
            if(!visited[neighbor])
                dfs(graph, visited, neighbor);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges){
        GRAPH graph(n);
        build_graph(graph, edges);
        vector<bool> visited(n);
        int cnt{};
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                ++cnt;
                dfs(graph, visited, i);
            }
        }

        return cnt;
    }
};

int main(){
    vector<vector<int>> ex1 {{0,1} , {1,2}, {3,4}};
    vector<vector<int>> ex2{{0,1}, {1,2}, {2,3}, {3,4}};
    vector<vector<int>> ex3{{0,1}, {2,3}, {4,5}, {6,7}};

    Solution s;
    cout << s.countComponents(5, ex1) << endl;
    cout << s.countComponents(5, ex2) << endl;
    cout << s.countComponents(8, ex3) << endl;


    return 0;
}
