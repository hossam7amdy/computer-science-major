#include<iostream>
using namespace std;

int main(){
    int n, m;
    int grid[10][10]{};
    cin >> n >> m;
    for(int r=0; r<n; ++r)
        for(int c=0; c<m; ++c)
            cin >> grid[r][c];

    int q;
    cin >> q;
    while(q--){
        int r1, r2, sum1{}, sum2{};
        cin >> r1 >> r2;
        --r1, --r2;
        for(int c=0; c<m; ++c){
            sum1 += grid[r1][c];
            sum2 += grid[r2][c];
        }

        if(sum1<sum2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
