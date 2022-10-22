#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> GRAPH;
void add_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
}
void print_adj_list(const GRAPH &graph) {
    for(int node = 0; node < (int)graph.size(); node++){
        cout << "Node " << node << " has neighbors: ";
        for(int edge = 0; edge < (int)graph[node].size(); edge++)
            cout << graph[node][edge] << " ";
        cout << "\n";
    }
}

int main(){
    int ROWS, COLS;
    cin >> ROWS >> COLS;

    GRAPH image(COLS*ROWS);

    int dr[] {-1,0,1,0};
    int dc[] {0,1,0,-1};

    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            for(int d = 0; d < 4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS)
                    add_edge(image, COLS * r + c , COLS * nr + nc);
            }
        }
    }

    print_adj_list(image);

    return 0;
}
