#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

● Valid: () ()() (()()) {}{} (((()))) ([]) ()[]{} {[]}
● Invalid: (] ()) (][) (] ([)] (])
*/

bool isValid(string str){
    map<char, char> mp;
    mp[')'] = '(';
    mp['}'] = '{';
    mp[']'] = '[';

    stack<char> st;
    for(auto ch : str){
        if(!mp.count(ch))
            st.push(ch);
        else{
            if(st.empty())
                return false;
            if(st.top()!=mp[ch])
                return false;
            st.pop();
        }
    }

    return st.empty();
}

int main(){
    //
    string str;
    while(cin>>str)
        cout << isValid(str) << " ";

    return 0;
}
