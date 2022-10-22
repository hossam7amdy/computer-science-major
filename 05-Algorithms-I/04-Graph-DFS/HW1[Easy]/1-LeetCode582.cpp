#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
 * This is the exact problem as the lecture problem: reachability
 * The only issue: node values are not in range [0, N-1]
 *
 * One nice way to handle that is to use hash_table
 * We use unordered_map to represent the graph (flexible key)
 * We use unordered_set to represent the visited nodes
 *
 * Time complexity is the same.
 * 		This representation is powerful if the graph is very sparse
 * 		such that many nodes are isolated
 *
 * Be flexible in representing graphs :)
 */

typedef unordered_map<int, vector<int>> GRAPH;

void add_edge(GRAPH &graph, int from, int to){
    graph[from].push_back(to);
}

void build_graph(GRAPH &graph, const vector<int> &pid, const vector<int> &ppid){
    for(int i = 0; i < (int)pid.size(); ++i)
        add_edge(graph, ppid[i], pid[i]);
}

void dfs(GRAPH &graph, int node, unordered_set<int> &visited){
    visited.insert(node);

    for(int neighbor : graph[node]){
        if(!visited.count(neighbor))
            dfs(graph, neighbor, visited);
    }
}

vector<int> reachability(GRAPH &graph, int node){
    unordered_set<int> visited;
    dfs(graph, node, visited);
    return vector<int>(visited.begin(), visited.end());
}

class Solution{
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill){
        GRAPH processes;
        build_graph(processes, pid, ppid);
        return reachability(processes, kill);
    }
};



int main(){
    vector<int> pid {5, 2, 0, 1, 6, 3, 4};
    vector<int>ppid {0, 5, 5, 5, 2, 2, 1};

    Solution sol;

    for(int i = 1; i < 7; ++i){
        vector<int> res = sol.killProcess(pid, ppid, pid[i]);
        for(const int id : res)
            cout << id << " ";
        cout << "\n";
    }

    return 0;
}
