#include<iostream>
#include<vector>
using namespace std;


    /// based on hash-tables trick ///

/// p4
void countSortString(vector<string> &v){ // time O(n+k) - memory O(k^2)

    const int LETTERS_SZ { 26 };

    vector<vector<string>> freq(LETTERS_SZ);

    for(int i=0; i<(int)v.size(); ++i){
        string str{v[i]};
        freq[str[0]-'a'].push_back(str);
    }

    int idx{};
    for(int i=0; i<LETTERS_SZ; ++i)
        for(int j=0; j<(int)freq[i].size(); ++j)
            v[idx++] = freq[i][j];

}

/// p5
void countSortPrefix(vector<string> &v){ // // time O(n+k) - memory O(k^2)

    const int LETTERS_SZ { 26 };
    const int ARRAY_SZ { LETTERS_SZ * LETTERS_SZ };

    vector<vector<string>> freq(ARRAY_SZ);

    for(int i=0; i<(int)v.size(); ++i){
        string str{ v[i] };
        // flatten array trick
        int idx = (str[0]-'a') * LETTERS_SZ + (str[1]-'a');
        freq[idx].push_back(str);
    }

    int idx{};
    for(int bucket = 0; bucket < ARRAY_SZ; ++bucket)
        for(int str_idx = 0; str_idx < (int)freq[bucket].size(); ++str_idx)
            v[idx++] = freq[bucket][str_idx];

}

int main(){
    vector<string> v{"az","ab","aa"};

    countSortPrefix(v);

    for(const auto &item: v)
        cout << item << " ";

    return 0;
}
