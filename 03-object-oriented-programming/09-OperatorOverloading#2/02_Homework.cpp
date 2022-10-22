/// Reading and Writing
/*
● In MyPair class:
● A fresh software engineer
    overloaded << operator this way
    ○ Add needed lines to cin x, y
    ○ Add needed lines to cout x, y
● Provide tips
*/

#include<iostream>
#include<istream>
using namespace std;


class MyPair
{
private:
    int first;
    int second;
public:
    MyPair(): first(0), second(0) {  }
    MyPair(const int &f, const int &s): first(f), second(s) {}

    void print() const
    {
        cout << first << " " << second << "\n";
    }

    void operator>>(istream &input)
    {
        input >> first >> second;
    }
    void operator>>(ostream &output) const
    {
        output << first << " " << second;
    }
};

int main()
{
	MyPair x, y;

	// Very weird to the used style!
	x >> cin;
	y >> cin;

	x >> cout;
	y >> cout;

	// Tip 1: using non-member style allow us to extend normally to have cin >>
	// Using >> for both input/output is wrong. Use operators as people expect
	// E.g. don't overload + to do - operations! The code will be misused!


    return 0;
}
