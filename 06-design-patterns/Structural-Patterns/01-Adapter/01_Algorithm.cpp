#include<iostream>
using namespace std;

class clientInterface
{
public:
    virtual void method() const = 0;
};

class client : public clientInterface
{
public:
    void method() const override {
        cout << "I am client's method\n";
    }
};

class Service
{
public:
    void seviceMethod() const {
        cout << "I am service's method\n";
    }
};

class Adapter : public clientInterface
{
private:
    Service adaptee;
public:
    void method() const override {
        adaptee.seviceMethod();
    }
};

void test(){
    client *ptr1 = new client();
    ptr1->method();
    delete ptr1;

    Adapter *ptr2 = new Adapter();
    ptr2->method();
    delete ptr2;
}

int main(){
    test();

    return 0;
}
