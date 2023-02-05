#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef vector<vector<int>> GRAPH;

void print(GRAPH& graph){
    for(auto &row : graph){
        for(auto &val : row){
            if(val == INF)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << "\n";
    }
    cout << "----------------\n";
}

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

int floyd(GRAPH& graph){
    int n = graph.size();

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
        cout << "After relaxed with node: " << k << "\n";
        print(graph);
    }
}

int main(){
    GRAPH graph;

    read_graph(graph);
    floyd(graph);

    return 0;
}
