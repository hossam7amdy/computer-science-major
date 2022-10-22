#include <iostream>
using namespace std;

/*
● Implement the following 2 functions:
● bool is_prime(int num);
    ○ Return true if number is prime
● Int nth_prime(int n);
    ○ Return the n-th prime number. It should use is_prime function
    ○ E.g nth_prime(6) = 13
■ Recall: 2, 3, 5, 7, 11, 13, 17, 19
*/

bool is_prime(int num){
    if(num<=1)
        return 0;
    for(int i=2; i<num; i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

int nth_prime(int n){
    for(int i=2;;i++){
        n-=is_prime(i);
        if(!n)
            return i;
        else if(n<=0)
            return 0;
    }
}




int main() {
    for (int i = 1; i <= 20; ++i) {
		cout<<nth_prime(i)<<" ";
	}
	return 0;
}
