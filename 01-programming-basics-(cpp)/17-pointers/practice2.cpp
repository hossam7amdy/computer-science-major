#include<iostream>
using namespace std;

void do_math(int &x){
    x++;
    x = x * 2;
    x*=2;
}

void do_math(int* x){
    ++*x;
    *x = *x * 2;
    *x *= 2;
}

int* bigger(int* p1, int* p2){ // returns address
    if(p1==nullptr) return p2;
    if(p2==nullptr) return p1;

    if(*p1>*p2)
        return p1;
    return p2;
}

int smaller(int &ref1, int &ref2){
    if(ref1<ref2)
        return ref1;
    return ref2;
}

int main(){
    int y = 2;
    int* ptr = &y;

    do_math(y);
    cout << y << endl; // 12

    do_math(*ptr);
    cout << y << endl; // 52

    int x1 = 2, x2 = 3;
    int* ptr1 = bigger(&x1,&x2);
    int &val = *ptr1;
    cout << ptr1 << " = " << *ptr1 << endl;

    cout << smaller(x1, y) << endl;
    cout << smaller(x2, x1) << endl;
    cout << smaller(*ptr1, val) << endl;


    return 0;
}
