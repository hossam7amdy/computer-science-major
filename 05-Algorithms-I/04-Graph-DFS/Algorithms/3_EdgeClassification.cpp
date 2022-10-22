#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<vector<int>> GRAPH;
void addDirectedEdge(GRAPH &adjList, const int &from, const int &to){
    adjList[from].push_back(to);
}

void dfs(const GRAPH &adjList,  int &node, vector<int> &start, vector<int> &finish, int &time){
    start[node] = ++time;

    for(auto neighbor : adjList[node]){
        if(start[neighbor] == -1){
            cout << "Tree edge: " << node << " " << neighbor << "\n";
            dfs(adjList, neighbor, start, finish, time);
        }
        else{
            if(start[node] < start[neighbor])
                cout << "Forward edge: " << node << " " << neighbor << "\n";
            else if(finish[neighbor] == -1)
                cout << "Back edge (CYCLE): " << node << " " << neighbor << "\n";
            else
                cout << "Cross edge: " << node << " " << neighbor << "\n";
        }
    }
    finish[node] = ++time;
}

void edgeClassification(const GRAPH &adjList){
    int nodes = (int)adjList.size();
    vector<int> start(nodes, -1);
    vector<int> finish(nodes, -1);

    int time = 0;
    for(int i = 0; i < nodes; ++i)
        if(start[i] == -1)
            dfs(adjList, i, start, finish, time);
}

int main(){
    freopen("edge_classification-input.txt", "r", stdin);
    int Cases;
    cin >> Cases;
    while(Cases--){
        int nodes, edges;
        cin >> nodes >> edges;
        GRAPH adjList(nodes);
        for(int i = 0; i < edges; ++i){
            int from, to;
            cin >> from >> to;
            addDirectedEdge(adjList, from, to);
        }

        edgeClassification(adjList);
        cout << "==========================\n";
    }

    return 0;
}
