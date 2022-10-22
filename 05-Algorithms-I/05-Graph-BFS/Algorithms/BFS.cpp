#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> adjList;
const int OO{ INT_MAX };

void add_undirected_edge(adjList &adjList, const int &from, const int &to){
    adjList[from].push_back(to);
    adjList[to].push_back(from);
}

vector<int> BFS_v1(const adjList &adjList, int start){
    queue<pair<int, int>> nodes;
    vector<int> len((int)adjList.size(), OO);

    nodes.push( { start, 0 } );
    len[start] = 0;

    while(!nodes.empty()){
        auto pair = nodes.front();
        nodes.pop();

        int node = pair.first, level = pair.second;

        for(const auto &neighbor : adjList[node]){
            if(len[neighbor] == OO){
                nodes.push({ neighbor, level + 1} );
                len[neighbor] = level + 1;
            }
        }
    }

    return len;
}

vector<int> BFS_v2(const adjList &adjList, int start){
    queue<int> nodes;
    vector<int> len((int)adjList.size(), OO);

    nodes.push(start);
    len[start] = 0;

    for(int level = 0, sz = 1; !nodes.empty(); sz = (int)nodes.size(), ++level){
        while(sz--){
            int cur = nodes.front();
            nodes.pop();

            for(const auto &neighbor : adjList[cur]){
                if(len[neighbor] == OO){
                    nodes.push(neighbor);
                    len[neighbor] = level + 1;
                }
            }
        }
    }

    return len;
}

int main(){
    adjList adjList(9);
    add_undirected_edge(adjList, 1,3);
    add_undirected_edge(adjList, 1,5);
    add_undirected_edge(adjList, 1,6);
    add_undirected_edge(adjList, 3,5);
    add_undirected_edge(adjList, 3,4);
    add_undirected_edge(adjList, 3,7);
    add_undirected_edge(adjList, 6,0);
    add_undirected_edge(adjList, 4,2);
    add_undirected_edge(adjList, 0,2);
    add_undirected_edge(adjList, 2,8);

    vector<int> len(BFS_v2(adjList, 1));

    for(const auto l : len)
        cout << l << " ";

    return 0;
}
