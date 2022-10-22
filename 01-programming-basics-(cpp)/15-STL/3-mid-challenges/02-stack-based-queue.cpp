#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Stack based on a queue
● We need to implement stack
● But we will make use of the available queue data structure
● Fill the push methods such that the struct behave as it is a stack
● Don’t define other struct variables.
    Only this queue<int>
● E.g. this code should print: 3 2 1
*/

struct OurStack{
    queue<int> q;
    //
    void push(int val){
        q.push(val);
        int sz = q.size();

        while(sz>1){ //if more than 1: start swapping
            int temp = q.front();
            q.pop();
            q.push(temp);
            sz--;
        }
        return;
    }

    void pop(){
        if(!q.empty()){
            q.pop();
        }
    }

    int top(){
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};


int main(){
    OurStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while(!st.empty())
        cout << st.top() << " ", st.pop();

    return 0;
}
