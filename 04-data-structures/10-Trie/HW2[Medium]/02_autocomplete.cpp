
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Trie{
private:
    map<char, Trie*> child;
    bool isLeaf{};
public:
    Trie(){
    }

    void Insert(const string &str){
        Trie* cur = this;
        for(int i=0; i<(int)str.size(); i++){
            if(!cur->child.count(str[i]))
                cur->child[str[i]] = new Trie();
            cur = cur->child[str[i]];
        }
        cur->isLeaf = true;
    }

    void get_all_content(vector<string> &v, string s = ""){
        if(isLeaf)
            v.push_back(s);
        for(const auto &pair : child){
            Trie* next = pair.second;
            next->get_all_content(v, s+pair.first);
        }
    }
    void auto_complete(const string &str, vector<string> &res){
        Trie* cur = this;
        for(int i=0; i<(int)str.size(); i++){
            if(cur->child.count(str[i]))
                cur = cur->child[str[i]];
        }

        cur->get_all_content(res, str);
    }


    /// my version
    void auto_complete1(const string &str, vector<string> &res, string s = "", int idx = -1){
        if(idx != -1 && s[idx] != str[idx] && idx < (int)str.size())
            return;

        if(isLeaf && (int)str.size() <= (int)s.size())
            res.push_back(s);

        for(const auto &pair : child){
            Trie* next = pair.second;
            next->auto_complete1(str, res, s + pair.first, idx+1);
        }
    }
};

int main() {
	Trie tree;

	tree.Insert("abcd");
	tree.Insert("xyz");
	tree.Insert("a");
	tree.Insert("ab");
	tree.Insert("xyzw");
	tree.Insert("bcd");

	vector<string> res;
	tree.auto_complete("ab", res);
	for (int i = 0; i < (int) res.size(); ++i)
		cout << res[i] << "\n";

	return 0;
}
