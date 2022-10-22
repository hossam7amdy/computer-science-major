#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

/*
Another operations-based problem.
The number is a node.
We can convert to another (edge) by
	iterating on the array and applying the 3 operations

Total number of states? O(M) where M = 1001 here

Time complexity? O(N*M) where N is the array length
*/

class Solution {
private:
    const int MIN = 0, MAX = 1000;
    bool isValid(const int &value){
        return MIN <= value && value <= MAX;
    }

    int bfs_path(const vector<int> &nums, const int &start, const int &goal){
        queue<int> q;
        vector<bool> visited(MAX + 1);

        q.push(start);
        visited[start] = true;

        for(int steps = 0, sz = q.size(); !q.empty(); ++steps, sz = q.size()){
            while(sz--){
                int cur = q.front();
                q.pop();

                for(const auto &val : nums){
                    int newVal1 = cur - val, newVal2 = cur + val, newVal3 = cur ^ val;
                    if(newVal1 == goal || newVal2 == goal || newVal3 == goal)
                        return steps + 1;

                    if(!isValid(cur))
                        continue;

                    if(isValid(newVal1) && !visited[newVal1])
                        visited[newVal1] = true, q.push(newVal1);

                    if(isValid(newVal2) && !visited[newVal2])
                        visited[newVal2] = true, q.push(newVal2);

                    if(isValid(newVal3) && !visited[newVal3])
                        visited[newVal3] = true, q.push(newVal3);
                }
            }
        }

        return -1;
    }

public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        return bfs_path(nums, start, goal);
    }
};

int main(){
    return 0;
}
