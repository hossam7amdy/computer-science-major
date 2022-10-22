#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

///https://leetcode.com/problems/daily-temperatures/
/*
● Given an array, for every number, find the first number after it of a higher value
● E.g. 10, 5, 7, 15, 11 ⇒ 15 7 15 -1 -1
    ○ First number greater than 10 ⇒ 15
    ○ First number greater than 5 ⇒ 7
    ○ First number greater than 7 ⇒ 15
    ○ First number greater than 15 and 11 ⇒ None, so use -1
● Input:
    ○ 8 73, 74, 75, 71, 69, 72, 76, 73 ⇒ 74 75 76 72 72 76 -1 -1
● We can easily solve that with 2 nested loops
● We can solve it with 1 loop using stack. Find it
*/

vector<int> dailyTemperatures(vector<int>& temperatures) { // FOR leetcode
    int sz = temperatures.size();
    stack<int> st;
    vector<int> vec(sz, 0);
    for(int i=1; i<sz; ++i){
        if(temperatures[i-1]<temperatures[i])
            vec[i-1]++;
        else
            st.push(i-1);

        while(!st.empty() && temperatures[st.top()]<temperatures[i]){
            vec[st.top()] = i - st.top();
            st.pop();
            }
        }
    return vec;
}

vector<int> dailyTemperatures1(vector<int>& temperatures) { // FOR homework
    int sz = temperatures.size();
    stack<int> st;
    for(int i=1; i<sz; ++i){
        if(temperatures[i-1]<temperatures[i])
            temperatures[i-1] = temperatures[i];
        else
            st.push(i-1);

        while(!st.empty() && temperatures[st.top()]<temperatures[i])
            temperatures[st.top()]=temperatures[i], st.pop();
        }

    temperatures[sz-1] = -1;
    while(!st.empty()){
        temperatures[st.top()]=-1, st.pop();
    }
    return temperatures;
}

int main(){
    vector<int> vec{73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> myvec {dailyTemperatures(vec)};
    for(auto val : myvec)
        cout << val << " ";

    cout << "\n";

    dailyTemperatures1(vec);
    for(auto ele : vec)
        cout << ele << " ";




    return 0;
}
