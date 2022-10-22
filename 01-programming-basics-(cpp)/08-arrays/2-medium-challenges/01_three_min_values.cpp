#include<iostream>
using namespace std;

int main(){
    const int MAX {1000};
    int arr[MAX]{};
    int n{};
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];

    int min1 {min(arr[0], min(arr[1], arr[2]))};
    int min3 {max(arr[0], max(arr[1], arr[2]))};
    int min2 {INT_MAX};
    if(min1<arr[0] && arr[0]<min3)
        min2 = arr[0];
    else if(min1<arr[1] && arr[1]<min3)
        min2 = arr[1];
    else if(min1<arr[2] && arr[2]<min3)
        min2 = arr[2];

    for(int i=3; i<n; ++i){
        if(arr[i]<min1){
            swap(min3, min2);
            swap(min2, min1);
            min1 = arr[i];
        }
        else if(arr[i]<min2){
            swap(min3, min2);
            min2 = arr[i];
        }
        else if(arr[i]<min3)
            min3 = arr[i];
    }

    cout << min1 << " " << min2 << " " << min3;


    return 0;
}
