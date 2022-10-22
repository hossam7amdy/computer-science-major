#include <iostream>
using namespace std;

/*
● Read N, then N integers for an Array. Call a function with the array to check if
the array is palindrome or note
    ○ We already coded it before
    ○ Just copy code and rearrange to call function with array
*/

bool is_pal(int arr[], int n){
    for(int i=0; i<n/2; i++){
        if(arr[i]!=arr[-i-1])
            return 0;
    }
    return 1;
}



int main() {
    int const MAX = 100;
    int arr[MAX];

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << is_pal(arr, n);

	return 0;
}
