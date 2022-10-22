#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
all words prefix (1)
● Given N, read N unique strings. Then Read Q queries, for each query: print
all strings that start with this prefix. Print use input order. Use a map
    ● 4
    ○ mostafa
    ○ morad
    ○ nawal
    ○ marwa
    ● 4
    ○ m => [mostafa morad marwa]
    ○ mo => [mostafa morad]
    ○ mos => [mostafa]
    ○ naw => [nawal]
*/




int main(){
    map<string, vector<string>> mp;
    int N;
    cout << "How many names: "; cin >> N;
    while(N--){
        string name;
        cin >> name;
        int sz = name.size();
        string str = "";
        for(int i=0; i<sz; i++){
            str+=name[i];
            mp[str].push_back(name);
        }
    }

    int Q;
    cout << "How many queries: "; cin >> Q;
    while(Q--){
        string str;
        cin >> str;
        if(mp.count(str)){
            for(const auto &ele : mp[str])
                cout << ele << " ";
            cout << "\n";
        }
        else
            cout << "No names with such a prefix.\n";
    }

    return 0;
}
