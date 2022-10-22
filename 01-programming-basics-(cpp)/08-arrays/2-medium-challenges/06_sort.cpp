#include<iostream>
using namespace std;

int main(){
    const int MAX {501};
    int freq[MAX]{};
    int n{};
    cin >> n;
    while(n--){
        int num;
        cin >> num;

        freq[num]++;
    }

    for(int i=0; i<MAX; ++i){
        if(freq[i])
            while(freq[i]--)
                cout << i << " ";
    }

    return 0;
}
