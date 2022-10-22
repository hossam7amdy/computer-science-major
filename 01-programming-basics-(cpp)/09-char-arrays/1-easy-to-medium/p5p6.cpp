#include<iostream>
using namespace std;

int toInt(const string &str){
    int res{};
    for(int i=0; i<(int)str.size(); ++i)
        res = (res * 10) + (int)(str[i]-'0');

    return res;
}

void Grouping(const string &str){
    for(int i=0; i<(int)str.size(); ++i){
        if(i && str[i-1] != str[i])
            cout << " ";
        cout << str[i];
    }
    cout << "\n";
}

int main(){
    cout << toInt("100") * 3 << endl;
    cout << toInt("200") * 5 << endl;
    cout << toInt("0200") * 10 << endl;


    Grouping("111222333");
    Grouping("hossam");
    Grouping("hhoosssaamm");
    Grouping("hhhh");
    Grouping("");

    return 0;
}
