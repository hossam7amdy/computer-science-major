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

    bool word_exist(string str) {
		// If recursive: Time Limit Exceeded on leetcode
		Trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			if (!cur->child.count(str[idx]))
				return false;	// such path don't exist
			cur = cur->child[str[idx]];
		}
		return cur->isLeaf;
	}

    bool word_exist_with_1_change(string str){
        Trie* cur = this;
        for(int i=0; i<(int)str.size(); i++){
            if(cur->child.count(str[i]))
                cur = cur->child[str[i]];
            else{
                char cpy = str[i];
                for(char ch = 'a'; ch<='z'; ++ch){
                    if(cpy == ch)
                        continue;

                    str[i] = ch;
                    if(word_exist(str))
                        return true;
                }
                break;
            }
        }
        return false;
    }

};

int main() {
	Trie tree;

	tree.Insert("hello");
	tree.Insert("leetcode");

	cout << tree.word_exist_with_1_change("hello") << endl;
	cout << tree.word_exist_with_1_change("xello") << endl;
	cout << tree.word_exist_with_1_change("xyllo") << endl;
	cout << tree.word_exist_with_1_change("hhllo") << endl;
	cout << tree.word_exist_with_1_change("leetcoded") << endl;

	return 0;
}
