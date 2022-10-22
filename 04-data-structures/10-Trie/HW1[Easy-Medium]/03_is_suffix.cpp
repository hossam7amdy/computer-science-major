#include<iostream>
#include<cstring>
using namespace std;

class SuffixTrie{
private:
    static const int MAX_CHAR{26};
    SuffixTrie* child[MAX_CHAR];
    bool isLeaf{};
public:
    SuffixTrie(){
        memset(child, 0, sizeof(child));
    }

    void Insert(const string &str, int idx = 0){
        if((int)str.size() - idx - 1 == -1)
            isLeaf = true;
        else{
            int cur = str[(int)str.size()-idx-1] - 'a';
            if(!child[cur])
                child[cur] = new SuffixTrie();

            child[cur]->Insert(str, idx+1);
        }
    }

    bool suffix_exist(const string &suffix, int idx = 0){
        if((int)suffix.size() - idx - 1 == -1)
            return true;

        int cur = suffix[(int)suffix.size()-idx-1] - 'a';
        if(!child[cur])
            return false;

        return child[cur]->suffix_exist(suffix, idx+1);
    }
};

int main(){
	SuffixTrie root;

	root.Insert("abcd");
	root.Insert("xyz");
	root.Insert("abf");
	root.Insert("xn");
	root.Insert("ab");
	root.Insert("bcd");

	cout << root.suffix_exist("cd") << "\n";
	cout << root.suffix_exist("cc") << "\n";

    return 0;
}
