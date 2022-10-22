#include<iostream>
#include<vector>
using namespace std;

bool isPrime(const int &number){
    if(number<2)
        return false;

    for(int i=2; i<number; ++i)
        if(number % i == 0)
            return false;
    return true;
}

int main(){
    int n,m,q;
    cin >> n >> m;
    vector<vector<bool>> matrix(n, vector<bool>(m));

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            int val;
            cin >> val;

            // let's compute is prime once NOT with every query. Also no need for main array
            matrix[i][j] = isPrime(val);
        }
    }

    cin >> q;
    while(q--){
        int i,j,r,c, primes{};
        cin >> i >> j >> r >> c;

        if(r>n || c>m)
            break;

        // answer queries normally
        for(int k=0; k<r; ++k)
            for(int l=0; l<c; ++l)
                primes += matrix[i+k][j+l];

        cout << primes << endl;
    }

    return 0;
}
