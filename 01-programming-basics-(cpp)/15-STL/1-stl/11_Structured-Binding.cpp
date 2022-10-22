#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct employee{
    string name;
    int sal;
};

pair<int, string> gb;
auto &by_ref(){ return gb; }
auto by_val() { return gb; }

int main(){
    int arr[] {1,2,3};
    auto &[a,b,c] = arr;
    a=3, cout << arr[0] << "\n";

    ///with struct
    employee emp {"Hossam", 5000};
    auto &[n,s] = emp; //by ref
    n = "Ahmed", cout << emp.name <<"\n";
    //const auto &[n,s] = emp;
    //s = 2000, cout << emp.sal; //CE: read-only variable

    ///with pair
    pair<int, string> p{26, "Hossam"};
    auto [age, name] = by_ref();
    //auto &[age, name] = by_val(); =>> CE
    age = 28, cout << age << "\n";

    ///with tuple
    tuple<char, int, string> tp = make_tuple('a', 11, "Emad");
    auto [ch, num, str] = tp; //OK, but waste of time/memory
    //Direct initialization
    auto [n1, n2, ch1, ch2] = tuple<int, int, char, char>(11, 12, 'M', 'F');

    ///with multimap
    multimap<char, int> mp1 {{'a',65}, {'b',66}, {'a',67}};
    for(const auto &[key, val] : mp1)
        cout << key << " " << val << "\n";
    //return pair of iterators
    auto [iter_key, iter_val] = mp1.equal_range('a');
    for(auto it=iter_key; it!=iter_val; it++)
        cout << it->first << " " << it->second << "\n";

    ///with Insertion
    set<int> s1 {1,20,31,42};
    auto [iter1, success1] = s1.insert(1); cout << success1 << "\n"; //false
    auto [iter2, success2] = s1.insert(2); cout << success2 << "\n"; //true
    cout << *iter2;

    return 0;
}
