#include<iostream>
#include<tuple>
using namespace std;


int main(){
    //Generalization of pairs: create any number of data type
    tuple<string, int, char> t1;
    t1 = make_tuple("Hossam", 100, 'M'); // read
    // print
    cout << get <0> (t1) << " " << get <1> (t1) << " " << get <2> (t1) << "\n";
    // replace an element
    get <0> (t1) = "Ahmed";
    cout << get <0> (t1) << " " << get <1> (t1) << " " << get <2> (t1) << "\n";

    cout << boolalpha; //prints true as word "true"
    cout << (t1 <= t1) << "\n";

    string n;
    int id;
    char g;

    //unpack tuple values into separate variable
    tie(n, id, g) = t1;
    cout << id << " " << n << " " << g << "\n";

    auto t2 = tuple_cat(t1, make_tuple(25));
    cout << get <0> (t2) << " " << get <1> (t2) << " " << get <2> (t2) << " " << get <3> (t2) << "\n";

    int c,d;
    //auto [c,d] = std::make_tuple(4,5); // error: conflicting declaration 'auto c'


}
