#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

int hash_num(const int &num, int n = 65407){
    long long n_ = n;

    return (num % n_ + n_) % n_;
}

int hash_string(const string &str, int n = 65407){
    long long n_ = n;
    long long base = 2 * 26;
    long long sum{};

    for(int i=0; i<(int)str.size(); i++){
        long long val{};
        if(islower(str[i]))
            val = str[i] - 'a';
        else if(isupper(str[i]))
            val = 26 + str[i] - 'A';

        assert(!isdigit(str[i]));

        sum = sum * base + val;
        sum %= n_;
    }
    return sum;
}

class SomeObject{
private:
    const static int INTERNAL_LIMIT = 2147483647;

    int num;
    string str1, str2;

public:
    SomeObject(const int &num, const string &str1, const string &str2):
        num(num), str1(str1), str2(str2){
    }

    int Hash(){
        long long res = hash_string(str1+str2, INTERNAL_LIMIT);
        res += hash_num(num, INTERNAL_LIMIT);

        return res%INTERNAL_LIMIT;
    }
};


int main(){
    SomeObject object(123, "Hossam", "Hamdy");
    cout << object.Hash() << endl;

    SomeObject object1(123, "Hamdy", "Hossam");
    cout << object1.Hash() << endl;

    SomeObject object2(321, "Hossam", "Hamdy");
    cout << object2.Hash() << endl;

    SomeObject object3(123, "hossamYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYyyyyyyyyyyyyyyyyyyyyyyyyyyZZZZZZZZZZZZZZZZZZZZZZZZZ", "HamdyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYKDFAKDJFALSJDFKASJAKJA;lkajfljsdjlfjaklsjdfkl;asdfjlkas");
    cout << object3.Hash() << endl;


    return 0;
}
