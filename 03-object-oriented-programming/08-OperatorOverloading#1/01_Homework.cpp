///Homework 1: Adding vectors
/*
● Extend the functionality of vector<int> to allows adding 2 vectors.
● The smaller vector in length is added to the large vector
    ○ Large[i] += small[i]
*/

#include<iostream>
#include<vector>
using namespace std;


vector<int> operator +(const vector<int> &v1, const vector<int> &v2)
{
    int sz = 0;
    vector<int> res(sz);
    if((int)v1.size()>(int)v2.size())
    {
        sz = (int)v2.size();
        res = v1;
    }
    else
    {
        sz = (int)v1.size();
        res = v2;
    }


    for(int i=0; i<sz; i++)
        res[i] = v1[i] + v2[i];
    return res;
}


int main()
{
    vector<int> a = {1,2,3,4};
    vector<int> b = {10,20};

    vector<int> c = a + b;

    for(const auto &val : c)
        cout << val << " ";

    return 0;
}
