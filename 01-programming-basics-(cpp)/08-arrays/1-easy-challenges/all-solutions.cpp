#include<iostream>
using namespace std;

const int MAX = 201;
int arr[MAX]{};

void p1(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];

        if(i){
            if(arr[i-1]>arr[i]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

void p2(){
    int n;
    cin >> n;
    int mn{INT_MAX}, mx{INT_MIN};
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        mn = min(arr[i], mn);
        mx = max(arr[i], mx);
    }

    for(int i=0; i<n; ++i){
        if(arr[i] == mn)
            arr[i] = mx;
        else if(arr[i] == mx)
            arr[i] = mn;
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void p3(){
    int n;
    cin >> n;

    int last = -1;
    while(n--){
        int cur;
        cin >> cur;
        if(last != cur){
            last = cur;
            cout << last << " ";
        }
    }
}

void p4(){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];

    for(int i=0; i<n/2; ++i){
        if(arr[i] != arr[n-i-1]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

void p5(){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];

    int mn{INT_MAX};
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j)
            mn = min(mn ,arr[i] + arr[j] + j -i);
    }
    cout << mn << endl;
}

int main(){
    //p1();
    //p2();
    //p3();
    //p4();
    //p5();

    return 0;
}
