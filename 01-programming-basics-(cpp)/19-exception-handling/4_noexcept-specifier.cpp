#include<iostream>
#include<cmath>
using namespace std;

// Are playing with me!
int my_abs(int x) noexcept {
    throw 1;
    if(x<0)
        return -x;
    return x;
}

int my_abs_div(int x, int y){
    return my_abs(x) / my_abs(y);
}

int main(){

    try{
        cout << my_abs_div(6,2) << endl;
    }catch(...){    }

    cout << "Bye\n";

    return 0;
}
