#include<iostream>
using namespace std;

/// p1: Length of 3n+1
int len_3nplus1(const int &n){
    if(n==1)
        return 1;
    if(n%2==0)
        return 1 + len_3nplus1(n/2);
    else
        return 1 + len_3nplus1(3*n+1);
}

/// p2: Power Function
int pow(const int &n, int p = 2){
    if(p == 0)
        return 1;
    return n * pow(n,p-1);
}

int main(){
    cout << len_3nplus1(6) << endl;
    cout << pow(6) << endl;

    return 0;
}
