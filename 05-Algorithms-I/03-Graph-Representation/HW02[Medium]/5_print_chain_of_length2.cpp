#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_edge(GRAPH &graph, int from, int to){
    graph[from].push_back(to);
}

void print_paths_len_2(GRAPH &graph) {
	int nodes = graph.size();
	// Iterate on node and get all its neighbor
	// for each neighbor, get its neighbors too
	for (int i = 0; i < nodes; ++i) {
		for (int idx1 = 0; idx1 < (int) graph[i].size(); ++idx1) {
			int j = graph[i][idx1];
			for (int idx2 = 0; idx2 < (int) graph[j].size(); ++idx2) {
				int k = graph[j][idx2];
				cout << i << " " << j << " " << k << "\n";
			}
		}
	}
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

    print_paths_len_2(graph);

    return 0;
}

