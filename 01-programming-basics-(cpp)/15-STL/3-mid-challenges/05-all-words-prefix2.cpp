#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
all words prefix (2)
● Given N, read N (!unique) strings. Then Read Q queries, for each query: print
all strings that start with this prefix. Print them ordered no duplicate.
INPUTS: 5
mostafa
morad
nawal
marwa
mostafa
● 4
○ m => [marwa morad mostafa]
○ mo => [morad mostafa]
○ mos => [mostafa]
○ naw => [nawal]
*/




int main(){
    map<string, set<string>> mp;
    int N;
    cout << "How many names: "; cin >> N;
    while(N--){
        string name;
        cin >> name;
        int sz = name.size();
        string str = "";
        for(int i=0; i<sz; i++){
            str+=name[i];
            mp[str].insert(name);
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
