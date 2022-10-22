/// 1- Increment Operators: prefix & postfix
/// 2- Overloading Streams: Insertion & Extraction

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
    MyPair(const int &f, const int &s): first(f), second(s) {}

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

int main()
{
    MyPair x, y;
    cin >> x >> y;
    cout << x++ << y;
    cout << x << y;

    return 0;
}
