#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

/*

Another operations-based problem. Node this time a string!
	if there is an operation that converts the string to another, then this is the edge

Hence, all what you need is to do BFS from the start string till finding the target string in this graph!
As we use strings, use hashtable unordered_set to mark visited
The deadends can be simply added to our visited set!

Tip: Carefully verify the start string/deadends

Let D = Number of digits. How many states we can have?
	4 letters each is 10 values ==> 10^4  (10^D)
	This part is what really matters

We generate the children in O(D)

So in total O(D * 10^D)
D is constant anyway

Why this matters? To be sure number of states are reasonable

Tip: In C++, we can change the index value in O(1).
     In langauges where the string is immutable, we construct the whole string!
*/

class Solution {
private:
    char up(char &ch){
        ch = (ch - '0') + 1;
        if(ch > 9)
            return '0';
        return ch + '0';
    }
    char down(char &ch){
        ch = (ch - '0') - 1;
        if(ch < 0)
            return '9';
        return ch + '0';
    }
    vector<string> getCompination(const string &cur){
        vector<string> compinations;

        for(int i = 0; i < (int)cur.size(); ++i){
            string start = cur;
            start[i] = up(start[i]);
            compinations.push_back(start);

            start = cur;
            start[i] = down(start[i]);
            compinations.push_back(start);
        }

        return compinations;
    }

    bool isDeadend(const vector<string> &deadends, const string &comp){
        for(const auto &dead : deadends)
            if(comp == dead)
                return true;
        return false;
    }

    int BFS(const vector<string> &deadends, const string &start, const string &target){
        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        for(int steps = 0, sz = (int)q.size(); !q.empty(); ++steps, sz = (int)q.size()){
            while(sz--){
                string cur = q.front();
                q.pop();

                vector<string> cur_comps = getCompination(cur);
                for(const auto &comp : cur_comps){
                    // cout << comp << " ";
                    if(comp == target)
                        return steps + 1;

                    if(visited.count(comp) || isDeadend(deadends, comp))
                        continue;

                    q.push(comp);
                    visited.insert(comp);
                }
            }
        }

        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        string start {"0000"};

        if(start == target)
            return 0;
        if(isDeadend(deadends, start))
            return -1;

        return BFS(deadends, start, target);
    }
};

int main(){

    return 0;
}
