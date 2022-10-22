#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_edge(GRAPH &graph, int from, int to){
    graph[from].push_back(to);
}

void dfs(const GRAPH &graph, int node, vector<int> &visited){
    visited[node] = true;

    for(const int &neighbor : graph[node]){
        if(!visited[neighbor]){
            cout << neighbor << " ";
            dfs(graph, neighbor, visited);
        }
    }
}

void reachable(const GRAPH &graph){
    int nodes = graph.size();

    for(int i = 0; i < nodes; ++i){
        cout << "Node " << i << " can reach: {";
        vector<int> visited(nodes, 0);
        dfs(graph, i, visited);
        cout << "}\n";
    }
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes);

    for(int i = 0; i < edges; ++i){
        int from, to;
        cin >> from >> to;

        add_edge(graph, from, to);
    }

    reachable(graph);

    return 0;
}

/*
7 9
0 1
0 3
1 4
1 0
2 0
3 1
4 3
5 6
6 6

Node 0 can reach: 1 4 3
Node 1 can reach: 4 3 0
Node 2 can reach: 0 1 4 3
Node 3 can reach: 1 4 0
Node 4 can reach: 3 1 0
Node 5 can reach: 6
Node 6 can reach:
*/
