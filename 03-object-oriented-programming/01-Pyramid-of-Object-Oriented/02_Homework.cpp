#include<iostream>
using namespace std;

// Looping
int sum_1_to_n(int n){
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += i;
    return sum;
}

// Formula
int sum_1_to_n(int n){
    return n * (n+1) / 2;
}

///Dr's Tips:
/*
In many cases, the same task can be done in several ways
- Some are clearly written and some are not
- Fast or slow
- Memory hungry or reasonable
- Heavy computations (your mobile become hot) or more efficient
- Consume your mobile data package (video call) or save it!

It is not easy to build efficient software!
*/

int main(){
    cout << sum_1_to_n(5);

    return 0;
}
