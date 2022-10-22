#include<iostream>
#include<vector>
using namespace std;

struct Employee{
    int id = -1;
    string name;

    Employee(){}

    Employee(int _id, string _name){
        id = _id;
        name = _name;
    }

    void print(){
        cout << name << " " << id << endl;
    }

};

int main(){
    Employee e1(11, "Hossam");
    e1.print();

    Employee* e2 {new Employee(12, "Ahmed")};
    e2->print();

    Employee* e3 = new Employee(13, "Doaa");
    (*e3).print();

    Employee& e4 = *e2;
    e4.id = 10; // by reference changes apply on all

    Employee* e5 = &e1;
    e5->print();

    /// vector of pointers !
    vector<Employee*> vec;
    vec.push_back(e2);
    vec.push_back(&e1);

    for(auto emp : vec)
        emp->print();

    /// Delete what we have created only "new"
    delete e2;
    delete e3;
    e2 = e3 = nullptr;

    return 0;
}
