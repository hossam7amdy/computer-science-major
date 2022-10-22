#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;


int main(){
    int n,m,q;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> grid[i][j];

    cin >> q;
    while(q--){
        int r,c;
        cin >> r >> c;
        assert(r>=0 && r<n && c>=0 && c<m);

        int mx{ grid[r][c] };
        int dr[]{1,0,1,-1,0,-1,-1,1};
        int dc[]{0,1,1,0,-1,-1,1,-1};

        for(int i=0; i<8; ++i){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m)
                mx = max(mx, grid[nr][nc]);
        }
        cout << mx << "\n";
    }
    return 0;
}
