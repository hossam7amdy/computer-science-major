#include<iostream>
#include<vector>
using namespace std;

// (&&), (||) and (,) don't need an initial values to use them.

// && default is 1
bool all(auto ...args){
    return (args && ...);
}

// || default is 0
auto any(auto ...args){
    return (args || ...);
}

// (,) can be used to do sequential operations
template<class T>
auto push_back_vec(vector<T>& v, auto ...args){
    return(v.push_back(args), ...);
}




int main(){

    cout << all(1,2,3,4,5) << "\n"; //true
    cout << all(1,0,3,4,5) << "\n"; //false
    cout << any(1,0,0,0) << "\n"; //true
    cout << any(0,0,0,0) << "\n"; //false

    vector<string> v;
    v.push_back("Hossam");
    v.push_back("Ahmed");
    v.push_back("Emad");

    push_back_vec(v,"Doaa", "Dad", "Mom"); //push them one by one

    int sz = v.size();
    for(auto x : v) //print
        cout << x << " ";

    return 0;
}
