#include<iostream>
using namespace std;

//Unary Right-Fold
auto sum(auto ...args){
    return (args + ...);
}

//Binary Right-Fold
auto sum_empty(auto ...args){
    return (args + ... + 0);
}

int main(){
    cout << sum(1,2,3,4,5) << "\n";
    //goes from right to left
    // (1 + ... )
    // (1 + (2 + ...))
    // (1 + (2 + (3 + ...))
    // (1 + (2 + (3 + (4 + ...))
    // (1 + (2 + (3 + (4 + (5)))))
    // notice it dosn't work with empty folds

    //so we need a solution for this problem?
    //Now we are rescued
    cout << sum_empty() << "\n";

    return 0;
}
