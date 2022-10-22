#include<iostream>
using namespace std;

//Division using Unary Right-Fold
auto unary_div_right(auto ...args){
    return (args / ...);
}

//Division using Unary Left-Fold
auto unary_div_left(auto ...args){
    return (... / args);
}


int main(){
    cout << unary_div_right(1.0,2.0,3.0,4.0) << "\n";
    cout << unary_div_left<double>(1,2,3,4) << "\n";
    //so be careful when it comes do division
    return 0;
}
