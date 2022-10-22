#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print1(const auto &mp){
    for(const pair<string, int> &val : mp)
        cout << val.first << " - " << val.second << "\n";
}

void print2(const map<char, vector<int>> &mp){
    for(const pair<char, vector<int>> &ele : mp){
        cout << ele.first << " - ";
        for(auto val : ele.second)
            cout << val << " ";
        cout << "\n";
    }
}

int main(){
    map<string, int> mp;
    mp["hossam"] = 26;
    mp["ahmed"] = 24;
    mp["doaa"] = 18;
    mp["emad"] = 16;
    print1(mp);
    if(mp.count("hossam"))
        cout << "Yes\n";
    auto it = mp.find("emad");
    if(it != mp.end())
        cout << "Yes\n";

    cout << "\n********************************\n";

    map<char, vector<int>> cool_mp;
    cool_mp['A'] = {1,2,3,4,5,6,7};
    vector<int> x {1,3,5,7};
    cool_mp['b'] = x; //assign vector to key['b']
    x.push_back(9); //push new val to vector x\
    //this are two different sizes. Why?
    cout << x.size() << "\n";
    cout << cool_mp['b'].size() << "\n";

    cool_mp['d'] = x; //assign it to another key
    print2(cool_mp);

    return 0;
}
