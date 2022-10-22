#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

class Trie{
private:
    /// Dr/ Mostafa Notes:
    // based on self-balancing BST, so keys are sorted (which is logn), which usually not important

    unordered_map<char, Trie*> child;
    // This is based on hashing, O(1), but keys are not sorted

    //map<char, Trie*> child;
    bool isLeaf{};

public:
    Trie(){
    }

    void Insert(const string &str){ // iterative
        Trie* cur = this;
        for(int i=0; i<(int)str.size(); i++){
            if(!cur->child.count(str[i]))
                cur->child[str[i]] = new Trie();

            cur = cur->child[str[i]];
        }
        cur->isLeaf = true;
    }
    bool word_exist(const string &prefix, int idx = 0){ // recursive
        if((int)prefix.size() == idx)
            return isLeaf;

        if(!child.count(prefix[idx]))
            return false;

        return child[prefix[idx]]->word_exist(prefix, idx+1);
    }
};

int main(){
    Trie root;

	root.Insert("abcd");
	root.Insert("xyz");
	root.Insert("abf");
	root.Insert("xn");
	root.Insert("ab");
	root.Insert("bcd");

	cout << root.word_exist("xyz") << "\n";
	cout << root.word_exist("xn") << "\n";

    return 0;
}
