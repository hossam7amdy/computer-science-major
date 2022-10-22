#include<iostream>
using namespace std;


int main(){
    string ifLower {"YZIMNESTODUAPWXHQFBRJKCGVL"};
    string ifDigit{"!@#$%^&*()"};

    string s;
    cin >> s;

    for(int i=0; i<(int)s.size(); ++i){
        if(islower(s[i]))
            cout << ifLower[s[i]-'a'];
        else if(isdigit(s[i]))
            cout << ifDigit[s[i]-'0'];
        else
            cout << s[i];
    }

    return 0;
}
