#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;

///https://leetcode.com/problems/asteroid-collision/

/*
Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

Example 4:
Input: asteroids = [-2,-1,1,-2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.
*/

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for(auto val : asteroids){
        bool flag = true;
        while(!st.empty() && st.top()>0 && val<0){
            if(st.top()>abs(val)){
                flag = false;
                break;
            }
            else if(abs(val)==st.top()){
                st.pop();
                flag = false;
                break;
            }
            else
                st.pop();
        }
        if(flag)
            st.push(val);
    }

    asteroids.clear();
    while(!st.empty())
        asteroids.push_back(st.top()), st.pop();
    reverse(asteroids.begin(), asteroids.end());
    return asteroids;
}

int main(){
    vector<int> vec{-2,-1,1,-2};
    asteroidCollision(vec);
    for(auto ele : vec)
        cout << ele << " ";

    return 0;
}
