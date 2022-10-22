// https://leetcode.com/problems/course-schedule/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    /// Complexity ///
* O(N) space complexity for the queue: max N nodes
* O(E+V) time complexity for an adjacency list
    - First block iterates on whole graph: O(E+V)
    - Second block is just iterating on nodes: O(N)
    - While loop executed maximum N times
        > Only new nodes are added to the queue during processing
    - The internal loop:
        > Aggregate across all the nodes (as in dfs/bfs) is just O(E)
    - So total O(E+V)
* Correctness: the same as the previous lecture
    - Formally, we need to justify the matching between the idea and the code
*/

class Solution {
    typedef vector<vector<int>> GRAPH;

    void add_directed_edge(GRAPH &adjList, const int &from, const int &to){
        adjList[from].push_back(to);
    }

    vector<int> topoSort(const GRAPH &adjList){ // O(V+E)
        int nodes = (int)adjList.size();

        vector<int> inDegrees(nodes, 0); // O(V)
        for(int node = 0; node < nodes; ++node)
            for(int edge : adjList[node])
                inDegrees[edge]++;

        queue<int> ready; // MAX of O(V)
        for(int edge = 0; edge < nodes; ++edge) // initial edges
            if(!inDegrees[edge])
                ready.push(edge);

        vector<int> ordering;
        while(!ready.empty()){
            int cur = ready.front();
            ready.pop();

            ordering.push_back(cur);

            for(int neighbor : adjList[cur])
                if(--inDegrees[neighbor] == 0)
                    ready.push(neighbor);
        }
        return ordering;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        GRAPH courses(numCourses);
        for(const auto &p : prerequisites)
            add_directed_edge(courses, p[0], p[1]);

        vector<int> ordering = topoSort(courses);

        return (int)ordering.size() == numCourses;
    }
};

int main(){
    int numCourses = 9;
    vector<vector<int>> prerequisites = {{0,1},{1,2},{2,3},{2,4},{5,0},{5,7},{6,7},{6,8},{7,2},{8,2}};

    Solution s;
    cout << s.canFinish(numCourses ,prerequisites) << endl;



    return 0;
}
