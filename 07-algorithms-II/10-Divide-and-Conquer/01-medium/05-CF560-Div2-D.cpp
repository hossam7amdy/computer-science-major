// https://codeforces.com/contest/560/problem/D/
#include<bits/stdc++.h>
using namespace std;


string canonical(const string &str){
    int sz = str.size();
    if(sz % 2 != 0)
        return str;

    int mid = sz / 2;
    string can1 = canonical(str.substr(0,mid));
    string can2 = canonical(str.substr(mid));

    if(can1 > can2)
        return can2 + can1;

    return can1 + can2;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;

    if(canonical(s1) == canonical(s2))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

