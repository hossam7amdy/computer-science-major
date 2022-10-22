#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<unordered_set<int>> GRAPH;

void add_edge(GRAPH &graph, int from, int to){
    graph[from].insert(to);
}

void print_adjaceny_list(const GRAPH &graph) {
    for(int node = 0; node < (int)graph.size(); node++){
        cout << "Node " << node << " has neighbors: ";
        for(const auto &neighbor : graph[node])
            cout << neighbor << " ";
        cout << "\n";
    }
}

bool isExist(const GRAPH &graph, int from, int to){
    if(from >= (int)graph.size())
        return false;

    return graph[from].count(to);
}

/*
Space Complexity is O(E)
Time complexity
	O(1) for add/remove/check edge
	O(Degree) for iterate on neighbors

Disadvantages
	- No order guarantee for edges
	- Impractical for multiple edges  (we may do workarounds)
	- Hash tables extra memory
	- Like any hash tables, more caution to properly deal with the load (load factor)

*/

int main(){
    GRAPH graph(6);

    //print_adjaceny_list(graph);

    add_edge(graph, 2, 1);
    add_edge(graph, 2, 5);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 0, 5);
    add_edge(graph, 1, 4);
    add_edge(graph, 5, 4);
    add_edge(graph, 0, 0);

    // sort(graph.begin(), graph.end());

    cout << isExist(graph, 6, 1) << endl; // 0
    cout << isExist(graph, 2, 5) << endl; // 1
    cout << isExist(graph, 1, 1) << endl; // 0
    cout << isExist(graph, 4, 1) << endl; // 0
    cout << isExist(graph, 1, 4) << endl; // 1

    print_adjaceny_list(graph); // O(V+E)



    return 0;
}
