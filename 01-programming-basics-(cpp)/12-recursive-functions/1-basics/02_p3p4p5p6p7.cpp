#include<iostream>
using namespace std;

/// p3: Array Max
int arr_max(int arr[], const int &sz){
    if(sz==0)
        return arr[0];
    int result = arr[sz-1];
    return max(result, arr_max(arr, sz-1));
}

/// p4: Array Sum
int arr_sum(int arr[], const int &sz){
    if(sz==1)
        return arr[0];
    int sum = arr[sz-1];
    return sum + arr_sum(arr, sz-1);
}

/// p5: Array Avg
double arr_avg(int arr[], const int &sz){
    if(sz==1)
        return arr[0];

    double sub = arr_avg(arr, sz-1);
    sub = sub * (sz-1);
    return (sub + arr[sz-1])/sz;
}

/// p6: Array Increment
void arr_increment(int arr[], const int &sz){
    if(sz==0)
        return;

    arr_increment(arr, sz-1);
    arr[sz-1] += sz-1;
}

/// p7: Array Accumulation
void arr_accu(int arr[], const int &sz){
    if(sz==1)
        return;

    arr_accu(arr, sz-1);
    arr[sz-1] += arr[sz-2];
}

int main(){
    int arr[]{1, 3, 5, 7, 4, 2};
    //cout << arr_max(arr, 5) << endl;
    //cout << arr_sum(arr, 5) << endl;
    //cout << arr_avg(arr, 5) << endl;
    //arr_increment(arr, 5);
    //arr_accu(arr, 5);
     max_left(arr, 6);
    for(const auto &item : arr)
        cout << item << " ";

    return 0;
}
