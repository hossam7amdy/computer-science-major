#include<iostream>
using namespace std;

bool isPrefix(const string &str1, const string &str2){
    int sz = (int)str2.size();
    for(int i=0; i<sz; ++i)
        if(str1[i] != str2[i])
            return false;

    return true;
}

bool isSuffix(const string &str1, const string &str2){
    int sz1 = (int)str1.size();
    int sz2 = (int)str2.size();

    for(int i=0; i<sz2; ++i)
        if(str1[sz1 - i - 1] != str2[sz2 - i - 1])
            return false;

    return true;
}

bool isSubstring(const string &str1, const string &str2){
    int sz1 = (int)str1.size();
    int sz2 = (int)str2.size();

    if(sz2 > sz1)
        return false;

    int j = 0;
    for(int i=0; i<sz1 && j<sz2; ++i){
        if(j && str1[i] != str2[j])
            return false;

        j+=(str1[i] == str2[j]);
    }

    return j == sz2;
}

bool isSubsequence(const string &str1, const string &str2){
    int sz1 = (int)str1.size();
    int sz2 = (int)str2.size();

    if(sz2 > sz1)
        return false;

    int j = 0;
    for(int i=0; i<sz1 && j<sz2; ++i)
        j+=(str1[i] == str2[j]);

    return j == sz2;
}

int main(){
    cout << isSubsequence("ABCDEFG","ABCD") << endl;
    cout << isSubsequence("ABCDEFG","ABCDEF") << endl;
    cout << isSubsequence("ABCDEFG","EFG") << endl;
    cout << isSubsequence("ABCDEFG","DEFG") << endl;
    cout << isSubsequence("ABCDEFG","BCD") << endl;
    cout << isSubsequence("ABCDEFG","DEF") << endl;
    cout << isSubsequence("ABCDEFG","ACEG") << endl;
    cout << isSubsequence("ABCDEFG","DG") << endl;
    cout << isSubsequence("ABCDEFG","GD") << endl;
    cout << isSubsequence("ABCDEFG","ABCDEFG") << endl;

    return 0;
}
