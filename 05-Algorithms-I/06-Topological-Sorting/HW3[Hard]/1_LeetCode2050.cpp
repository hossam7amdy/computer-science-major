#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
 * The competition time of topological ordering is a know practical CS problem.
 * Code wise, just minor changes.
 *
 * Assume the following graph
 * 		0-1, 1-2, 3-4, 4-2  with completion times   {10, 20, 7, 15, 5}
 *
 * 	Running the classical topological sort:
 * 		ready: {0, 3}
 * 		Pop 0
 * 		ready {3, 1}
 * 		pop 3
 * 		read {1, 5}
 * 		pop 1
 * 		ready {5}
 * 		pop 5
 * 		ready {2}
 * 		pop 2
 *
 * 		Now node(2) has 2 paths before it:  10+20 and 15+5. node(2) has to wait for them.
 * 			It needs max(30, 20) = 30 BEFORE starting
 * 			then it takes 7 units, for a total 37 for node(2)
 *
 * 		The whole idea is to create vector: completionTime
 * 			Update it during the topological sort to include the full completion time
 *
 * 		We update it in an incremental way
 *
 * 		Let's simulate again:
 * 		Initially competition {0, 0, 0, 0, 0}
 * 		ready: {0, 3}
 * 		Pop 0
 * 			competition[0] = 10			# means I needed 10 time units in the best case
 * 			Now what is the effect of node(0) on its neighbor node(1)?
 * 				node(1) can't start before time(10)
 * 				competition[1] = 10      # means my paths SO FAR need 10 units to finish
 * 		ready {3, 1}
 * 		pop 3
 * 			In a similar logic	competition[3] = 15. competition[4] = 15.   (3 done - 4 not yet)
 * 		read {1, 5}
 * 		pop 1
 * 			Now node(1) is ready. competition[1] = 10 for its paths. time(1) = 20
 * 			So node(1) needs competition[1] += time(1)   ==> competition[1] = 30
 * 			What about neighbor node(2)? We just reached with competition[2] = 30
 * 		ready {5}
 * 		pop 5
 * 			In a similar logic, competition[4] += time(4)  ==> competition[4] = 20
 * 			What about neighbor node(2)?
 * 				We already now it has SO FAR competition[2] = 30  from path 0-1
 * 				But now we have new path which is competition[4] = 20
 *
 * 				However, as we have to wait, then node(2) still needs to wait 30 units
 * 					completionTime[2] = max(completionTime[2], completionTime[4]) = 30
 *
 * 		ready {2}
 * 		pop 2
 * 			completionTime[2] += time(2) ==> 30 + 7 = 37
 *
 * Looks hard? When we learn to do recursion on trees/DAGs, you will get more familiar with that style
 * 	So calm down at the moment :)
 *
 * Take home message:
 * 	When a node wants to aggregate information from all sub-graphs below it (think tree paths)
 *  Then we can process and keepo updating the nodes
 *
 * Note: this problem is easier think/code using recursion (dynamic programming specifically)
 * 		https://leetcode.com/problems/parallel-courses-iii/discuss/1537720/Simple-dfs-%2B-dp
 *
 */

class Solution {
    typedef vector<vector<int>> GRAPH;
    void addDirectedEdge(GRAPH &adjList, const int &from, const int &to){
        adjList[from].push_back(to);
    }
    void buildGraph(GRAPH &adjList, const GRAPH &edges){
        for(const auto p : edges)
            addDirectedEdge(adjList, p[0] - 1, p[1] - 1);
    }

public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        GRAPH adjList(n);
        buildGraph(adjList, relations);

        vector<int> indegree(n, 0);
        for(int i = 0; i < (int)adjList.size(); ++i)
            for(int neighbor : adjList[i])
                indegree[neighbor]++;

        queue<int> ready;
        for(int i = 0; i < n; ++i)
            if(!indegree[i])
                ready.push(i);

        vector<int> completionTime(n, 0);
        while(!ready.empty()){
            int cur = ready.front();
            ready.pop();

            completionTime[cur] += time[cur];
            for(int neighbor : adjList[cur]){
                if(--indegree[neighbor] == 0)
                    ready.push(neighbor);

                completionTime[neighbor] = max(completionTime[cur], completionTime[neighbor]);
            }
        }

        return *max_element(completionTime.begin(), completionTime.end());
    }
};

void test1(){
    int nodes = 3;
    vector<vector<int>> relations = {{1,3},{2,3}};
    vector<int> time = {3,2,5};

    Solution s;
    cout << s.minimumTime(nodes, relations, time) << "\n";
}

void test2(){
    int nodes = 5;
    vector<vector<int>> relations = {{1,5},{2,5},{3,5},{3,4},{4,5}};
    vector<int> time = {1,2,3,4,5};

    Solution s;
    cout << s.minimumTime(nodes, relations, time) << "\n";
}

void test3(){
    int nodes = 9;
    vector<vector<int>> relations = {{2,7},{2,6},{3,6},{4,6},{7,6},{2,1},{3,1},{4,1},{6,1},{7,1},{3,8},{5,8},{7,8},{1,9},{2,9},{6,9},{7,9}};
    vector<int> time = {9,5,9,5,8,7,7,8,4};

    Solution s;
    cout << s.minimumTime(nodes, relations, time) << "\n";
}

int main(){
    test1();
    test2();
    test3();

    return 0;
}
