#include<iostream>
#include<vector>
using namespace std;

/// Properties: creates extra space
    // 1- Not In-place
    // 2- Not stable
    // 3- Not adaptive
    // 4- Not On-line

// k = max value of the array
void count_sort(vector<int> &v){ // time O(n) - memory O(k)
    int n{(int)v.size()};

    if(n <= 1) // no need to proceed
        return;

    // depends of frequency array trick
    int mx{v[0]};
    for(int i=1; i<n; ++i)
        mx = max(mx, v[i]);

    vector<int> freq(mx+1);
    for(int i=0; i<n; ++i)
        freq[v[i]]++;

    int j{};
    for(int i=0; i<(int)freq.size(); ++i)
        while(freq[i]--)
            v[j++] = i;
}

int main(){
    vector<int> v{1,1};
    count_sort(v);

    for(const auto &item : v)
        cout << item << " ";
    return 0;
}
