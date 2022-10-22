#include<iostream>
using namespace std;

//Handle a specific data type with template.
template<class something>
something pow(something s, int n = 2){
    if(n==0)
        return 1;
    return s * pow(s, n-1);
}

//the handling
template<>
string pow(string s, int n){ //Notice we are not allowed to define the default argument more than once in C++.
    if(n==0)
        return "";
    return s + pow(s, n-1);
}



int main(){
    string name = "Hossam";

    cout << pow(5, 3) << "\n";
    cout << pow(name, 3) << "\n";
    return 0;
}
