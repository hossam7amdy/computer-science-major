#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
 * Assume we have original array: 1, 2, 3, 4, 5
 * 	The adjacent might be given as:
 * 		(1, 2), (2, 3), (4, 3), (4, 5)
 *
 * 	Observe: if we thought every number as node, and every pair as an edge
 * 	We end up with a graph that is an undirected chain
 * 	[1-2-3-4-5]
 *
 * 	This means there are 2 possible arrays: [1, 2, 3, 4, 5]  or [5, 4, 3, 2, 1]
 *
 * 	So all what we need to do is to build the graph and finds the chain begin!
 *
 * 	With a simple observation, we can find one of the begins (1 or 5) trivially
 * 	Simple, each node will have 2 neighbors, except 1 or 5. Each will have a single neighbor only
 *
 *
 * 	As the node values are huge, NOT [0, n-1] range, we will use graph based on hash table
 */

// Tip: we can implement this code without visited. We can always do that on trees/chains using parent info

class Solution {
private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    vector<int> cc_nodes;

    void add_edge(const int &from, const int &to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    void build_graph(const vector<vector<int>> &adjPairs){
        for(const auto vec : adjPairs)
            add_edge(vec[0], vec[1]);
    }

    void dfs(const int &node){
        visited.insert(node);
        cc_nodes.push_back(node);

        for(auto neighbor : graph[node])
            if(!visited.count(neighbor))
                dfs(neighbor);
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        build_graph(adjacentPairs);

        for(auto pair : graph){
            if((int)pair.second.size()==1){ // first/last element
                dfs(pair.first);
                break;
            }
        }

        return cc_nodes;
    }
};

int main(){

    vector<vector<int>> t1 {{2,1},{3,4},{3,2}};
    vector<vector<int>> t2 {{4,-2},{1,4},{-3,1}};

    Solution s;
    vector<int> arr = s.restoreArray(t1);

    for(const auto val : arr)
        cout << val << " ";

    return 0;
}
