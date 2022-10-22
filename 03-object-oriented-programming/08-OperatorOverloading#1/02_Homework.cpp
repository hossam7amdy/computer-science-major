/// Homework 2: Multiplying string
/*
● Extend the functionality of string to allow multiplying with a number
    ○ A.g. “hi” * 2 ⇒ “hihi”
*/

#include<iostream>
#include<string>
using namespace std;


string operator *(const string &str, const int &n)
{
    string res = str;
    for(int i=1; i<n; i++)
    {
        res+=str;
    }
    return res;
}


int main()
{
    string a = "bad";
    string b = "I am " + a * -1 + ", right?\n";

    cout << b;

    return 0;
}
