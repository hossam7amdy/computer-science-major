#include<iostream>
using namespace std;

/// p8: Left Max
void left_max(int arr[], const int &len){
    if(len==1)
        return;

    left_max(arr, len-1);
    arr[len-1] = max(arr[len-1], arr[len-2]);
}

/// p9: Right Max
void right_max(int arr[], const int &len){
    if(len==1)
        return;

    arr[len-2] = max(arr[len-1], arr[len-2]);
    right_max(arr, len-1);
}

/// p10: Suffix Sum
int suffix_sum(int arr[], int len, int n){
    if(n==0)
        return 0;

    return arr[len-1] + suffix_sum(arr, len-1, n-1);
}

/// p11: Prefix Sum
int prefix_sum_v1(int arr[], int n){
    if(n==1)
        return arr[0];

    return arr[n-1] + prefix_sum_v1(arr, n-1);
}
int prefix_sum_v2(int arr[], int n){
    if(n==0)
        return 0;

    return arr[0] + prefix_sum_v2(arr+1, n-1);
}

int main(){
    int arr[] {1, 3, 4, 7, 4, 1};

    //right_max(arr, 6);
    //cout << suffix_sum(arr, 6, 3) << endl;
    //cout << prefix_sum_v2(arr, 3) << endl;


    return 0;
}
