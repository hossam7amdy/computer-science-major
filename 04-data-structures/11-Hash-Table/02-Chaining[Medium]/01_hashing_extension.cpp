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

int main() {

    cout<<hash_function("aabcdefgAxT334gfg", 65407);


	return 0;
}
