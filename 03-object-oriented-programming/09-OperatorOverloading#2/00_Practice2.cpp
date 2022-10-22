/// 1- Conversion Constructors
/// 2- Conversion Operators

#include<iostream>
#include<sstream>
using namespace std;

class MyPair
{
private:
    int first;
    int second;
public:
    MyPair(): first(0), second(0) {  }
    // Disabling conversion constructor
    // No casting
    // No constructor
    explicit MyPair(const int &val): MyPair(val, val) { }
    MyPair(const int &f, const int &s): first(f), second(s) {  }

    // convert pair to my constructor
    MyPair(const pair<int, int> &p): first(p.first), second(p.second) {  }
    // convert my class to int
    operator int()
    {
        return getFirst() * getSecond();
    }
    // convert my class to pair<int, int>
    operator pair<int, int>()
    {
        return make_pair(getFirst(), getSecond());
    }
    int getFirst() const
    {
        return first;
    }
    int getSecond() const
    {
        return second;
    }
    // prefix
    MyPair& operator++()
    {
        ++first, ++second;
        return *this;
    }
    // postfix
    MyPair operator++(int)
    {
        MyPair temp = *this;
        ++first, ++second;
        return temp;
    }
    void print() const
    {
        cout << first << " " << second << "\n";
    }
    friend istream & operator >>(istream &input, MyPair &p);
    friend ostream & operator <<(ostream &output, const MyPair &p);
};

MyPair operator+(const MyPair &p1, const MyPair &p2)
{
    return MyPair(p1.getFirst() + p2.getFirst(),
            p1.getSecond() + p2.getSecond());
}

istream & operator>>(istream &input, MyPair &p)
{
    input >> p.first >> p.second;
    return input;
}
ostream & operator<<(ostream &output, const MyPair &p)
{
    output << "(" << p.first << ", " << p.second << ")";
    return output;
}


/*
● Both conversion constructor are very problematic
    ○ Use explicit
    ○ Don’t support conversion
        ■ Unless good reason
*/

int main()
{
    //MyPair w = 5;
    //cout << "W = " << w << "\n";

    MyPair x(10);
    cout << "X = " << x << "\n";

    MyPair y(1,3);
    cout << "Y = " << y << "\n";

    //MyPair z1 = x + 3.5;
    //cout << "Z1 = x + 3 = " << z1 << "\n";

    //MyPair z2 = 5 + x;
    //cout << "Z2 = 5 + x = " <<  z2 << "\n";

    //MyPair z3 = 3 + y; // unexpected behavior. WEY?
    //cout << "Z3 = 3 + y = " << z3 << "\n";

    MyPair z4 = x + y;
    cout << "Z4 = x + y = " << z4 << "\n";

    pair<int, int> p(2, 4);
    z4 = p;
    cout << "Z4 = " << z4 << "\n";

    int n = z4;
    cout << n << "\n";

    pair<int, int> newPair = z4;
    cout << newPair.first << " " << newPair.second << "\n";


    return 0;
}
