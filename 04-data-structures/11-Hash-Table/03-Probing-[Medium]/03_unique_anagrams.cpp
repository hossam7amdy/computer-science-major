#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include<algorithm>
using namespace std;

    /// BIG WRONG :) ///
int hash_fun(const string &str, int n = 65407){
    long long sum{};
    for(int i=0; i<(int)str.size(); ++i){
        //cout << str[i] << " => " << str[i] - 'a' << endl;
        sum = 10 + sum + str[i] - 'a'; // to differentiate (a from aa) ...
        sum %= n;
    }

    return sum;
}

int count_unique_anagram1(const string &str){ // O(L^3)

    unordered_set<int> st;

    for(int i=0; i<(int)str.size(); ++i){
        string s;
        for(int j=i; j<(int)str.size(); ++j){
            s += str[j]; // O(L)
            st.insert(hash_fun(s));
        }
    }
    return st.size();
}

int count_unique_anagram2(const string &str){ // O(L^3 logL)

    unordered_set<string> st;
    for(int i=0; i<(int)str.size(); ++i){
        string s;
        for(int j=i; j<(int)str.size(); ++j){
            s += str[j]; // O(L)
            sort(s.begin(), s.end()); // O(L logL)
            st.insert(s);
        }
    }
    return st.size();
}

int main(){
    cout << "bc => " << hash_fun("bc") << " && " << "da => " << hash_fun("da") << "\n";
    //cout << count_unique_anagram1("abcdabcdabcd") << "\n";	// 6
	//cout << count_unique_anagram2("abcdabcdabcd") << "\n";	// 5
	//cout << count_unique_anagram1("abba55ABBA") << "\n";	// 9
	//cout << count_unique_anagram1("aabade") << "\n";	// 17

    return 0;
}
