#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

/*
 * The key idea here, the graph is NOT N nodes, it 2N nodes
 * Specifically, each node is
 * 		One of the N nodes ( to N-1 idx)
 * 		A color: red or blue
 *
 * When a node is not a single value, we may call it a state
 * So the graph has N states, each state is idx and color
 *
 * The best way to work on states is to keep them as states,
 * 		e.g. don't covert to full explicit graph of 2N nodes
 *
 * Now, the task is pretty direct. Do bfs on this N states (or 2N nodes) graph and compute shortest path
 *
 * To work on the states: the queue is queue of states (idx, color)
 * 		Similarly, the visited array is N*2 cells
 *
 * Edge (y, z) exists IFF its color is different from the used color on edge (x, y)
 *
 * Take home lessons:
 * 		This is a state graphs: so each node has several sub-elements
 * 		Think how to generate the neighbor states from the current state
 */

class Solution {
    const char RED = 0;
    const char BLUE = 1;

    struct node{
        int id;
        char col;
        node(const int &id, const char &col):
            id(id), col(col){
        }
    };

    typedef vector<vector<node>> GRAPH;

    void add_directed_edge(GRAPH &graph, const int &id, const node &to){
        graph[id].push_back(to);
    }
    void build_graph(GRAPH &graph, const vector<vector<int>> &edges, const char &ch){
        for(const auto &vec : edges)
            add_directed_edge(graph, vec[0], node(vec[1], ch));
    }

    void bfs_path(const GRAPH &graph, vector<int> &res, const int &start){
        queue<node> q;
        vector<vector<bool>> vis((int)graph.size(), vector<bool>(2,0));

        q.push(node(start, RED));
        q.push(node(start, BLUE));

        res[start] = 0;
        vis[start][RED] = vis[start][BLUE] = true;

        for(int level = 1, sz = (int)q.size(); !q.empty(); ++level, sz = (int)q.size()){
            while(sz--){
                node cur = q.front();
                q.pop();

                for(node neighbor : graph[cur.id]){
                    if(neighbor.col != cur.col && !vis[neighbor.id][neighbor.col]){
                        if(res[neighbor.id] == -1)
                            res[neighbor.id] = level;

                        q.push(neighbor);
                        vis[neighbor.id][neighbor.col] = true;
                    }
                }
            }
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        GRAPH graph(n);
        build_graph(graph, redEdges, RED);
        build_graph(graph, blueEdges, BLUE);

        vector<int> res(n, -1);
        bfs_path(graph, res, 0);

        return res;
    }
};

int main(){

    return 0;
}
