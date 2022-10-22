#include<iostream>
using namespace std;

/// Homework 2: Guess me! ///
/*
● 1) What are the possible ways to finish Class C
constructor?
● 2) How many times ClassA Constructor will be
called?
○ Why?
○ Give a tip for the coder
*/

class classA{
private:
public:
    classA(){
        cout << "A constructor\n";
    }

    ~classA(){
        cout << "A destructor\n";
    }
};

class classB{
private:
    int x;
    classA aa; // originally this line needs to call constructor to default in begin
public:
    classB(int x): x(x), aa(classA()) {
            // Originally the constructor of classA called twice
			// Once to be default Initialized
			// Once inside the constructor

		// Moving to Initializer list, then we Initialize it before construction only once

		// Tip: Always use Initializer list
		// Note: If a member object is not initialized through a member initializer, the member object’s default constructor will be called "implicitly".
			// Avoid duplicate initlaization!
    }

    ~classB(){
        cout << "B destructor\n";
    }
};

class classC{
private:
    int &y;
    classB bb;

public:
    classC(int &y, const classB &bb): y(y), bb(bb){
        // 1- The only way to initialize a reference is intializer list
		// 2- The only way to initialize a class that doesn't have default constructor (e.g. Class B)  is intializer list
    }

    ~classC(){
        cout << "C destructor\n";
    }
};

// Tip: please use initalizer list as much as possible!

int main(){
    int hello = 10;
    classB b(5);
    classC c(hello, b);


    return 0;
}
