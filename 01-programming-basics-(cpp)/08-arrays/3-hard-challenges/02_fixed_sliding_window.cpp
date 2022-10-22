#include<iostream>
using namespace std;

int main(){
    const int MAX {201};
    int window[MAX]{};

    int k, n;
    cin >> k >> n;
    for(int i=0; i<n; ++i) cin >> window[i];

    // 3 7 1 0 3 -4 2 -6 9
    int idx{}, mx{INT_MIN}, sum = window[0];
    for(int i=1; i<n; ++i){
        sum += window[i];

        if(i >= k){
            sum -= window[i-k];
            if(sum > mx){
            mx = sum;
            idx = i;
            }
        }
    }

    cout << "max = " << mx << " at [" << idx - k + 1 << " : " << idx  << "]"<< endl;

    return 0;
}
