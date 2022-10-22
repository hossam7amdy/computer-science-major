#include<iostream>
#include<queue>
using namespace std;



int main(){
    //Two pairs of any data type.
    priority_queue<pair<int, string>> pq;
    pq.push(make_pair(100, "Hossam"));
    pq.push(make_pair(110, "Ahmed"));
    pq.push(make_pair(100, "Emad"));
    pq.push(make_pair(102, "Doaa"));

    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    cout << pq.size();

    return 0;
}
