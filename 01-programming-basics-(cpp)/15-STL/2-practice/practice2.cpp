#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
● Given 3 stack of positive numbers. You may remove some items from the top
of them. The target is the sum of all stacks is equal and maximum.
● Let’s say the 3 stacks as following (remove from end)
    ○ A = {1, 2, 3, 4};
    ○ B = {2, 2, 2, 4, 0};
    ○ C = {0, 3, 3, 5};
    ○ Initial sums are: 10, 10, 11 ⇒ Not equal
    ○ If we remove top element from A (4), top 2 from B (0, 4) and top from C (5) ⇒ 6, 6, 6 = max
● What if we have initial C as {12, 3, 3, 5}. Maximum possible sum is 0 :(
● Implement: int max_3stack_sum(vector<int> &a, vector<int> &b, vector<int> &c)
    ○ A, B, C acts like a stack. E.g. a values = {1, 2, 3, 4} and b = {2, 2, 2, 4, 0}

*/

int sum(auto &vec){
    int sum = 0;
    for(auto val : vec)
        sum += val;
    return sum;
}

int max_3stack_sum(vector<int> &a, vector<int> &b, vector<int> &c){
    int sum1 {sum(a)};
    int sum2 {sum(b)};
    int sum3 {sum(c)};

    while(true){
        if(sum1>sum2 || sum1>sum3)
            sum1-= a.back(), a.pop_back();
        else if(sum2>sum1 || sum2>sum3)
            sum2-= b.back(),b.pop_back();
        else if(sum3>sum1 || sum3>sum2)
            sum3-= c.back(),c.pop_back();
        else
            break;
    }
    return sum1;
}



int main(){
    vector<int> a{1,2,3,4}, b{2,2,2,4,0}, c{12,3,3,5};
    cout << max_3stack_sum(a,b,c);

    return 0;
}
