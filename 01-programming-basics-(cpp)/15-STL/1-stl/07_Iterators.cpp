#include<iostream>
#include<iterator>
#include<queue>
using namespace std;

void print_forward(deque<int> &dq){ //print and chance to change elements
    deque<int>::iterator it = dq.begin();
    while(it != dq.end()){
        cout << *it << " ";
        it++;
    }
    cout << "\n";
    return;
}

void print_backward(const auto &dq){ //read-only printing
    auto it = dq.crbegin();
     while(it != dq.crend()){
        cout << *it << " ";
        it++;
     }
     cout << "\n";
}


int main(){
    deque<int> dq {2,4,6,8};
    dq.push_back(1), dq.push_back(3), dq.push_back(11), dq.push_back(21), dq.push_back(5), dq.push_back(7), dq.push_back(18);
    dq.push_front(26), dq.push_front(23), dq.push_front(22), dq.push_front(20), dq.push_front(101), dq.push_front(9), dq.push_front(20);

    auto it = dq.begin();
    cout << *(it += 4) << "\n"; //print 5th element
    *it = 2; //set 5th element to 2
    *it++; //move to next position
    *it += 1000; //add 1000 to it

    print_forward(dq);
    print_backward(dq);

    for(auto it = dq.end(); it!=dq.begin()-1; it--) //We after the last position: so decrement by 1 to be at the right position.
        *it = 0; //reset all to 0

    print_forward(dq);

    return 0;
}
