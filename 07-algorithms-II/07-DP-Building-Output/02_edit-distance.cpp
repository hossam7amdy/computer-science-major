#include <bits/stdc++.h>
using namespace std;

const int MAX = 500 + 1;
int memo[MAX][MAX];

string w1, w2;
int w1Len, w2Len;

int calcDistance(int i, int j){
    if(i == w1Len)
        return w2Len - j; // add remains

    if(j == w2Len)
        return w1Len - i; // delete remains

    int &ret = memo[i][j];
    if(ret != -1)
        return ret;

    if(w1[i] == w2[j])
        return calcDistance(i + 1, j + 1);

    int ins = 1 + calcDistance(i,j+ 1);
    int del = 1 + calcDistance(i+1, j);
    int rep = 1 + calcDistance(i+1,j+1);

    return min(ins, min(del, rep));
}

void editDistancePrint(int i, int j){
    if(i == w1Len){
        for(;j < w2Len; ++j) // add remains
            cout << "In `" << w1 << "` insert " << w2[j] << " at position " << i++ << "\n";
        return;
    }

    if(j == w2Len){
        for(;i < w1Len; ++i) // delete remains
            cout << "In `" << w1 << "` delete " << w1[i] << " at position " << i << "\n";
        return;
    }

    if(w1[i] == w2[j]){
        editDistancePrint(i + 1, j + 1);
        return;
    }

    int ins = 1 + calcDistance(i,j+ 1);
    int del = 1 + calcDistance(i+1, j);

    int optimal = calcDistance(i,j);

    if(optimal == ins){
        cout << "In `" << w1 << "` insert " << w2[j] << " at position " << i << "\n";
        editDistancePrint(i, j + 1);
    }
    else if(optimal == del){
        cout << "In `" << w1 << "` delete " << w1[i] << " at position " << i << "\n";
        editDistancePrint(i + 1, j);
    }
    else{ // replace
        cout << "In `" << w1 << "` replace " << w1[i] << " with " << w2[j] << " at position " << i << "\n";
        editDistancePrint(i+1, j+1);
    }
}

int editDistance(const string &word1, const string &word2){
    memset(memo, -1, sizeof(memo));
    w1 = word1, w2 = word2;
    w1Len = (int)w1.size();
    w2Len = (int)w2.size();

    int ans = calcDistance(0,0);

    editDistancePrint(0,0);
    cout << ans << " steps in total\n";
    return ans;
}

int main(){
    editDistance("xy","axy");
    editDistance("axy","xy");
    editDistance("axy","bxy");
    editDistance("axy","a");
    editDistance("a","axy");
    editDistance("axy","axy");

    editDistance("horse","ros");
    editDistance("park","spake");
    editDistance("spake","park");
    editDistance("spakehz","park");

    return 0;
}
