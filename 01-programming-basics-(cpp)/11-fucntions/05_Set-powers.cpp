#include <iostream>
using namespace std;

/*
● Implement this function
● void set_powers(int arr[], int len = 5, int m = 2)
● This function will fill the array of len as following:
    ○ The i-th position: m^i, e.g. m * m * m … i times
    ○ E.g. for len = 6, m = 2 ⇒ 1 2 4 8 16 32
    ○ E.g. for len = 4, m = 3 ⇒ 1 3 9 27
● After a return from call: print the array
○ Try it with different default value scenarios
*/

int pow(int num, int pow){ //normal power fun
    int result = 1;
    for(int i=0; i<pow; i++)
        result *= num;
    return result;
}

void set_powers(int arr[], int len=5, int m=2){
    for(int i=0; i<len; i++)
        arr[i] = pow(m,i);
}


int main() {
    int const MAX = 100;
    int arr[MAX];

    int n;
    cin >> n;

    set_powers(arr, n, 3);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

	return 0;
}
