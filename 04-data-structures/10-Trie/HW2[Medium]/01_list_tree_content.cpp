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

    // O(NL) where N number of words and L is word length.
    void get_all_strings(vector<string> &res, string str = ""){
        if(isLeaf)
            res.push_back(str);

        for(const auto &pair : child){
            Trie* next = pair.second;
            next->get_all_strings(res, str + pair.first);
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
	tree.get_all_strings(res);
	for (int i = 0; i < (int) res.size(); ++i)
		cout << res[i] << "\n";

	return 0;
}
