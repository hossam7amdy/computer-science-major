#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Reverse a queue using a stack
● Implement a function that reverses a queue. Use a stack for this propose.
● void reverse_queue(queue<int>& q)
INPUT: 1 2 3
OUTPUT: 3 2 1
*/

void reverse_queue(queue<int>& q){
    stack<int> st;
    while(!q.empty()) //first in first out
        st.push(q.front()), q.pop();

    while(!st.empty()) //last in first out
        q.push(st.top()), st.pop();
    return;
}



int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4), q.push(5), q.push(5), q.push(5);
    reverse_queue(q);
    while(!q.empty())
        cout << q.front() << " ", q.pop();

    return 0;
}
