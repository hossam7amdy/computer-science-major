#include<iostream>
using namespace std;

// handle negative values
int hash_num(int num, int n = 7){
    return (num % n + n) % n;
}
// another approach
unsigned int hash_num2(int num, int n = 7){
    return (num % n + n) % n;
}

// handle overflow
int hash_num3(int num, int n = 7){
    long long n2 = n; // use variable > INT_MAX
    return (num % n2 + n2) % n2;
}
int hash_string(string str, int n = 7){
    long long sum {};
    long long n2 = n;
    for(int i=0; i<(int)str.size(); i++)
        sum = (sum * 26 + str[i] - 'a' ) % n2; // take modu with each step
    return sum;
}

int main(){
    cout << hash_num2(-100) << endl;
    cout << hash_num3(INT_MAX, INT_MAX * 5) << endl;

    cout << hash_string("abcdefghijklmopqrstuvwxyz") << endl;
    cout << hash_string("abcdefghijklmopqrstuvwxyzabcdefghijklmopqrstuvwxyz") << endl;
    cout << hash_string("abcdefghijklm") << endl;
    return 0;
}
