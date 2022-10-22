/// Homework 3: Ordering pairs
/*
● To be able to sort a vector of objects as in right code, the operator < must be supported on class type
● Add operator < as member function in the MyPair class to allow such code

● Tip:
    ○ When provide a class, think if comparing object is needed or not
        ■ E.g. Sort list of emplyees
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
    string print() const
    {
        ostringstream oss;
        oss << "(" << getFirst() << ", " << getSecond() << ")";
        return oss.str();
    }
};


int main()
{
    vector<MyPair> vec;
    vec.push_back(MyPair(10,20));
    vec.push_back(MyPair(10,7));
    vec.push_back(MyPair(1,200));

    sort(vec.begin(), vec.end());

    for(const auto &pair : vec)
       cout << pair.print() << "\n";

    return 0;
}
