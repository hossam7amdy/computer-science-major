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

        if(!freq[num]++)
            cout << num << " ";
    }

    return 0;
}
