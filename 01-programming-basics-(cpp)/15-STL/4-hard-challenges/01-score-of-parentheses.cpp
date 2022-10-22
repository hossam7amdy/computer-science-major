#include<iostream>
#include<bits/stdc++.h>
using namespace std;

///https://leetcode.com/problems/score-of-parentheses/
/*
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule.
"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.


Example 1:
    Input: s = "()"
    Output: 1

Example 2:
    Input: s = "(())"
    Output: 2

Example 3:
    Input: s = "()()"
    Output: 2

Example 4:
    Input: s = "(()(()))"
    Output: 6
*/

int scoreOfParentheses(string s) { //TODO later
    stack<char> st;
    int num = 0;
    char prev = '(';
    for(auto ch : s){
        if(ch==prev)
            num *= 2;
        else if(ch!=prev)
            num+=1;
        prev = ch;
    }
    return num;
}

int main(){
    cout << scoreOfParentheses("(()(()))");

    return 0;
}
