#include<iostream>
#include<vector>
using namespace std;


/// Descending Sort
void insertion_sort_v2(vector<int> &v){ // memory O(n^2) - time O(1)
    for(int i=1; i<(int)v.size(); ++i)
        for(int j=i; j>0 && v[j]>v[j-1]; --j)
            swap(v[j], v[j-1]); // 3 operations each
}

void show(const vector<int> &v){
    for(const auto &item : v)
        cout << item << " ";
}

int main(){
    vector<int> v1{1,7, 2,3,11,7,7,7,7,7};
    insertion_sort_v2(v1);
    show(v1);

    return 0;
}
