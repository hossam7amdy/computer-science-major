/// Homework 1: copy constructor
/*
● The format we used for copy constructor argument
○ const objectName &anotherName
● 1) What happens if we moved a constructor to the private section?
* CE: External users can't make objects of such a class using this constructor!
	If this is the empty constructor and no further constructors, users can't create a class at all.

● 2) What happens if we moved the copy constructor to the private section?
* CE: Objects of that class become non-copyable.

● 3) Why argument to a copy constructor must be passed as a reference?
* A copy constructor is called when an object is passed by value.
    Copy constructor itself is a function. So if we pass an argument by value in a copy constructor, it calls to copy constructor ...
○ What kind of behavior will happen?
* CE: would be made to call copy constructor ==> infinite recursion

● 4) C++ don’t force you to use const. Why is it a good practice to use it?
* We should use const in C++ wherever possible so that objects are not accidentally modified.
*/

#include<iostream>
using namespace std;

class Name{
private:
    string* name = nullptr;

public:
    Name(string str = "Hossam"){
        name = new string;
        *name = str;
    }

    Name(const Name &another){
        name = new string;
        *name = *another.name;
    }

    void print(){
        cout << "You Name is: " << *name << endl;
    }

    ~Name(){
        cout << "Deleted\n";
        delete name;
        name = nullptr;
    }
};

int main(){
    Name a;
    a.print();

    Name b(a);
    b.print();

    return 0;
}
