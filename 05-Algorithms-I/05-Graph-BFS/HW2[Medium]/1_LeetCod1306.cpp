#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
Operation-based problems are very common. So here is the "pattern"

We have some item (number, string, object)
We have an operation to apply to get a new item
Each item is a node. Each valid operation builds a (directed) edge

We may call the graph a state graph (like a state diagram in SWE)
A critical step is to count the total number of states
	- important to understand the complexity
	- We need a visited array

Tip: Sometimes, the total number of states are huge.
	 But as we BFS and stop early, we don't explore all the graph


In this problem, the nodes are indices and each node has 2 neighbors from 2 conversions

The number of states are just O(N), where N = array size

O(N) time and memory

Note: in my coding style, I verify entering elements before adding to the queue
This means, if you need special cases on the start, they must be done on the start node(s)

*/

class Solution {
    bool isValid(const int &idx, const int &sz){
        return 0 <= idx && idx < sz;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        if(!arr[start])
            return true;

        const int sz = (int)arr.size();
        queue<int> q;
        vector<bool> vis(50001, 0);

        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            int left = cur + arr[cur];
            if(isValid(left, sz) && !vis[left]){
                if(!arr[left])
                    return true;
                q.push(left);
                vis[left] = true;
            }

            int right = cur - arr[cur];
            if(isValid(right, sz) && !vis[right]){
                if(!arr[right])
                    return true;
                q.push(right);
                vis[right] = true;
            }
        }

        return false;
    }
};

int main(){


    return 0;
}
