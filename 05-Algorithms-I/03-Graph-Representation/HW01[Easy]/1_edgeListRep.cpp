#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge {
    int from{};
    int to{};
    int cost{};

    edge(const int &from, const int &to, const int &cost):
        from(from), to(to), cost(cost){
    }

    bool operator < (const edge &e) const {
        return cost < e.cost;
    }

    void printEdge() const {
        cout << "Edge (From " << from << " to " << to << " with cost " << cost << ")" << endl;
    }
};

typedef vector<edge> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost) {
    graph.push_back(edge(from, to, cost));
}

void print_adjaceny_list(GRAPH &graph) {
    for(const auto &edge : graph)
        edge.printEdge();
}


int main(){
    GRAPH graph;

    add_edge(graph, 0, 1, 2);
    add_edge(graph, 0, 2, 3);
    add_edge(graph, 1, 2, 15);
    add_edge(graph, 1, 3, 2);
    add_edge(graph, 2, 4, 13);
    add_edge(graph, 3, 4, 9);

    sort(graph.begin(), graph.end()); // O(n log n)

    print_adjaceny_list(graph); // space & memory O(E)

    return 0;
}
