#include<iostream>
#include<unordered_set>
#include<map>
using namespace std;

int count_unique_substrings(const string &str){ // O(L^3)
    // O(L^3)
	// Try all possible substrings (L^2) and insert in hashset
	// Hashing a string is typically O(L)

    unordered_set<string> st;

    for(int i=0; i<(int)str.size(); ++i){
        string s;
        for(int j=i; j<(int)str.size(); ++j){
            s += str[j];
            st.insert(s);
        }
    }
    //for(const auto &item : st)
       // cout << item << " ";
    return st.size();

    // Note: Using a trie: we can efficiently solve it in O(L^2)
	// Don't create the string and add to trie
	// For every stating position: let the second loop keep inserting
	// In trie letter by letter and mark as leaf
	// Hence overall only 2 loops
}

int main(){
	cout << count_unique_substrings("aaab") << "\n";	// 7
	cout << count_unique_substrings("aaaaa") << "\n";	// 5
	cout << count_unique_substrings("aaaba") << "\n";	// 11
	cout << count_unique_substrings("abcdef") << "\n";	// 21

    return 0;
}
