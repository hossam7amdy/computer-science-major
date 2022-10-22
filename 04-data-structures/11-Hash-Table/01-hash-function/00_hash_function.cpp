#include<iostream>
using namespace std;

int hash_num(int num, int n = 7){
    return num % n;
}

int hash_string(string str, int n = 7){
    int sum {};
    for(int i=0; i<(int)str.size(); i++)
        sum = sum * 26 + str[i] - 'a';
    return sum;
}

int main(){
    cout << hash_num(100) << endl;

    cout << hash_string("abcd") << endl;
    // same
    cout << hash_string("a") << endl;
    cout << hash_string("aaaa") << endl;
    return 0;
}
