#include<iostream>
#include<vector>
using namespace std;

/// Properties:
    // 1- In-place
    // 2- Stable
    // 3- Adaptive
    // 4- On-line => apply with insertion

void insertion_sort(vector<int> &v){ // time O(n^2) - memory O(1)

    for(int i=1; i<(int)v.size(); ++i){
        int key = v[i];
        int j = i-1;

        while(j>-1 && v[j]>key){
            v[j+1] = v[j]; // shift right
            --j;
        }

        v[j+1] = key; // The first right element
    }
}

int main(){
    vector<int> v1{-1,-2};
    insertion_sort(v1);

    vector<int> v2{9, 2, 10, 0, 5, 3, 90, 85};
    insertion_sort(v2);

    for(const auto &item : v1)
        cout << item << " ";

    return 0;
}
