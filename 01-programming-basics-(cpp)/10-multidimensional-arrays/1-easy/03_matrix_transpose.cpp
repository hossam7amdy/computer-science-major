#include<iostream>
using namespace std;

int main(){
    int n, m;
    int grid1[10][10]{};
    int grid2[10][10]{};
    cin >> n >> m;
    for(int r=0; r<n; ++r)
        for(int c=0; c<m; ++c){
            cin >> grid1[r][c];

            grid2[c][r] = grid1[r][c];
        }

    for(int r=0; r<m; ++r){
        for(int c=0; c<n; ++c)
            cout << grid2[r][c] << " ";
        cout << "\n";
    }


    return 0;
}
