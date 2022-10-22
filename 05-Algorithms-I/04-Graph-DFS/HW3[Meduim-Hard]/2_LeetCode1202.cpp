#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
 * Imagine we have pairs representing (0, 3), (3, 6), (6, 9), (9, 12)
 *
 * Given that we can swap the characters at any pair of indices in the given pairs any number of times
 * This means, we can move any character in the chain of indices [0, 3, 6, 9, 12]
 *
 * Imagine that every pair is a graph edge, then in every component, we can order its character in whatever order
 * Please find try some examples to convenience yourself
 *
 * Now we can do the following:
 * 	1- Build the undirected graph
 * 	2- Find CCs
 * 	3- For each CC, order its characters to be smallest lexicographically (aka sorted)
 *
 * 	Nodes are huge, keep the graph processing linear in terms of E/V
 */

class Solution {
private:
    void add_edge(vector<vector<int>> &graph, const int &from, const int &to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // Coding tip: Keep your functions standard for reusability
    void dfs(const vector<vector<int>> &graph, vector<bool> &visited, vector<int> &cc_nodes, int node){
        visited[node] = true;
        cc_nodes.push_back(node);

        for(const int &neighbor : graph[node])
            if(!visited[neighbor])
                dfs(graph, visited, cc_nodes, neighbor);
    }

public:
    string smallestStringWithSwaps(string s, const vector<vector<int>>& pairs) {
        int nodes = (int)s.length();
        vector<vector<int>> graph(nodes);

        // construct the graph
        for(const auto &vec : pairs)
            add_edge(graph, vec[0], vec[1]);


        vector<bool> visited(nodes);
        for(int node = 0; node < nodes; ++node){
            if(!visited[node]){
                vector<int> cc_nodes;
                dfs(graph, visited, cc_nodes, node);

                string cc_str;
                for(int node : cc_nodes)
                    cc_str += s[node];

                sort(cc_nodes.begin(), cc_nodes.end());
                sort(cc_str.begin(), cc_str.end());

                for(int idx = 0; idx < (int)cc_nodes.size(); ++idx)
                    s[cc_nodes[idx]] = cc_str[idx];
            }
        }

        return s;
    }
};

int main(){
    Solution s;
    cout << s.smallestStringWithSwaps("dcab", {{0,3},{1,2}}) << "\n";

    return 0;
}
