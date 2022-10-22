#include<iostream>
using namespace std;


bool isPrime(int n, int mod=2){
    if(n<2)
        return false;
    if(n==mod || n==2)
        return true;

    return n%mod!=0 && isPrime(n, mod+1);
}

int countPrimes(int st, int en){
    if(st>en)
        return 0;

    return isPrime(st) + countPrimes(st+1, en);
}

int main(){
    cout << countPrimes(2, 10) << endl;
    cout << countPrimes(10, 20) << endl;
    cout << countPrimes(10, 200) << endl;
    //cout << countPrimes(2, 5000000) << endl; // ??

    return 0;
}
