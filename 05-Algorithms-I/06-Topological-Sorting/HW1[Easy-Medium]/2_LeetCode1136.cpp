#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
There are 2 popular problems in graph theory: shortest path and longest path

This problem is about the longest path in DAG (as we return -1 for cycles)
	The longest path problem is NP-hard in general graph (for now think: solutions are extremely slow)
	but it has efficient solutions for DAG graph

	Remember my advise: always notice the extra properties (general graph vs DAG)

Why is this a longest path problem?
	Because the courses that represents the longest chain of prerequisites will be the bottleneck to finish the study

Many of the DAG problems can be solved with dynamic programming (DP), which is doable in this problem.

However, a nice chance of topological sort is possible for this problem.

=================

We can develop an idea that is inspired from BFS and implemented like a topological sort!

Imagine in the normal topological sort we have 4 nodes with in-degree 0
	We add to the queue and start to get them one by one

What if we did like BFS level by level strategy? Processed the queue exactly 4 times?
	We removed one level of the tree!
	The queue new nodes are the next stage of nodes with in-degree 0!



Take home message
	BFS 			 => Shortest Path in unweighted Graph
	Topological sort => Longest  Path in DAG

*/

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &adjList, int from, int to){
    adjList[from].push_back(to);
}

int topoSort(const GRAPH &adjList){
    int nodes = (int)adjList.size();

    vector<int> indegree(nodes);
    for(int n = 0; n < nodes; ++n)
        for(int edge : adjList[n])
            indegree[edge]++;

    queue<int> ready;
    for(int d = 0; d < nodes; ++d)
        if(!indegree[d])
            ready.push(d);

    vector<int> sorting;
    int levels = 0;
    for(int sz = (int)ready.size(); !ready.empty(); sz = (int)ready.size(), ++levels){
        while(sz--){
            int cur = ready.front();
            ready.pop();
            sorting.push_back(cur);

            for(int d : adjList[cur])
                if(--indegree[d] == 0)
                    ready.push(d);
        }
    }

    if((int)sorting.size() != nodes)
        return -1;

    return levels;
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

        cout << topoSort(adjList) << "\n";
    }

    return 0;
}
