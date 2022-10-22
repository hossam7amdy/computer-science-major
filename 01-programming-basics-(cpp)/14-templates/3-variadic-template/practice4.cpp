#include<iostream>
using namespace std;

void print(){
    cout << "\n";
}
//print without defining int type.
template<typename T, class ...Args>
void print(T a, Args ...args){
    cout << a;
    int sz = sizeof ...(args);
    if(sz>0)
        cout << ", "; //cool trick to avoid printing extra comma
    print(args...);
}

//print using const & we can also get red of (typename) and use (auto)
void print2(){
    cout << "\n";
}
template<class T>
void print2(const T& a, const auto& ...args){
    int sz = sizeof ...(args);
    cout << a;
    if(sz>0)
        cout << ", ";
    print2(args...);
}

int main(){
    //normally result = the type of the first
    print("Hossam" ,2,3,4,5);
    print2(1.0,2.4,"something",4,5);
    print(1,2,3.2,(1>2),5.5);
    print2(1.1,2.2,3.3,4.4,5.5);
    print(1,2.2,'a',4.4,5.9);
    print2('a','b', 'c', 'd', 'e', 'f', 'g', 'h', "...");

    return 0;
}
