#include<iostream>
using namespace std;

int main(){
    int n{}, val{}, lower_sum{}, upper_sum{};
    cin >> n;
    for(int r=0; r<n; ++r){
        for(int c=0; c<n; ++c){
            cin >> val;
            if(r<=c)
                upper_sum += val;
            if(r>=c)
                lower_sum += val;
        }
    }

    cout << lower_sum << "\n" << upper_sum << endl;

    return 0;
}
