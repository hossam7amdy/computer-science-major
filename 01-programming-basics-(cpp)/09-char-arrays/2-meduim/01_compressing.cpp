#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt{1};
    for(int i=1; i<(int)s.size(); ++i){
        if(s[i] == s[i-1])
            ++cnt;
        else{
            cout << s[i-1] << cnt << "_";
            cnt = 1; // reset counter
        }
    }
    cout << s[(int)s.size()-1] << cnt;

    return 0;
}
