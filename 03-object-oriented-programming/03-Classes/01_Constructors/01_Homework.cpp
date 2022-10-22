#include<iostream>
using namespace std;

/// Homework 1: Initializer list!
/*
● We learned that it is recommended to use the initializer list for constructor
● Assume we have a class of several variables (e.g. a, b, c in order)
● But the initializer list is b, a, c
● Will the constructor initialize based on class order or initializer-list order? // class order
● Also, what is the order of the destructor? // class order
● It is preferred to learn the answer by reading a book/reference
● But, implement a program that its results can help us answer the 2 questions
*/

class A{
private:
public:
    A(){
        cout << "A constructor\n";
    }

    ~A(){
        cout << "A destructor\n";
    }
};

class B{
private:
public:
    B(){
        cout << "B constructor\n";
    }

    ~B(){
        cout << "B destructor\n";
    }
};

class C{
private:
public:
    C(){
        cout << "C constructor\n";
    }

    ~C(){
        cout << "C destructor\n";
    }
};

class D{
private:
    A aa;
    B bb;
    C cc;

public:
    D(): bb(B()), aa(A()), cc(C()) {
        cout << "D constructor\n";
    }

    D(const A &a, const B &b, const C &c): aa(a), bb(b), cc(c) {
		// By using & => we use same memory object hence faster and low memory
		// By using const => we remember developers you shouldn't try to change this parameter
    }

    ~D(){
        cout << "D destructor\n";
    }
};



int main(){
    D dd;

    return 0;
}
/*
A Constructor
B Constructor
C Constructor
D Constructor
D Destructor
C Destructor
B Destructor
A Destructor


From results: Constructors are called based on Class data members order NOT initalizer list order
 */
