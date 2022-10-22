/// friend class, member function, and friend function

#include<iostream>
using namespace std;

class A; // Defined early to break cycle

class B{
public:
    void AccessA1(A &a1);
    void AccessA2(A &a2);
};

class A{
private:
    int val1 = 10;
    int val2 = 20;
    void HiddenA(){
        cout << "I am hidden\n";
    }
public:
    // friend member function: access my private data
    friend void B::AccessA1(A& a);

    //friend function:
    friend void Access(A& a);
};

void B::AccessA1(A &a1){
        cout << a1.val1++ << endl;
        a1.HiddenA();
}
void B::AccessA2(A &a2){
    // Syntax error: can't access these private data
        //cout << a2.val2 << endl;
}

void Access(A& a){
    cout << "I am a general function, and here is your data: ";
    cout << a.val2 << endl;
}

int main(){
    A a;
    B b;
    b.AccessA1(a);
    Access(a);

    return 0;
}
