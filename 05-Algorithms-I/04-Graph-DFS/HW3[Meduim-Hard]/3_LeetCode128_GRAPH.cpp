#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;


/*
 *
 * How a consecutive set of numbers represent a graph?
 * Assume we have numbers: [1, 2, 3, 4, 5]
 * We have 4 edges (1, 2), (2, 3), (3, 4), (4, 5)
 *
 * We will take the array and build its undirected graph as following
 * 	For any pair of values (val, val+1), then we have an edge
 *
 *  How to do that efficiently?
 *  	First, create hashset of the values for easy lookup
 *  	then iterate on the values
 *  		For a given val, check if val+1 exists. If so add an edge
 *
 *
 *  Now, every consecutive group of values is a CC, specifically a chain of nodes
 *  1, 2, 3, 6, 7, 8, 9
 *  	(1, 2), (2, 3)
 *  	(6, 7), (7, 8), (8, 9)
 *
 * Remember: in an undirected chain: only the first and last node has 1 neighbor
 * 	We can use them to find the full chain
 *
 * Be careful from an empty graph, or graph of a single node, or unconnected nodes
 * 	Handle them
 *
 *
 * Be careful from duplicate values: 0 0 0 1 1 1 2 2 2
 * 	We should create a single undirected edge (0, 1) NOT 3
 * 		Otherwise, the chain first value may have several neighbors
 *
 *
 * Overall nice idea, but tricky implementation
 * The non-graph based solutions are safer to code!
 */

class Solution {
private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> elements;
    unordered_set<int> visited;

    void add_edge(const int &from, const int &to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    void build_graph(){
        for(const auto &el : elements)
            if(elements.count(el + 1))
                add_edge(el, el + 1);
    }
    int dfs(int node){
        visited.insert(node);

        for(int neighbor : graph[node])
            if(!visited.count(neighbor))
                return 1 + dfs(neighbor);
        return 1;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        if(!(int)nums.size()) return 0;

        for(const auto &it : nums)
            if(!elements.count(it))
                elements.insert(it);

        build_graph();

        int res = 1;
        for(const auto &pair : graph){
            if(!visited.count(pair.first) && (int)pair.second.size()==1)
                res = max(res, dfs(pair.first));
        }

        return res;
    }
};

int main(){
    vector<int> t1 {10, 20};
    vector<int> t2 {-1,-4,0,8,-2,6,-4,-8,9,-2,-6,-6};

    Solution s;
    cout << s.longestConsecutive(t1) << endl;
    cout << s.longestConsecutive(t2) << endl;

    return 0;
}
