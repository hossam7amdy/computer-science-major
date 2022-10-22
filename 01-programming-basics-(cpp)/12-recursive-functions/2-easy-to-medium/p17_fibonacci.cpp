#include<iostream>
using namespace std;

// a lot of redundant overlapping
int cnt = 0;
int fib(int n){
    ++cnt;
    if(n <= 1)
        return 1;

    return fib(n-1) + fib(n-2);
}

// no overlapping (greedy)
long long fib_sequence[100]{0};
int cnt2 = 0;
long long fibonacci(int n){
    ++cnt2;
    if(n <= 1)
        fib_sequence[n] = 1;

    if(fib_sequence[n])
        return fib_sequence[n];

    fib_sequence[n] = fibonacci(n-1) + fibonacci(n-2);
    return fib_sequence[n];
}
// 1 1 2 3 5 8 13
int main(){
    int n;
    cin >> n;
    cout << fib(n) << ", Total Calls: " << cnt << endl;
    cout << fibonacci(n) << ", Total Calls: " << cnt2 << endl;

    // Iterative trial
    int sum{1}, prev{0};
    for(int i=1; i<n; ++i){
        int temp{prev};
        prev=sum;
        sum += temp;
    }
    cout << sum << endl;

    return 0;
}
