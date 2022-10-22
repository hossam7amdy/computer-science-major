#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 0 1 2 3 5 8 13

int main(){

    const int MAX = 80 + 1;
    ll a = 1, b = 1, c = -1; // base case

    for(int i = 2; i < MAX; ++i){
        c = a + b; // Recurrence
        a = b, b = c;
    }

    cout << c << "\n"; // 37889062373143906

    return 0;
}
