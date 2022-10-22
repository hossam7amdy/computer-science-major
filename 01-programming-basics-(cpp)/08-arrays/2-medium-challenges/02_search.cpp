#include<iostream>
using namespace std;

int main(){
    const int MAX {1000};
    int arr[MAX]{};
    int n{};
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];

    int q{};
    cin >> q;
    while(q--){
        int val{};
        cin >> val;
        int idx{-1};

        for(int i=0; i<n; ++i)
            if(arr[i]==val)
                idx = i;

        cout << idx << endl;
    }


    return 0;
}
