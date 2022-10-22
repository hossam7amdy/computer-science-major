#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

int hash_function(const string &str, const int &n){
    int base = 2 * 26 + 10;
    long long nn = n;
    long long sum {};

    for(int i=0; i<(int) str.size(); i++){
        int val{};
        if(islower(str[i]))
            val = str[i] - 'a';
        else if(isupper(str[i]))
            val = 26 + str[i] - 'A';
        else if(isdigit(str[i]))
            val = 26 + 26 + str[i] - '0';
        else
            assert(false);

        sum = sum * base + val;
        sum %= nn;
    }
    return sum;
}

int hash_string_folding(const string &str, const int &n){
    long long sum {};
    for(int i=0; i<(int)str.size(); i+=4){
        string block = str.substr(i, 4);
        sum += hash_function(block, n);
        sum %= n;
    }
    return sum;
}

int main() {
    cout<<hash_string_folding("aabcdefgAxT334gfg", 65407);


	return 0;
}
