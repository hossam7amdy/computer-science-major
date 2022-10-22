#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_direct_edge(GRAPH &graph, const int &from, const int &to){
    graph[from].push_back(to);
}

vector<int> BFS(const GRAPH &graph, const int &start){
    queue<int> nodes;
    vector<bool> visited( (int)graph.size() );
    vector<int> parent( (int)graph.size(), -1);

    nodes.push(start);
    visited[start] = true;


    while(!nodes.empty()){
        int cur = nodes.front();
        nodes.pop();

        for(const auto neighbor : graph[cur]){
            if(!visited[neighbor]){
                nodes.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = cur;
            }
        }
    }
    return parent;
}

void printPath(const vector<int> &parents, int cur_node){
    if(cur_node == -1)
        return;

    printPath(parents, parents[cur_node]);
    cout << cur_node << " ";
}

int main(){
    freopen("01_BFS_path.txt", "r", stdin);

    int cases;
    cin >> cases;

    while(cases--){
        int nodes, edges;
        cin >> nodes >> edges;

        GRAPH adjList(nodes);

        for(int ed = 0; ed < edges; ++ed){
            int from, to;
            cin >> from >> to;
            add_direct_edge(adjList, from ,to);
        }

        int start = 0;
        vector<int> parents = BFS(adjList, start);

        for(int i = 1; i < nodes; ++i){
            cout << "Path from " << start << " to " << i << ": ";

            if(parents[i] == -1)
                cout << "Not Exist";
            else
                printPath(parents, i);
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}

/*
2

5 4
0 1
1 2
2 3
4 3

9 11
1 3
1 5
1 6
3 5
4 3
3 7
5 4
6 0
2 4
2 8
0 2

Path from 0 to 1: 0 1
Path from 0 to 2: 0 1 2
Path from 0 to 3: 0 1 2 3
Path from 0 to 4: Not exist

Path from 0 to 1: Not exist
Path from 0 to 2: 0 2
Path from 0 to 3: 0 2 4 3
Path from 0 to 4: 0 2 4
Path from 0 to 5: 0 2 4 3 5
Path from 0 to 6: Not exist
Path from 0 to 7: 0 2 4 3 7
Path from 0 to 8: 0 2 8
 */
