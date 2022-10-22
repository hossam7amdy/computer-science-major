#include<iostream>
using namespace std;

//Function to compare two things of same-type

template<typename sometype>
sometype mymax(sometype t1, sometype t2){
    if(t1 > t2)
        return t1;
    return t2;
}

int main(){
    //"At compile time": compiler generates different func for every case
    cout << mymax(2,4) <<"\n";
    cout << mymax<double>(1.5,3) <<"\n"; //must be of same type.
    cout << mymax('a','A') <<"\n";
    cout << mymax('a','z') <<"\n";
    cout << mymax("hossam", "ahmed") <<"\n";

    //notice we cannot use max. why?


    return 0;
}
