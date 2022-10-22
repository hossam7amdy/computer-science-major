#include<iostream>
using namespace std;

int main(){
    const int MAX {1000000};
    bool is_visited[MAX]{0};
    int sequence[201];

    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        if(i==0 || i==1){
            sequence[i] = i;
            is_visited[i] = 1;
        }
        else{
            int val = sequence[i-1] - (i-1) - 1;
            if(is_visited[val] || val < 0)
                val = sequence[i-1] + i;

            is_visited[val] = 1;
            sequence[i] = val;
        }
    }

    for(int i=0; i<n; ++i)
        cout << sequence[i] << " ";

    //cout << sequence[n-1] << endl;

    return 0;
}
