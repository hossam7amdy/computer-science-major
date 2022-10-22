/// Homework 4: Ordering named pairs
/*
● Define class NamedPair that inherits from the previous class
    ○ It has now extra params for string name
● Define operator <
    ○ It should utilize parent operator <
    ○ Don’t duplicate effort
● Override function print to print new variable
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


class MyPair
{
    int first;
    int second;
public:
    MyPair(int first, int second): first(first), second(second) {}

    int getFirst() const
    {
        return first;
    }
    void setFirst(const int &first)
    {
        this->first = first;
    }
    int getSecond() const
    {
        return second;
    }
    void setSecond(const int &second)
    {
        this->second;
    }
    bool operator<(const MyPair& p2)
    {
        MyPair &p1 = *this;
        if(p1.getFirst() == p2.getFirst())
            p1.getSecond() < p2.getSecond();

        return p1.getFirst() < p2.getFirst();
    }
    virtual void print() const
    {
        cout << "(" << getFirst() << ", " << getSecond() << ")";
    }
    virtual ~MyPair() {}
};

class NamedPair: public MyPair
{
    string name;
public:
    NamedPair(string name, int first, int second): name(name), MyPair(first, second) { }

/// Don't repeat yourself !
/*
    string getFirst() const
    {
        return this->name;
    }
    void setFirst(const string &first)
    {
        this->name = name;
    }
    int getSecond() const
    {
        return MyPair::getFirst();
    }
    void setSecond(const int &second)
    {
        MyPair::setFirst(second);
    }
    int getThird() const
    {
        return MyPair::getSecond();
    }
    void setThird(const int &third)
    {
        MyPair::setSecond(third);
    }
    */
    virtual void print() const
    {
        cout << "(" << name << ": " << getFirst() << ", " << getSecond() << ")\n";
    }
    bool operator<(const NamedPair &p2)
    {
        NamedPair &p1 = *this;
        if(p1.name == p2.name)
            return MyPair::operator<(p2);
        return p1.name < p2.name;
    }
    virtual ~NamedPair() {}
};

int main()
{
    vector<NamedPair> vec;
    vec.push_back(NamedPair("Ahmed",2,20));
    vec.push_back(NamedPair("Ahmed",10,7));
    vec.push_back(NamedPair("Emad",1,200));

    sort(vec.begin(), vec.end());

    for(const auto &pair : vec)
        pair.print();

    return 0;
}
