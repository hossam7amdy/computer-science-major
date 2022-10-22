#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
    int to;
    int cost;
};

typedef vector<vector<int>> GRAPH;
typedef vector<vector<edge>> WEIGHTED_GRAPH;

    /// Directed Graph ///

// UN-WEIGHTED //
void add_directed_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
}
// WEIGHTED
void add_weight_to_directed_edge(WEIGHTED_GRAPH &graph, int from, int to, int cost) {
    graph[from].push_back({to, cost});
}

    /// Undirected Graph ///

// UN-WEIGHTED //
void add_undirected_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

// WEIGHTED //
void add_weight_to_undirected_edge(WEIGHTED_GRAPH &graph, int from, int to, int cost) {
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
}

// UN-WEIGHTED //
void print_adj_list(const GRAPH &adj_list){
    for(int node = 0; node < (int)adj_list.size(); node++){
        cout << "Node " << node << " has neighbors: ";
        for(int neighbors = 0; neighbors < adj_list[node].size(); neighbors++)
            cout << adj_list[node][neighbors] << " ";
        cout << "\n";
    }
}

// WEIGHTED //
void print_weighed_adj_list(const WEIGHTED_GRAPH &adj_list){
        for(int node = 0; node < (int)adj_list.size(); node++){
        cout << "Node " << node << " has neighbors: ";
        for(int neighbors = 0; neighbors < adj_list[node].size(); neighbors++)
            cout << "(to " << adj_list[node][neighbors].to << " cost " << adj_list[node][neighbors].cost << ") ";
        cout << "\n";
    }
}

int main(){
    GRAPH directed_graph(5);

    add_directed_edge(directed_graph, 0, 1);
    add_directed_edge(directed_graph, 0, 2);
    add_directed_edge(directed_graph, 1, 2);
    add_directed_edge(directed_graph, 1, 4);
    add_directed_edge(directed_graph, 2, 3);
    add_directed_edge(directed_graph, 3, 4);

    print_adj_list(directed_graph);

    cout << "\n==================\n";

    GRAPH undirected_graph(5);

    add_undirected_edge(undirected_graph, 0, 1);
    add_undirected_edge(undirected_graph, 0, 2);
    add_undirected_edge(undirected_graph, 1, 2);
    add_undirected_edge(undirected_graph, 1, 3);
    add_undirected_edge(undirected_graph, 2, 4);
    add_undirected_edge(undirected_graph, 3, 4);

    print_adj_list(undirected_graph);


    cout << "\n\tWEIGHTED GRAPH\n";
    WEIGHTED_GRAPH undir_graph(5);

    add_weight_to_undirected_edge(undir_graph, 0, 1, 2);
    add_weight_to_undirected_edge(undir_graph, 0, 2, 3);
    add_weight_to_undirected_edge(undir_graph, 1, 2, 15);
    add_weight_to_undirected_edge(undir_graph, 1, 3, 2);
    add_weight_to_undirected_edge(undir_graph, 2, 4, 13);
    add_weight_to_undirected_edge(undir_graph, 3, 4, 9);

    print_weighed_adj_list(undir_graph);

    return 0;
}
