#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<vector<int>> GRAPH;

/// Directed Graph
void add_directed_edge(GRAPH &graph, int from, int to) {
    graph[from][to]++;
}
void add_weight_to_directed_edge(GRAPH &graph, int from, int to, const int &cost) {
    graph[from][to] = cost;
}

/// Undirected Graph
void add_undirected_edge(GRAPH &graph, int from, int to) {
    graph[from][to] += 1;
    graph[to][from] += 1;
}
void add_weight_to_undirected_edge(GRAPH &graph, int from, int to, const int &cost) {
    graph[from][to] = graph[to][from] = cost;
}

void print_adj_matrix(const GRAPH &graph){
    for(int r = 0; r < (int)graph.size(); r++)
        for(int c = 0; c < (int)graph[r].size(); c++)
            if(graph[r][c])
                cout << "From " << r << " to " << c << " there are " << graph[r][c] << " edges.\n";
}
void show_graph(const GRAPH &graph) {
    for(const auto &colums : graph){
        for(const auto &row_item : colums)
            cout << row_item << " ";
        cout << "\n";
    }
}

int main(){
    GRAPH directed_graph(5, vector<int>(5));

    add_directed_edge(directed_graph, 0, 1);
    add_directed_edge(directed_graph, 0, 2);
    add_directed_edge(directed_graph, 1, 2);
    add_directed_edge(directed_graph, 1, 4);
    add_directed_edge(directed_graph, 2, 3);
    add_directed_edge(directed_graph, 3, 4);

    print_adj_matrix(directed_graph);

    cout << "\n==================\n";

    GRAPH undirected_graph(5, vector<int>(5));

    add_weight_to_undirected_edge(undirected_graph, 0, 1, 2);
    add_weight_to_undirected_edge(undirected_graph, 0, 2, 3);
    add_weight_to_undirected_edge(undirected_graph, 1, 2, 15);
    add_weight_to_undirected_edge(undirected_graph, 1, 3, 2);
    add_weight_to_undirected_edge(undirected_graph, 2, 4, 13);
    add_weight_to_undirected_edge(undirected_graph, 3, 4, 9);

    print_adj_matrix(undirected_graph);

    return 0;
}
