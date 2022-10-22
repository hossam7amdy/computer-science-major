#include<iostream>
using namespace std;

sum(){
    return 0;
}

//sum without defining int type.
template<typename T, class ...Args>
T sum(T a, Args ...args){
    return a + sum(args...);
}

int main(){
    //normally result = the type of the first
    cout << sum(1,2,3,4,5) << "\n";
    cout << sum(1.0,2.4,3.5,4,5) << "\n";
    cout << sum(1,2,3.2,4.5,5.5) << "\n";
    cout << sum(1.1,2.2,3.3,4.4,5.5) << "\n";
    cout << sum<double>(1,2.2,3.8,4.4,5.9) << "\n";
    cout << sum<int>(1.4,2.2,3.2,4.4,5.6) << "\n";

    return 0;
}
