#include<iostream>
#include<cstring>
using namespace std;

class Trie{
private:
    static const int MAX_CHAR{26};
    Trie* child[MAX_CHAR];
    bool isLeaf{};

public:
    Trie(){
        memset(child, 0, sizeof(child));
    }
    //////////////// Homework ///////////////
    void Insert(const string& str){
        Trie* cur = this;

        for(int i=0; i<(int) str.size(); i++){
            int index = str[i] - 'a';
            if(cur->child[index] == 0)
                cur->child[index] = new Trie();
            cur = cur->child[index];
        }
        cur->isLeaf = true;
    }

    bool prefix_exist(const string& prefix){
        Trie* cur = this;

        for(int i=0; i<(int)prefix.size(); i++){
            int index = prefix[i] - 'a';
            if(cur->child[index] == 0)
                return false;
            cur = cur->child[index];
        }
        return true;
    }
    bool word_exist(const string& word){
        Trie* cur = this;

        for(int i=0; i<(int)word.size(); i++){
            int index = word[i] - 'a';
            if(cur->child[index] == 0)
                return false;
            cur = cur->child[index];
        }
        return cur->isLeaf;
    }
};

void test(){
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
}

int main(){
    test();
    return 0;
}
