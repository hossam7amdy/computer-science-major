#include<iostream>
using namespace std;

template<class Function>
auto sum_square(Function op, auto...args){
    return (op(args) + ... + 0);
}

int sqr(int x){
    return x * x;
}

int main(){
    int val = sum_square(sqr, 1,2,3,4);

    cout << val;

    return 0;
}
