#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

int count_substrings_match(const string &str1, const string &str2){ // O(L^3)

    unordered_set<string> st1;
    for(int i=0; i<(int)str1.size(); ++i){
        string s;
        for(int j=i; j<(int)str1.size(); ++j){
            s += str1[j];
            st1.insert(s);
        }
    }

    unordered_set<string> st2;
    for(int i=0; i<(int)str2.size(); ++i){
        string s;
        for(int j=i; j<(int)str2.size(); ++j){
            s += str2[j];
            st2.insert(s);
        }
    }

    int res {};
    for(const auto &item : st1)
        res += (st2.count(item));

    return res;
}

int main(){

	cout << count_substrings_match("aaab", "aa") << "\n";		// 2
	cout << count_substrings_match("aaab", "ab") << "\n";		// 3
	cout << count_substrings_match("aaaaa", "xy") << "\n";		// 0
	cout << count_substrings_match("aaaaa", "aaaaa") << "\n";	// 5

    return 0;
}
