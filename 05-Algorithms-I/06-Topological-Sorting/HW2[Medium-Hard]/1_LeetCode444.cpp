// https://leetcode.com/problems/sequence-reconstruction/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

/*
 * We can reduce this problem to a graph as following:
 * Think in every sequence [1, 2, 3, 4] as a directed path: e.g. (1, 2), (2, 3) and (3, 4)
 *
 * Think about the relationship of topological ordering of this graph and the super-sequence:
 * 	The topological graph will:
 * 		have all the graph nodes
 * 		The ordering will respect the paths
 *
 * So all what we need to do:
 * 		Make sure there is a unique topological sort (super-sequence)
 *
 * We know there can be many topological sort
 * Can we know if there is a SINGLE UNIQE ordering?
 * Yes trivial. The queue MUST always have a single node.
 * 		This means in every step, we can only choose this node
 *
 * So adjust the topological to return empty vector if also there is more than a solution
 * As the vertices are huge AND many values is NOT part of the graph,
 * 	we should use a hash table. So adjust the code for that
 *
 * One bug source, sequences of a single element: e.g. [ [1], [7] ]
 *
 * Note: the org is a permutation with UNIQUE elements.
 * 	Without that, we can't use topological sort, which output UNIQUE values
 *
 * Note: if this problem is only asking if this is a valid super-sequence,
 * 	I think it will be developed similar to LeetCode 792 - Number of Matching Subsequences
 * 	We discuss it later in the interviews course
 *  Think about a non-graph solution for this case
 */

class Solution {
private:
    typedef unordered_map<int, vector<int>> GRAPH;

    void add_directed_edge(GRAPH &adjList, const int &from, const int &to){
        adjList[from].push_back(to);
    }

    vector<int> topoSort(GRAPH &adjList){
        unordered_map<int, int> indegree;
        for(auto &nodeNeighbors : adjList)
            for(auto &neighbor : nodeNeighbors.second)
                indegree[neighbor]++;

        queue<int> ready;
        for(auto &node : adjList)
            if(!indegree.count(node.first))
                ready.push(node.first);

        vector<int> sorting;
        while((int)ready.size() == 1){
            int cur = ready.front();
            ready.pop();
            sorting.push_back(cur);

            for(const auto &neighbor : adjList[cur])
                if(--indegree[neighbor] == 0)
                    ready.push(neighbor);
        }

        return sorting;
    }
public:
     bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        GRAPH adjList;
        for(int i = 0; i < (int)seqs.size(); ++i){
            if(seqs[i].empty())
                adjList[i] = vector<int>();
            for(int j = 0; j + 1 < (int)seqs[i].size(); ++j)
                add_directed_edge(adjList, seqs[i][j], seqs[i][j + 1]);
        }

        vector<int> sorted = topoSort(adjList);

        //for(int val : sorted)
            //cout << val << " ";

        return sorted == org;
    }
};

void test1(){
    vector<int> org = {1,2,3};
    vector<vector<int>> seqs = {{1,2}, {1,3}};

    Solution s;
    cout << s.sequenceReconstruction(org, seqs) << endl;
}

void test2(){
    vector<int> org = {1,2,3};
    vector<vector<int>> seqs = {{1,2}};

    Solution s;
    cout << s.sequenceReconstruction(org, seqs) << endl;
}

void test3(){
    vector<int> org = {1,2,3};
    vector<vector<int>> seqs = {{1,2},{1,3},{2,3}};

    Solution s;
    cout << s.sequenceReconstruction(org, seqs) << endl;
}

void test4(){
    vector<int> org = {4,1,5,2,6,3};
    vector<vector<int>> seqs = {{5,2,6,3},{4,1,5,2}};

    Solution s;
    cout << s.sequenceReconstruction(org, seqs) << endl;
}

void test5(){ // has cycle: 1 => 2 => 3 => 1
    vector<int> org = {1,2,3};
    vector<vector<int>> seqs = {{1,2},{2,3},{3,1}};

    Solution s;
    cout << s.sequenceReconstruction(org, seqs) << endl;
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
