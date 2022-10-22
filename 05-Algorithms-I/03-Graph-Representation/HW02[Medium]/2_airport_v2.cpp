#include<iostream>
#include<vector>
#include<map>
using namespace std;

class ObjectIdMapper{
private:
    map<int,string> id_to_str;
    map<string,int> str_to_id;
public:
    int getId(const string &str) {
        if(str_to_id.count(str))
            return str_to_id[str];

        int id = str_to_id.size();
        id_to_str[id] = str;
        str_to_id[str] = id;

        return str_to_id[str];
    }

    string getStr(const int &id) {
        return id_to_str[id];
    }
};

struct Edge{
    int to{};
    int cost{};

    Edge(const int &to, const int &cost):
        to(to), cost(cost){
    }
};
typedef vector<vector<Edge>> GRAPH;
void add_to(GRAPH &graph, const int &from, const int &to, const int &cost) {
    graph[from].push_back({to, cost});
}
void print_adjaceny_matrix(GRAPH &graph, ObjectIdMapper &mapper) {
    for(int node = 0; node < (int)graph.size(); node++){
        cout << "Flights from " << mapper.getStr(node) << ":\n";
        for(int edge = 0; edge <(int)graph[node].size(); edge++)
            cout << "\t(To " << mapper.getStr(graph[node][edge].to) << " with cost " << graph[node][edge].cost << ")\n";
    }
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH airport(nodes);
    ObjectIdMapper mapper;

    for(int e = 0; e < edges; e++){
        string source, dest;
        int cost;
        cin >> source >> dest >> cost;

        int from = mapper.getId(source);
        int to = mapper.getId(dest);

        add_to(airport, from, to, cost);
    }

    print_adjaceny_matrix(airport, mapper);

    cout << "\nNO RTE";

    return 0;
}

/*

5 9
California Texas 30
California Texas 10
Florida California 70
California Florida 75
NewYork California 35
Pennsylvania Florida 18
Pennsylvania Florida 28
California Texas 35
California Pennsylvania 37


Flights from California:
        (To Texas with cost 30)
        (To Texas with cost 10)
        (To Florida with cost 75)
        (To Texas with cost 35)
        (To Pennsylvania with cost 37)
Flights from Texas:
Flights from Florida:
        (To California with cost 70)
Flights from NewYork:
        (To California with cost 35)
Flights from Pennsylvania:
        (To Florida with cost 18)
        (To Florida with cost 28)

NO RTE

 */
