#include<iostream>
using namespace std;

struct Employee{
    int* Xptr = nullptr;

    Employee(){
        Xptr = new int[5] {1,2,3,4,5};
    }

    ~Employee(){
        delete[] Xptr;
        cout << "Bye\n";
        Xptr = nullptr;
    }

    void print(){
        cout << Xptr << " " << *Xptr << " " << &Xptr << endl;
    }

    Employee(const Employee& e) = delete;
    void operator = (const Employee& e) = delete;
};

int main(){
    int* x = new int {5};
    cout << x << " " << *x << " " << &x << endl;
    delete x; // Created and deleted by me

    Employee e1;
    e1.print(); // memory leak. Who deletes it?
    /// Destructor !

    e1.Xptr[0] = 20;
    e1.print();

    Employee e2;
    e2.print();

    e2 = e1; // NOW CE
    e2.print();
    // Crash
    // e2 lost his Xptr value created in the memory
    // the value of e1 copied

    /// Problem 1): Memory leaks as we lost e2 created memory
    /// Problem 2): e1 will deleted twice = dangling = crash

    Employee e3 = e1; // CE

    return 0;
}
