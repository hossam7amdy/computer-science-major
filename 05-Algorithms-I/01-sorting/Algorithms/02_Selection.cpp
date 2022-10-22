#include<iostream>
#include<vector>
using namespace std;


/// Properties:
    // 1- In-place
    // 2- Not stable => swaps
    // 3- Not adaptive => doesn't depend on the data.
    // 4- Not On-line => apply after insertion

void selection_sort(vector< pair<int, char>> &v){ // time O(n^2) - memory O(1)
    int n = (int)v.size();
    for(int i = 0; i < n - 1; ++i){
        int mn_idx{i};
        for(int j = i + 1; j < n; ++j)
            if(v[mn_idx].first > v[j].first)
                mn_idx = j;

        swap(v[mn_idx], v[i]); // put on right place
    }
}

int main(){
    vector<int> v1{-1,-2,-5};
    //selection_sort(v1);

    // 5 1 5 1 0
    // 0 1 5 1 5
    // 0 1 1 5 5
    vector<pair<int, char>> v2{make_pair(5,'A'),
                                make_pair(1,'A'),
                                make_pair(5,'B'),
                                make_pair(1,'B'),
                                make_pair(0,'A')};

    selection_sort(v2); // not stable algo

    for(const auto &pair : v2)
        cout << pair.first << pair.second << "\n";
    return 0;
}
