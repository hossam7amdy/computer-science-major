#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &adjList, int from, int to){
    adjList[from].push_back(to);
}

vector<int> topoSort(const GRAPH &adjList){ // O(VlogV+E)
    int nodes = (int)adjList.size();

    vector<int> indegree(nodes);
    for(int n = 0; n < nodes; ++n)
        for(int edge : adjList[n])
            indegree[edge]++;

    priority_queue<int, vector<int>, greater<int>> ready; // min heap
    for(int d = 0; d < nodes; ++d)
        if(!indegree[d])
            ready.push(d);

    vector<int> sorting;
    while(!ready.empty()){
        int cur = ready.top();
        ready.pop();
        sorting.push_back(cur);

        for(int d : adjList[cur])
            if(--indegree[d] == 0)
                ready.push(d);
    }

    if((int)sorting.size() != nodes)
        sorting.clear();

    return sorting;
}

int main(){
    freopen("input.txt", "r", stdin);

    int testCases;
    cin >> testCases;
    while(testCases--){
        int nodes, edges;
        cin >> nodes >> edges;

        GRAPH adjList(nodes);
        for(int i = 0; i < edges; ++i){
            int from, to;
            cin >> from >> to;
            add_directed_edge(adjList, from, to);
        }

        vector<int> result = topoSort(adjList);

        for(auto node : result)
            cout << node << " ";
        cout << "\n";
    }

    return 0;
}
