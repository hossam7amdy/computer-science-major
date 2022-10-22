#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 80 + 1;
ll memory[MAX];

ll fib(int n){
    if(n <= 1)
        return 1; // base case

    auto &ret = memory[n];

    if(ret != -1)
        return ret;

    return ret = fib(n - 1) + fib(n - 2); // Recurrence
}

int main() {
    int n;
    cin >> n;

    memset(memory, -1, sizeof(memory));

    cout << fib(n) << "\n"; // 37889062373143906

    return 0;
}
