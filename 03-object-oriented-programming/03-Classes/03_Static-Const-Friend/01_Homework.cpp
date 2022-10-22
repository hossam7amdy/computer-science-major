/// Homework 01: Why!
/*
● Why C++ doesn’t allow creating const static member function?
- Because the function shared among all objects.

● Why C++ doesn’t allow using this pointer to access a static member data?
- It doesn't have its own data members, So this invalidate the use of this pointer.

Dr's note:
It is useful to think about the language features:
	why does it allow something? why not?
*/

#include<iostream>
using namespace std;

class A{
private:
    int a;
    static int b;
public:
    int PrintMe(){
        return a++;
    }
};


int main(){
    A aa;
    cout << aa.PrintMe() << endl;
    cout << aa.PrintMe() << endl;
    cout << aa.PrintMe() << endl;
    cout << aa.PrintMe() << endl;
    return 0;
}
