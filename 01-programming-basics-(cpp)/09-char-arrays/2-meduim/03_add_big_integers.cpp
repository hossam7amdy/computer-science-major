#include<iostream>
using namespace std;

string add(const string &num1, const string &num2){
    int sz1{(int)num1.size()};
    int sz2{(int)num2.size()};

    if(sz2 > sz1)
        return add(num2, num1);

    string res = num1;

    int carry{};
    for(int i=0; i<sz1; ++i){
        if(i<sz2)
            carry += (int)num2[sz2 - i - 1] - '0';

        carry += (int)(res[sz1 - i - 1] - '0');

        if(carry > 9){
            carry -= 10;
            res[sz1 - i - 1] = (char)(carry + '0');
            carry = 1;
        }
        else{
            res[sz1 - i - 1] = (char)(carry + '0');
            carry = 0;
        }
    }

    if(carry)
        res = "1" + res;

    return res;
}

int main(){
    cout << add("99","999") << endl;
    cout << add("10001234","5555") << endl;
    cout << add("3001072","5555") << endl;
    cout << add("10999999999","5555") << endl;
    cout << add("999999999999999999999999999999999","999999999999999999999999999999999") << endl;

    return 0;
}
