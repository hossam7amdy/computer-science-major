#include<iostream>
using namespace std;

class MyNumber{
private:
    int* val1 = nullptr;
    int val2;
public:
    MyNumber(int x=1, int y=2){
        cout << "Normal Constructor\n";
        val1 = new int;
        *val1 = x;
        val2 = y;
    }

    // Always use const and &
    // Const may be removed
    // & no ⇒ Compile error
    MyNumber(const MyNumber &another){
        cout << "Copy Constructor\n";
        val1 = new int;
        *val1 = *another.val1;
        val2 = another.val2;
    }

    void Print(){
        cout << "val1: " << *val1 << " " << val1 << endl;
        cout << "val2: " << val2 << " " << &val2 << endl;
        cout << endl;
    }

    ~MyNumber(){
        cout << "Memory Freed\n";
         delete val1;
         val1 = nullptr;
    }
};

void fun1(MyNumber x){
}

MyNumber fun2(){
    MyNumber y(4,5);
    return y; // return object is temporary
}


/// Temporary Objects
// Main rule: cannot be bound to a non-const reference.
// Later: Move Semantic: void play4(MyNumber &&a);
void play1(MyNumber a){}
void play2(MyNumber &a){} // CE
void play3(const MyNumber &a){}

int main(){
    MyNumber a;         // normal constructor
    MyNumber b(2,3);   // normal constructor

    /// Four ways to user a copy constructor
    MyNumber c(a);     // copy constructor to build c
    MyNumber d = a;     // copy constructor to initialize in declaration
    fun1(a);           // copy constructor to pass object
    fun2();            // copy constructor to return object

    c = a;             // assignment NOT copy constructor

    play1(MyNumber());
    //play2(MyNumber()); // cannot be bound to a non-referemce
    play3(MyNumber());
    //play4(play2());   // cannot be bound to a non-referemce


    a.Print();
    b.Print();
    c.Print();
    d.Print();



    //a = b;
    // Assignment is OK with normal values
    // but be careful when it comes to pointers => always ( COPY CONSTRUCTOR ) => Deep copy
    // to a void shallow copy

    return 0;
}
