#include<iostream>
using namespace std;

bool compare(const string &s1, const string &s2){
    int sz1{(int)s1.size()};
    int sz2{(int)s2.size()};

    for(int i=0; i<min(sz1, sz2); ++i){
        if(s1[i]<s2[i])
            return true;
        else if(s1[i]>s2[i])
            return false;
    }

    return sz1 <= sz2;
}

int main(){
    cout << compare("aaa", "aaa") << endl;
    cout << compare("aaa", "aaaaa") << endl;
    cout << compare("aaaaa", "aaa") << endl;
    cout << compare("abc", "d") << endl;
    cout << compare("ddddddddddddddd", "xyz") << endl;
    cout << compare("azzzzzzzz", "za") << endl;
    cout << compare("za","azzzzzzzz") << endl;



    return 0;
}
