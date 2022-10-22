#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Trie{
private:
    map<string, Trie*> child;
    bool isLeaf{};
public:
    Trie(){
    }

    void Insert(const vector<string> &path){
        Trie* cur = this;
        for(int i=0; i<(int)path.size(); i++){
            if(!cur->child.count(path[i]))
                cur->child[path[i]] = new Trie();

            cur = cur->child[path[i]];
        }
        cur->isLeaf = true;
    }

    bool subpath_exist(const vector<string> &path){
        Trie* cur = this;
        for(int i=0; i<(int)path.size(); i++){
            if(!cur->child.count(path[i]))
                return false;

            cur = cur->child[path[i]];
        }
        return true;
    }
};

int main(){
	Trie tree;

	vector<string> path;

	path = {"home", "software", "eclipse"};
	tree.Insert(path);

	path = {"home", "software", "eclipse", "bin"};
	tree.Insert(path);

	path = {"home", "installed", "gnu"};
	tree.Insert(path);

	path = {"user", "mostafa", "tmp"};
	tree.Insert(path);

	path = {"user", "mostafa", "tmp"};
	cout << tree.subpath_exist(path) << "\n"; // 1

	path = {"user", "mostafa"};
	cout << tree.subpath_exist(path) << "\n"; // 1

	path = {"user", "mostafa", "private"};
	cout << tree.subpath_exist(path) << "\n"; // 0
    return 0;
}
