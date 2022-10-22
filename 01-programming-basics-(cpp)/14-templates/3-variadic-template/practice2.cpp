#include<iostream>
using namespace std;

//How to print parameter Pack.
//Recall: how to sum of an array recursively.
int sum(int arr[], int len){
    if(len==0)
        return 0;
    return arr[len-1] + sum(arr, len-1);
}

int main1(){
    int arr[]{1,2,3,4,5,6,7,8,9,10};
    cout << sum(arr, 10) << "\n";

    return 0;
}

sum(){
    return 0;
}
//Back to Variadic: same logic
template<class ...Args>
int sum(int a, Args ...args){
    return a + sum(args...);
}

int main(){
    cout << sum(1,2,3,4,5) << "\n";
    // sum(1,2,3,4,5)
    // 1 + sum(2,3,4,5)
    // 1 + 2 + sum(3,4,5)
    // 1 + 2 + 3 + sum(4,5)
    // 1 + 2 + 3 + 4 + sum(5)
    // 1 + 2 + 3 + 4 + 5 + sum() =>> returns here.
    // RIGHT FOLD Expansion.
    // (1 + (2 + (3 + (4 + (5) + ()))))

    return 0;
}
