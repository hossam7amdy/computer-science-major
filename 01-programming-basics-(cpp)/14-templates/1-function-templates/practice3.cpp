#include<iostream>
using namespace std;

//Working with static variable

int global_var{0};

template<typename T1>
void print(T1 t1){
    static int static_var(0);
    cout << static_var++ << " " << global_var++ << "\n";
}

int main(){

    print(2);
    print(2);
    print(2);

    print('a');

    print(2.0);
    print(2.0);
    print(2.0);

    print(2);

    print('a');
    print('b');
    print('c');

    //Compiler generate a new static for every type.

    return 0;
}
