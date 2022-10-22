#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    const int MAX = 80 + 1;
    ll memory[MAX] = {1, 1}; // base case

    for(int i = 2; i < MAX; ++i)
        memory[i] = memory[i - 1] + memory[i - 2]; // Recurrence

    cout << memory[80] << "\n"; // 37889062373143906

    return 0;
}
