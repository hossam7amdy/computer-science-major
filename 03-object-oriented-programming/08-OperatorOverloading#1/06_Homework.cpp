/// Homework 6: Our Map
/*
● Ever wondered from map usage?!
● We wanna implement our own map <string, int>. Internal data structures is and usage as on right
● [string] return corresponding int or 0 if not exist
● [int] return sorted vector of strings that has this integer value
● HasNext/GetNext to iterate and print
● Clear: just remove all stored entries
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MyMap
{
private:
    vector<string> vec_strs;
    vector<int> vec_ints;

    int pos = 0;
public:
    int& operator[](const string &str)
    {
        for(int i=0; i<(int)vec_strs.size(); i++)
        {
            if(vec_strs[i] == str)
                return vec_ints[i];
        }

        vec_strs.push_back(str);
        vec_ints.push_back(0);
        return vec_ints.back();
    }

    vector<string> operator[](const int &val)
    {
        vector<string> ret;
        for(int i=0; i<(int)vec_ints.size(); i++)
        {
            if(vec_ints[i] == val)
                ret.push_back(vec_strs[i]);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }

    void reset_iterator()
    {
        this-> pos = 0;
    }

    bool HasNext() const
    {
        return pos < (int)vec_strs.size();
    }

    pair<string, int> GetNext()
    {
        pair<string, int> p;
        if(HasNext())
        {
            p = make_pair(vec_strs[pos], vec_ints[pos]);
            pos++;
        }
        return p;
    }

    void Clear()
    {
        vec_ints.clear();
        vec_strs.clear();
        pos = 0;
    }

    void print() const
    {
        for(int i=0; i<(int)vec_strs.size(); i++)
            cout << vec_strs[i] << ": " << vec_ints[i] << "\n";
    }
};


int main()
{
    MyMap mp;
    mp["mostafa"] = 1;
    mp["ahmed"] = 2;
    mp["emad"] = 3;
    mp["hossam"] = 1;
    mp["mostafa"] = 5;
    mp["doaa"] = 1;

    vector<string> keys = mp[1];
    for(int i=0; i<(int)keys.size(); i++)
        cout << keys[i] << " ";

    auto p = mp.GetNext();
    cout << p.first << " " << p.second << "\n";

    p = mp.GetNext();
    cout << p.first << " " << p.second << "\n";

    p = mp.GetNext();
    cout << p.first << " " << p.second << "\n";

    p = mp.GetNext();
    cout << p.first << " " << p.second << "\n";

    p = mp.GetNext();
    cout << p.first << " " << p.second << "\n";

    p = mp.GetNext();
    cout << p.first << " " << p.second << "\n";

    return 0;
}
