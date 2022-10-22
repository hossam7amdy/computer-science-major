#include<iostream>
using namespace std;

int main(){
    const int MAX {1000};
    int arr[MAX]{};
    int n{};
    cin >> n;

    int freq[MAX]{0};
    for(int i=0; i<n; ++i){
        cin >> arr[i];

        if(arr[i]<0)
            freq[-arr[i]+270]++;
        else
            freq[arr[i]]++;
    }

    int most_freq{}, times{};
    for(int i=0; i<MAX; ++i){
        times = max(freq[i], times);
        if(times == freq[i])
            most_freq = i;
    }

    if(most_freq>270)
        most_freq = 270 - most_freq;

    cout << most_freq << " repeated " << times << endl;


    return 0;
}
