#include<iostream>
#include<queue>
using namespace std;

template<class sometype>
void print(priority_queue<sometype> &pq){ //notice if you don't use the reference you just play with a copy.
    while(!pq.empty()){                  //And the queue will remain the same after printing, so be careful.
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(){
    //Main feature: Sort from LARGE to SMALL
    //What about the reverse: SMALL to LARGE
    priority_queue<int> pri_que;

    pri_que.push(1);
    pri_que.push(3);
    pri_que.push(7);
    pri_que.push(9);
    print(pri_que);
    cout << "\nsize = " << pri_que.size();



    return 0;
}
