#include<iostream>
using namespace std;

void test(){
    const int MAX = 150;
    int arr[MAX]{};

    int sz;
    cin >> sz;
    for(int i=0; i<sz; ++i)
        cin >> arr[i];
}

void p1(){ // find the 1st and 2nd max values
    const int MAX = 150;
    int arr[MAX]{};

    int sz;
    cin >> sz;
    for(int i=0; i<sz; ++i)
        cin >> arr[i];

    int max1{}, max2{};
    max1 = max(arr[0], arr[1]);
    max2 = min(arr[0], arr[1]);

    for(int i=2; i<sz; i++){
        if(arr[i] > max1)
            max2 = max1, max1 = arr[i];
        else if(arr[i] > max2)
            max2 = arr[i];
    }
    cout << max1 << " " << max2 << endl;
}

void p2(){ // find pair values of maximum sum
    const int MAX = 150;
    int arr[MAX]{};

    int sz;
    cin >> sz;
    for(int i=0; i<sz; ++i)
        cin >> arr[i];

    int max1{}, max2{}, idx1{}, idx2{};
    max1 = arr[0];
    if(arr[1] > max1){
        max2 = max1;
        max1 = arr[1], idx1 = 1;
    }

    for(int i=2; i<sz; ++i){
        if(arr[i]>max1){
            max2 = max1, idx2 = idx1;
            max1 = arr[i], idx1 = i;
        }
        else if(arr[i] > max2)
            max2 = arr[i], idx2 = i;
    }

    cout << "sum = " << max1 + max2 << " at indices [" << idx1 << "] and [" << idx2 << "]" << endl;
}

void p3(){ // find the most frequent number
    const int MAX = 150;
    int arr[MAX]{};

    int sz;
    cin >> sz;
    int freq[MAX+1]{0}; // freq array

    for(int i=0; i<sz; ++i){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int most_freq{}, times{};
    for(int i=0; i<MAX+1; ++i){
        if(freq[i] > times)
            times = freq[i], most_freq = i;
    }

    cout << most_freq << " repeated " << times << " times\n";
}


int main(){
    //p1();
    //p2();
    p3();

    return 0;
}
