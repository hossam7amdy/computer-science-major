#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
    typedef vector<vector<int>> GRAPH;
    void addDirectedEdge(GRAPH &adjList, const int &from, const int &to){
        adjList[from].push_back(to);
    }
    void buildGraph(GRAPH &adjList, const GRAPH &edges){
        for(const auto p : edges)
            addDirectedEdge(adjList, p[0], p[1]);
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int nodes = (int)colors.length();
        GRAPH adjList(nodes);
        buildGraph(adjList, edges);

        vector<int> indegree(nodes, 0);
        for(int i = 0; i < (int)adjList.size(); ++i)
            for(int neighbor : adjList[i])
                indegree[neighbor]++;

        queue<int> ready;
        for(int i = 0; i < nodes; ++i)
            if(!indegree[i])
                ready.push(i);

        const int LETTERS = 26;
        int popedNodes = 0, result = 0;
        vector<vector<int>> colFreq(nodes, vector<int>(LETTERS, 0));
        while(!ready.empty()){
            int node = ready.front(), color = colors[node] - 'a';
            ready.pop();
            ++popedNodes;
            ++colFreq[node][color];

            result = max(result, colFreq[node][color]);
            for(int neighbor : adjList[node]){
                if(--indegree[neighbor] == 0)
                    ready.push(neighbor);

                // Update my neighbors that I can reach you with this set of colors frequencies
			for (int col = 0; col < 26; ++col)
				colFreq[neighbor][col] = max(colFreq[neighbor][col], colFreq[node][col]);

            }


        }

        if(popedNodes != nodes)
            return -1;

        return result;
    }
};

void test1(){
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};
    string colors = "abaca";

    Solution s;
    cout << s.largestPathValue(colors, edges) << "\n";
}

void test2(){
    vector<vector<int>> edges = {{0,0}};
    string colors = "a";

    Solution s;
    cout << s.largestPathValue(colors, edges) << "\n";
}

int main(){
    test1();
    test2();

    return 0;
}
