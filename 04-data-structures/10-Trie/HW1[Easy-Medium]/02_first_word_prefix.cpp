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
    /////////////////// Homework ////////////////
    string first_word_prefix(const string &str){
        Trie* cur = this;

        for(int i=0; i<(int)str.size(); i++){
            int index = str[i] - 'a';
            if(!cur->child[index])
                break;
            cur = cur->child[index];

            if(cur->isLeaf)
                return str.substr(0, i+1);
        }
        return str;
    }
};

void test(){
	Trie root;

	root.Insert("xyz");
	root.Insert("xyzwfe");



	cout << root.first_word_prefix("xyzeeeeee") << "\n";
}

int main(){
    test();
    return 0;
}
