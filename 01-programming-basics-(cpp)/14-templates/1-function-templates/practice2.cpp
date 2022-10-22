#include<iostream>
using namespace std;

//sum of two things.

template<typename T1,class T2>
T1 sum(T1 t1, T2 t2){
    return t1 + t2;
}

int main(){

    cout << sum(2,3) << "\n";
    cout << sum(2.2,3) << "\n";
    cout << sum(2,3.3) << "\n";
    cout << sum(2.2,3.3) << "\n";
    cout << sum('a',3.5) << "\n";
    cout << sum(3.5,'a') << "\n";
    cout << sum('A',1) << "\n";
    cout << sum<string>("I am"," Hossam") << "\n"; //You should define <string> why?

    return 0;
}
