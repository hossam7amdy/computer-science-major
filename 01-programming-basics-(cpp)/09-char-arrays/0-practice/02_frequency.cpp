#include<iostream>
using namespace std;

// https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/J

int main(){
    string s;
    cin >> s;

    int freq[150]{};
    for(int i=0; i<(int)s.size(); ++i)
        freq[(int)s[i]]++;

    for(int i='a'; i<='z'; ++i){
        if(freq[i])
            cout << (char)i << " : " << freq[i] <<  endl;
    }

    return 0;
}
