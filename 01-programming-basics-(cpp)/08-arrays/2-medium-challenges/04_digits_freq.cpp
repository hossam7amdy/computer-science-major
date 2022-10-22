#include<iostream>
using namespace std;

int main(){
    const int MAX {10};
    int freq[MAX]{};
    int n{};
    cin >> n;

    while(n--){
        int num{};
        cin >> num;

        while(num){
            int digit = num%10;
            freq[digit]++;
            num/=10;
        }
    }

    for(int i=0; i<MAX; ++i)
        cout << i << " = " << freq[i] << endl;


    return 0;
}
