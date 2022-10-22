#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct employee{
    int id, age;
    string name;

    employee(int _id, string _name, int _age){
        id = _id, name = _name, age = _age;
    }

    bool operator <(const employee& rhs) const {
        if(false){ //first way: normal compare
            if(id != rhs.id)
                return id < rhs.id;
            else if(name != rhs.name)
                return name < rhs.name;
            return age < rhs.age;
        }
        if(false){ //second way: create pairs.
            return make_pair(id, make_pair(name, age))
                < make_pair(rhs.id, make_pair(rhs.name, rhs.age));
        }
        if(true){ //third way: with tie elements (must be variables)
            return std::tie(id, name, age)
                < std::tie(rhs.id, rhs.name, rhs.age);
        }


    }
    void print(){
        cout << id << " " << name << " " << age << "\n";
    }
};


void print(auto &s){
    for(auto val : s)
        cout << val << " ";
    return;
}

int main(){
    set<string> st; // ordered & unique
    st.insert("hossam"), st.insert("ahmed"), st.insert("emad");
    auto [done] = st.insert("ahmed");
    if(!done)
        cout << "exist\n";
    if(st.count("hossam"))
        cout << "Yes\n";
    auto it = st.begin();
    it = st.find("hossam");
    if(it != st.end())
        st.erase(it);
    print(st);
    cout << "\nMultiSet*************************\n";
    multiset<int> ms;
    ms.insert(1), ms.insert(1), ms.insert(3), ms.insert(5), ms.insert(7), ms.insert(9), ms.insert(11), ms.insert(3);
    print(ms); //ordered & NOT unique
    cout << "\nStruct over sets & Multisets *************************\n";
    set<employee> myset;
    myset.insert(employee(112, "ahmed", 24));
    myset.insert(employee(112, "doaa", 18));
    myset.insert(employee(112, "emad", 16));
    myset.insert(employee(112, "hossam", 26));
    myset.insert(employee(112, "ahmed", 24));
    myset.insert(employee(112, "emad", 16));
    for(auto ele : myset)
        ele.print();

    return 0;
}
