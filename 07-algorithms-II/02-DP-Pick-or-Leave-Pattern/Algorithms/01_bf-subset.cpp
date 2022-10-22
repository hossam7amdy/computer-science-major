#include <bits/stdc++.h>
using namespace std;

string res = "    ";
void all_subsets(int idx){
    if(idx == (int)res.size()){
        cout << res << "\n";
        return;
    }

    res[idx] = '0'; // try 0
    all_subsets(idx + 1);

    res[idx] = '1'; // try 1
    all_subsets(idx + 1);

    res[idx] = ' '; // backtrack
}

int main(){
    all_subsets(0);

    return 0;
}
