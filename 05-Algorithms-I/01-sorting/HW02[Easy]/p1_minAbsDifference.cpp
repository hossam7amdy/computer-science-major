#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) { // nlog(n)
    sort(arr.begin(), arr.end()); // nlog(n)

    int minAbs{INT_MAX};
    for(int i=1; i<(int)arr.size(); ++i) // O(n)
        minAbs = min(minAbs, arr[i] - arr[i - 1]);

    vector<vector<int>> ret;
    for(int i=1; i<(int)arr.size(); ++i){ // O(n)
        if(arr[i] - arr[i - 1] == minAbs)
            ret.push_back({arr[i-1], arr[i]});
    }

    return ret;
}

int main(){


    return 0;
}
