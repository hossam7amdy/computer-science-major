/// Static data member, static member function, and static class

#include<iostream>
using namespace std;

class A{
private:
    int y;
    static int x;
public:
    A(){
        y = 0;
        x++; // keep updates till program ends
    }

    static int factorial(int n){
        // y += 10; // can't access member data
        x+=10; // though it accesses static data member normally

        int ret = 0;
        for(int i=1; i<=n; i++)
            ret+=i;
        return ret;
    }

    void print(){
        cout << "x= " << x << "\n" << "y= " << y << endl;
    }
};

int A::x = 0;

class Employee{ // practical example (lets count how many employee will be used?
private:
    int id;
    string name;
    static int employee_counter;
public:
    Employee(int id, string name):id(id), name(name){
        employee_counter++;
    }

    void print() const {
        cout << id << " " << name << endl;
    }

    static int GetEmployeeCount(){
        return Employee::employee_counter;
    }
};

int Employee::employee_counter = 0;

int main(){
    Employee emp1(101, "hossam");
    Employee emp2(102, "Ahmed");
    static Employee stat_emp(100, "Doaa");
    Employee(111, "Belal");

    cout << Employee::GetEmployeeCount() << endl;  // 4


    return 0;
}
