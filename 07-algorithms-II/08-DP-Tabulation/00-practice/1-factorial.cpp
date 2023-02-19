#include <bits/stdc++.h>
using namespace std;

int fact(int n){

    int result = n;
    for(int i = n - 1; i > 0; --i)
        result *= i;

    return result;
}

int main() {

    cout << fact(6) << "\n";

    return 0;
}
