#include<iostream>
#include<set>
#include<map>
using namespace std;

class Edge {
private:
    string destination;
    int cost{};
public:
    Edge(const string &destination, const int &cost):
        destination(destination), cost(cost){
    }

    void print() const {
        cout << "\tTo " << destination << " with cost " << cost << endl;
    }

    bool operator < (const Edge &e) const {
        if(destination != e.destination)
            return destination < e.destination;

        return cost < e.cost;
    }
};

typedef map<string, multiset<Edge>> GRAPH; // Ordered and allow duplicated (SELF-BALANCED TREE)

void add_destination(GRAPH &airport, const string &source, const string &destination, const int &cost){
    airport[source].insert(Edge(destination, cost));
}

void show_airport_list(const GRAPH &airport) {
    for(auto source : airport) {
        cout << "Flights from " << source.first << ":\n";
        for(auto destinaton : source.second)
            destinaton.print();
    }
}

int main(){
    GRAPH airport;

    int nodes, edges;
    cin >> nodes >> edges;

    for(int e = 0; e < edges; e++){
        string source, dest;
        int cost;
        cin >> source >> dest >> cost;
        add_destination(airport, source, dest, cost);
    }

    show_airport_list(airport);

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

Output
Flights from California:
	To Florida with cost 75
	To Pennsylvania with cost 37
	To Texas with cost 10
	To Texas with cost 30
	To Texas with cost 35
Flights from Florida:
	To California with cost 70
Flights from NewYork:
	To California with cost 35
Flights from Pennsylvania:
	To Florida with cost 18
	To Florida with cost 28

 */
