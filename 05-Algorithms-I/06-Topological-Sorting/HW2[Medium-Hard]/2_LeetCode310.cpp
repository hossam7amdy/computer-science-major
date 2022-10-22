#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

We can develop an idea that is inspired from BFS and implemented like a topological sort!

The idea is shrinking (deleting) the tree leaves LEVEL-by-LEVEL
	Undirected tree node will be leave if in-degree = 1

Imagine a chain: 1-2-3-4-5-6-7
	Nodes 1 and 7 are the current chains. Remove them
	2-3-4-5-6
	Next leaves: 2 and 6. Remove (level 2)
	3-4-5
	Next leaves: 3 and 5. Remove (level 3)
	4

	This is for odd length

	For even length: 1-2-3-4-5-6-7-8
	Stop when there are only 2 nodes: 4-5

The same approach for a tree. The proof is intuitive.
	Leave nodes will make the tree height very high
	The centroids somewhere in the tree are affected by these leaves
	if a centroid at height 7, after we remove ALL leaves at current level,
		the this centroid height is decreasing by one

	See editorial figures

Implementation:
	Like topological sort but
		graph is undirected
		the focus on in-degree = 1
		Stop when there are nodes <= 2

 */

class Solution {
private:
    typedef vector<vector<int>> GRAPH;

    void add_undirected_edge(GRAPH &adjList, const int &from, const int &to){
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
    void build_graph(const GRAPH &edges, GRAPH &adjList){
        for(auto pair : edges)
            add_undirected_edge(adjList, pair[0], pair[1]);
    }

    vector<int> topoSort(const GRAPH &adjList){
        int nodes = (int)adjList.size();

        vector<int> indegree(nodes, 0);
        for(auto nodeNeighbors : adjList)
            for(int neighbor : nodeNeighbors)
                indegree[neighbor]++;

        queue<int> ready;
        for(int i = 0; i < (int)indegree.size(); ++i)
            if(indegree[i] == 1) // leave node
                ready.push(i);

        for(int sz = (int)ready.size(); nodes > 2; sz = (int)ready.size()){
            nodes -= sz;
            while(sz--){
                int cur = ready.front();
                ready.pop();

                for(int neighbor : adjList[cur])
                    if(--indegree[neighbor] == 1)
                        ready.push(neighbor);
            }
        }

        vector<int> result;
        while(!ready.empty()){
            result.push_back(ready.front());
            ready.pop();
        }

        return result;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return { 0 };

        GRAPH adjList(n);
        build_graph(edges, adjList);

        return topoSort(adjList);
    }
};

int main(){

    return 0;
}
