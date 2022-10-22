#include<iostream>
using namespace std;

int v1(int arr[], const int &sz){ // O(n^3)
    int ans{};
    for(int i=0; i<sz; ++i){
        for(int j=sz-1; j>=i; --j){
            int ones{}, zeros{};
            for(int k=i; k<=j; k++)
                ones += arr[k], zeros += !arr[k];
            if(ones == zeros)
                ans = max(ans, ones+zeros);
        }
    }
    return ans;
}

int v2(int arr[], const int &sz){ // O(n^2)
    int ans{};
    for(int en=0; en<sz; ++en){
        int ones{}, zeros{};
        for(int st=en; st<sz; ++st){
            ones += arr[st], zeros += !arr[st];
            if(ones == zeros)
                ans = max(ans, ones+zeros);
        }
    }
    return ans;
}

/// To Do
// hint: accumulation
int v3(int arr[], const int &sz){ // O(n)

}

int main(){
    const int MAX{200};
    int arr[MAX]{};
    int n{};
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];

    cout << v1(arr, n) << endl;
    cout << v2(arr, n) << endl;

    return 0;
}
