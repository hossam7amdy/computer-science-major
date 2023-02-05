#include<bits/stdc++.h>
using namespace std;

#define INF 1e6
typedef vector<vector<int>> GRAPH;

void read_graph(GRAPH& graph){
    freopen("input.txt", "rt", stdin);

    int n, edges;
    cin >> n >> edges;

    graph.resize(n, vector<int>(n, INF));

    for(int i = 0; i < n; ++i) // diagonal
        graph[i][i] = 0;

    for(int i = 0; i < edges; ++i){
        int from, to, cost;
        cin >> from >> to >> cost;

        if(from == to) // ignore self loops
            continue;

        graph[from][to] = min(graph[from][to], cost);
    }
}

void floyd(GRAPH& graph, GRAPH& path){
    int n = graph.size();

    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = k;
                }
}

void build_path(GRAPH& path, int src, int dst){
    if(path[src][dst] == -1){
        cout << src << " " << dst << "\n";
        return;
    }

    build_path(path, src, path[src][dst]);
    build_path(path, path[src][dst], dst);
}

void print_sp_path(GRAPH& graph, int src, int dst){
    int n = graph.size();
    GRAPH path(n, vector<int>(n,-1));

    floyd(graph,path);
    build_path(path, src, dst);
}

int main(){
    GRAPH graph;

    read_graph(graph);
    print_sp_path(graph, 0, 2);

    return 0;
}
