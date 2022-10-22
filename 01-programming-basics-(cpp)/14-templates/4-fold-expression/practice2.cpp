#include<iostream>
using namespace std;


//Unary Left-Fold
auto multiply(auto ...args){
    return (... * args);
}

//Binary Left-Fold
auto multiply_empty(auto ...args){
    return (1 * ... * args);
}


int main(){
    cout << multiply(1,2,3,4,5) << "\n";
    // ( ... * 5)
    // (( ... * 4) * 5)
    // ((( ... * 3 ) * 4) * 5)
    // (((( ... * 2 ) * 3 ) * 4) * 5)
    // ((((( 1 ) * 2 ) * 3 ) * 4) * 5)

    cout << multiply_empty() << "\n";



    return 0;
}
