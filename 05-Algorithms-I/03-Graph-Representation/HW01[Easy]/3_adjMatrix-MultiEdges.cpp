#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<vector<int>>> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost){
    graph[from][to].push_back(cost);
}

void print_adj_matrix(const GRAPH &graph) {
    int nodes = (int)graph.size();

    for(int from = 0; from < nodes; from++)
        for(int to = 0; to < nodes; to++)
			for(int weight : graph[from][to])
				cout << "From " << from << " to " << to << " the cost is " << weight << "\n";
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes, vector<vector<int>>(nodes));

    print_adj_matrix(graph);

    for(int e = 0; e < edges; e++){
        int from, to, cost;
        cin >> from >> to >> cost;
        add_edge(graph, from, to, cost);
    }

    print_adj_matrix(graph);

    return 0;
}

/*

5 10
0 1 10
1 2 7
0 1 7
2 3 9
2 3 15
3 4 50
0 4 52
0 4 30
2 4 36
4 0 150

Output
From 0 to 1 the cost is 10
From 0 to 1 the cost is 7
From 0 to 4 the cost is 52
From 0 to 4 the cost is 30
From 1 to 2 the cost is 7
From 2 to 3 the cost is 9
From 2 to 3 the cost is 15
From 2 to 4 the cost is 36
From 3 to 4 the cost is 50
From 4 to 0 the cost is 150


O(V^2 + E) for space complexity
O(1) to check edge (u, v)
 */
