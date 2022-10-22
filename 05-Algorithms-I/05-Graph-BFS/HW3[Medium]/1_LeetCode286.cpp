#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

/*
We can brute force this problem by running BFS from every room! Can we do better?

Observe: each room can be connected to one of the nearest gates
		 but each gate can be used by many rooms, if it is their shortest gate

This motivates reverse thinking:
	Don't start from the room to find a SINGLE matching gate (the first nearest)
	Start from the gate to find its distance to each room (1 to many relationship)

Now how can we do this problem in O(ROWS * COL)?

This can be named: multi-source BFS
	In this variant, we have many starting points at the same time (the gates here)
	We simply add them to the queue and run the normal BFS
	So instead of a single start, we add all possible starting

	This means in level 1: each gate find the rooms of 1 step distance
	This means in level 2: each gate find the rooms of 2 steps distance
	And so on
	Hence, the first gate reach a room, then this is its shortest distance

Convenience yourself by tracing some examples
The whole idea, instead of doing one by one, we do them together
The advantage, each cell is marked as visited once.

Take home lesson: If we have multiple starts, we just add them to the queue

 */

class Solution{
private:
    int ROWS, COLS;
    int gate = 0, obstacle = -1, free = INT_MAX;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};

    struct cell{
        int r, c;
        cell(const int &r, const int &c):
            r(r), c(c){
        }
    };

    bool validDir(const int &r, const int &c){
        return 0 <= r && r < ROWS && 0 <= c && c < COLS;
    }

    void shortestPath(vector<vector<int>>& rooms, queue<cell> &gates){
        for(int steps = 1, sz = (int)gates.size(); !gates.empty(); ++steps, sz = (int)gates.size()){
            while(sz--){
                cell cur = gates.front();
                gates.pop();

                for(int d = 0; d < 4; ++d){
                    int nr = cur.r + dr[d];
                    int nc = cur.c + dc[d];

                    if(!validDir(nr, nc) || rooms[nr][nc] != free)
                        continue;

                    rooms[nr][nc] = steps;
                    gates.push(cell(nr, nc));
                }
            }
        }
    }

public:
     void wallsAndGates(vector<vector<int>>& rooms){
         ROWS = (int)rooms.size();
         COLS = (int)rooms[0].size();

         queue<cell> gates;
         for(int r = 0; r < ROWS; ++r)
            for(int c = 0; c < COLS; ++c)
                if(rooms[r][c] == gate)
                    gates.push(cell(r,c));

        shortestPath(rooms, gates);
     }
};


void print(const auto &rooms){
    for(const auto &row : rooms){
        for(const auto &col : row)
            cout << col << " ";
        cout << "\n";
    }
}

void test1(){
    vector<vector<int>> rooms = {{2147483647, -1, 0, 2147483647},
                                 {2147483647, 2147483647, 2147483647, -1},
                                 {2147483647, -1, 2147483647, -1},
                                 {0, -1, 2147483647, 2147483647}};

    Solution s;
    s.wallsAndGates(rooms);

    print(rooms);
}

void test2(){
    vector<vector<int>> rooms = {{-1}};

    Solution s;
    s.wallsAndGates(rooms);

    print(rooms);
}

void test3(){
    vector<vector<int>> rooms = {{2147483647}};

    Solution s;
    s.wallsAndGates(rooms);

    print(rooms);
}

void test4(){
    vector<vector<int>> rooms = {{0}};

    Solution s;
    s.wallsAndGates(rooms);

    print(rooms);
}

int main(){
    test1();
    test2();
    test3();
    test4();

    return 0;
}
