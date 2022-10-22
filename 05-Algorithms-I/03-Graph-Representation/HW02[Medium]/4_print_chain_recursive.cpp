#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
}
void print_chain(GRAPH &graph, int from) {
    cout << from << " ";

    if((int)graph[from].size() > 0)
        print_chain(graph, graph[from][0]);
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes);

    for(int edge = 0; edge < edges; edge++){
        int from, to;
        cin >> from >> to;
        add_edge(graph, from, to);
    }

    int q;
    cin >> q;
    while(q--){
        int node;
        cin >> node;
        print_chain(graph, node);
        cout << "\n";
    }

    return 0;
}
