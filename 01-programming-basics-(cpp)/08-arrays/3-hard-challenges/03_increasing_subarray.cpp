#include<iostream>
using namespace std;

int is_increasing(int arr[], int st, int en){
    for(int i=st+1; i<=en; ++i)
        if(arr[i-1] > arr[i])
            return false;
    return true;
}

int v1(int arr[], const int &sz){ // O(n^3)
    int c{};
    for(int i=0; i<sz; ++i){
        for(int j=i; j<sz; ++j){
            c += is_increasing(arr, i, j);
        }
    }
    return c;
}

int v2(int arr[], const int &n){ // O(n^2)
	int result = 0;

	// for every index i in the array we consider it as the start of a subarry
	for (int i = 0; i < n; i++) {
		// adding one to result because any subarray of size one is considered increasing
		// this subarray will include the value in index i
		result++;
		// trying expanding a subarray which starts with at index i and
		// if this subarray still increasing then we add one to our result
		// otherwise we should stop expanding this subarray
		for (int j = i + 1; j < n; j++) {
			// if the current value is greater than or equal the previous one
			// then it's increasing
			if (arr[j] >= arr[j - 1])
				result++;
			// otherwise stop
			else
				break;
		}
	}

	// printing the result
	return  result;
}

int v3(int arr[], const int &sz){ // O(n)
    int sum{}, len{1};
    for(int i=1; i<sz; ++i){
        if(arr[i-1] <= arr[i]){
            sum += len;
            ++len;
        }
        else
            len = 1;
    }
    sum += sz;

    return sum;
}

int main(){
    const int MAX {200};
    int arr[MAX]{};

    int n; cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];

    cout << v1(arr, n) << endl;
    cout << v2(arr, n) << endl;
    cout << v3(arr, n) << endl;



    return 0;
}
