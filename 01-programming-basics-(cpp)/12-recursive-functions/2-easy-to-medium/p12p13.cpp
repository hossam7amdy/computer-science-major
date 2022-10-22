#include<iostream>
using namespace std;


/// p12: Is Palindrome
bool isPalindrome_v1(int arr[], int st, int en){
    if(st>=en)
        return true;

    // Short circuit
    return arr[st]==arr[en] && isPalindrome_v1(arr, st+1, en-1);
}
bool isPalindrome_v2(int arr[], int len){
    if(len<=1)
        return true;

    if(arr[0]!=arr[len-1])
        return false;

    // shift array trick
    return isPalindrome_v2(arr+1, len-2);
}

/// p13: Is Prefix
bool is_prefix(string main, string prefix, int start_pos = 0){
    if((int)main.size()<(int)prefix.size())
        return false;
    if(start_pos == (int)prefix.size())
        return true;

    return main[start_pos]==prefix[start_pos] && is_prefix(main, prefix, start_pos+1);
}

int main(){
    int arr[] {1,2,2,1};
    //cout << isPalindrome_v1(arr,0 ,2) << endl;
    //cout << isPalindrome_v2(arr, 4) << endl;

    cout << is_prefix("abcdefgh", "abcd") << endl;
    cout << is_prefix("abcdefgh", "") << endl;
    cout << is_prefix("abcdefgh", "abd") << endl;

    return 0;
}
