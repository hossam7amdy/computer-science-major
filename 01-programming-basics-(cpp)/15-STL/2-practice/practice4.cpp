#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
● Given N full-names as following
    ○ Each full name name starts with number K: # of words,
    ○ Then read K words
● Input
5
3 mostafa saad ibrahim
3 mostafa saad ali
3 asmaa talaat morsi
2 asmaa ashraf
4 mostafa saad ibrahim mohamed
*/

void print(const vector<string> &v){
    for(auto str : v)
        cout << str << "\n";
}


int main(){
    map<string, vector<string>> mp;
    int N;
    cout << "How many full names? "; cin >> N;
    while(N--){
        int k;
        cout << "Number of words: "; cin >> k;
        string full_name = "";
        vector<string> names;
        while(k--){
            string sub_name;
            cin >> sub_name;
            full_name += sub_name;
            names.push_back(full_name);
            if(k)
                full_name+=" ";
        }
        for(auto &str : names) //better use reference here.
            mp[str].push_back(full_name);

    }

    int Q;
    cout << "How many queries? "; cin >> Q;
    while(Q--){
        int k;
        cout << "Number of words: "; cin >> k;
        string full_name = "";
        while(k--){
            string sub_name;
            cin >> sub_name;
            full_name += sub_name;
            if(k)
                full_name+=" ";
        }
        if(mp.count(full_name))
            print(mp[full_name]); //print names in the vector.
        else
            cout << "No such sub-full name.\n";
    }

    return 0;
}
