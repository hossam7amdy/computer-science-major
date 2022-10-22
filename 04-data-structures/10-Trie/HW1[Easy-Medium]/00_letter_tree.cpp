#include<iostream>
#include<cstring>
using namespace std;

class Trie{
private:
    static const int MAX_CHAR{26};
    Trie* child[MAX_CHAR];
    bool isLeaf { };
public:
    Trie(){
        memset(child, 0, sizeof(child));
    }

    void Insert(const string &str, int idx = 0){
        if((int) str.size() == idx)
            isLeaf = true;
        else{
            int index = str[idx] - 'a';
            if(child[index] == 0)
                child[index] = new Trie();
            child[index]->Insert(str, idx+1);
        }
    }

    bool prefix_exist(const string &prefix, int idx = 0){
        if((int)prefix.size() == idx)
            return true;

        int cur = prefix[idx] - 'a';
        if(child[cur] == 0)
            return false;

        return child[cur]->prefix_exist(prefix, idx+1);
    }
    bool word_exist(const string& str, int idx = 0){
        if((int)str.size() == idx)
            return isLeaf;

        int cur = str[idx] - 'a';
        if(child[cur] == 0)
            return false;

        return child[cur]->word_exist(str, idx+1);
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
	cout << root.word_exist("xy") << "\n";
	cout << root.prefix_exist("xy") << "\n";

    return 0;
}
