#include<iostream>
#include<vector>
using namespace std;

class Solution {
    typedef vector<vector<int>> GRAPH;

    void addDirectedEdge(GRAPH &adjList, const int &from, const int &to){
        adjList[from].push_back(to);
    }

    void dfs(const GRAPH &adjList, int &node, vector<int> &start, vector<int> &finish, vector<int> &result, int &time){
        start[node] = ++time;

        for(auto neighbor : adjList[node]){
            if(start[neighbor] == -1)
                dfs(adjList, neighbor, start, finish, result, time);
            else if(finish[neighbor] == -1)
                return;
        }
        result.push_back(node);
        finish[node] = ++time;
    }
public:
    bool canFinish(int numCourses, GRAPH& prerequisites) {
        GRAPH adjList(numCourses);
        for(const auto &p : prerequisites)
            addDirectedEdge(adjList, p[0], p[1]);

        vector<int> start(numCourses, -1);
        vector<int> finish(numCourses, -1);

        int time = 0;
        vector<int> result;
        for(int i = 0; i < numCourses; ++i)
            if(start[i] == -1)
                dfs(adjList, i, start, finish, result, time);

        if((int)result.size() != numCourses)
            return false;

        return true;
    }
};


int main(){
    return 0;
}
