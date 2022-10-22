/// 1- Assignment Operators

#include<iostream>
using namespace std;


class Base
{
private:
    int * x;
public:
    Base(): x(new int)
    {
        cout << "New def\n";
        *x = 0;
    }
    Base(const int &val): x(new int)
    {
        cout << "New\n";
        *x = val;
    }
    Base(const Base &another): x(new int) // copy constructor
    {
        *x = *another.x;
    }
    Base &operator=(const Base &another) // assignment operator
    {
        if(this == &another)
            return *this;

        *x = another.getVal();
        return *this;
    }
    void setVal(const int &val)
    {
        *x = val;
    }
    int getVal() const
    {
        return *x;
    }
    ~Base()
    {
        cout << "Deleted\n";
        delete x;
        x = nullptr;
    }
};

class Drived: public Base
{
private:
    int y;
public:
    using Base::Base;
    Drived(const int &x, const int &y): Base(x), y(y) {    }

};


int main()
{
    Base x(1);
    cout << x.getVal() << "\n";

    Base y(x);
    cout << y.getVal() << "\n";

    Base z = x;
    cout << z.getVal() << "\n";

    Base w;
    cout << w.getVal() << "\n";
    w = x;
    cout << w.getVal() << "\n";

    return 0;
}
