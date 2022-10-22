// https://leetcode.com/problems/course-schedule-ii/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    typedef vector<vector<int>> GRAPH;

    void add_directed_edge(GRAPH &adjList, int from, int to){
        adjList[from].push_back(to);
    }

    vector<int> topoSort(const GRAPH &adjList){
        int nodes = (int)adjList.size();

        vector<int> indegree(nodes);
        for(int n = 0; n < nodes; ++n)
            for(int edge : adjList[n])
                indegree[edge]++;

        // The lexicographical order
        priority_queue<int, vector<int>, greater<int>> ready;
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
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        GRAPH courses(numCourses);
        for(const auto &p : prerequisites)
            add_directed_edge(courses, p[1], p[0]);

        return topoSort(courses);
    }
};

int main(){

    return 0;
}
