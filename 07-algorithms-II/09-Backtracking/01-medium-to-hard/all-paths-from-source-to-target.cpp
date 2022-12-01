#include<bits/stdc++.h>
using namespace std;

void backtrack(const vector<vector<int>> &graph, int start, int end,
                vector<int> &curPath, vector<vector<int>> &paths){

    if(start == end){
        paths.push_back(curPath);
        return;
    }

    for(int child : graph[start]){
        curPath.push_back(child);
        backtrack(graph, child, end, curPath, paths);
        curPath.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {
    vector<int> curPath;
    vector<vector<int>> paths;

    curPath.push_back(0);
    backtrack(graph, 0, graph.size() - 1, curPath, paths);

    return paths;
}

int main() {
    allPathsSourceTarget({{4,3,1},{3,2,4},{},{4},{}});

    return 0;
}
