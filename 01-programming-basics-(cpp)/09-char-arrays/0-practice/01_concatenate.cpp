#include<iostream>
using namespace std;

// https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/K

int main(){
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        int sz1{(int)s1.size()}, sz2{(int)s2.size()};

        for(int i=0; i<max(sz1,sz2); ++i){
            if(i<sz1)
                cout << s1[i];
            if(i<sz2)
                cout << s2[i];
        }
        cout << "\n";
    }

    return 0;
}
