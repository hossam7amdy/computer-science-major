#include<iostream>
using namespace std;

struct Employee{
    int id;

    Employee(int _id){  id = _id; }

    ~Employee(){ cout << "Destroy Employee: " << id << endl; }
};

void f4(){
    cout << "Start f4\n";
    Employee *p = new Employee(7);
    throw 1;
    delete p;
    p = nullptr;
    cout << "End f4\n";
}

void f3(){
    cout << "Start f3\n";
    Employee e1(10);
    f4();
    cout << "End f3\n";
}

void f2(){
    cout << "Start f2\n";
    try{
        f3();
    }catch(runtime_error &e){
        cout << "runtime error: " << e.what() << endl;
    }
    cout << "End f2\n";
}

void f1(){
    cout << "Start f1\n";
    try{
        f2();
    }catch(int &e){
        cout << "Error code: " << e << endl;
    }
    cout << "End f1\n";
}

void fun1(){
    throw runtime_error ("A runtime error\n");
}

void fun2(){
    try{
        fun1();
    }catch(runtime_error &e){
        cout << &e << endl;
        throw;
    }
    cout << "No errors\n";
}

void fun3(){
    try{
        fun2();
    }catch(runtime_error &e){
        cout << &e << endl;
        throw;
    }
}

int main(){
    f1();

    cout << endl;

    try {   fun3(); } catch(runtime_error &e){
        cout << &e << endl;
    }

    return 0;
}
