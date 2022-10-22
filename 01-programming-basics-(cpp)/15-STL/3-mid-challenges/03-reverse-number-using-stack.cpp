#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Reverse a number using stack
● Implement a method that takes number >= 0 and reverse its digits using a stack
● int reverse_num(int num)
● E.g. Input: 1234, Output: 4321
*/

int reverse_num(int num){
    stack<int> st;
    while(num)
        st.push(num%10), num/=10;

    int tens = 1; //save its position
    while(!st.empty())
        num = st.top() * tens + num, tens*=10, st.pop();

    return num;
}


int main(){
    cout << reverse_num(1234);

    return 0;
}
