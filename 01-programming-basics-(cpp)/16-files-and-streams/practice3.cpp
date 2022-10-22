#include<iostream>
#include<sstream>
using namespace std;



int main(){
    ///String stream: deal with a string as a reading from a file.

    //READING
    string str = "Hossam 26 years old.";
    istringstream Iss(str);
    string name;
    int age;

    Iss>>name>>age;
    cout << age << "\n";

    //WRITING
    ostringstream Oss;
    Oss<<"Ahmed ";
    Oss<<24;
    Oss<<" years";

    cout << Oss.str();

    return 0;
}
