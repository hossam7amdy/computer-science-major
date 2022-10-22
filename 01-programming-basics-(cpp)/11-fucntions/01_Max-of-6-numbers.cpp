#include <iostream>
using namespace std;

/*
● Write a function that reads 6 numbers and compute their maximum. Create
the following functions
    ○ max(int a, int b, int c)
    ○ max(int a, int b, int c, int d)
    ○ max(int a, int b, int c, int d, int e)
    ○ max(int a, int b, int c, int d, int e, int f)
● How can
    ○ max(int a, int b, int c, int d) utilize max(int a, int b, int c) ? and so on
*/

int mx(int a, int b, int c){
    if(a<b)
        a=b;
    if(a<c)
        a=c;
    return a;
}

int mx(int a, int b, int c, int d){
    if(d>mx(a,b,c))
        return d;
    return mx(a,b,c);
}

int mx(int a, int b, int c, int d, int e){
    if(e>mx(a,b,c,d))
        return e;
    return mx(a,b,c,d);
}

int mx(int a, int b, int c, int d, int e, int f){
    if(f>mx(a,b,c,d,e))
        return f;
    return mx(a,b,c,d,e);
}


int main() {
    cout << mx(5,3,10,-9,11,11);

	return 0;
}
