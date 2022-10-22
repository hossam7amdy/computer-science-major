#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<sstream>
#include<algorithm>
#include<assert.h>
using namespace std;

string toStr(const int &val){
    ostringstream oss;
    oss << val;
    return oss.str();
}

typedef int type;
class BinaryTree{
private:
    type data{ };
    BinaryTree* left{ };
    BinaryTree* right{ };

public:
    BinaryTree(const type &data):
        data(data){
    }

    void add(const vector<type> &data, const vector<char> &direction){
        assert((int)data.size() == (int)direction.size());
        BinaryTree* current = this;

        for(int i=0; i<(int)data.size(); i++){
            if(direction[i] == 'L'){
                if(!current->left)
                    current->left = new BinaryTree(data[i]);
                else
                    assert(current->left->data == data[i]);
                current = current->left;
            }else{
                if(!current->right)
                    current->right = new BinaryTree(data[i]);
                else
                    assert(current->right->data == data[i]);
                current = current->right;
            }
        }
    }

    void clear_nodes() {
        if(left){
            delete left;
            left = nullptr;
        }
        if(right){
            delete right;
            right = nullptr;
        }
    }
    ~BinaryTree(){
        //cout << "Node " << data << " deleted at address " << this << "\n";
        clear_nodes();
    }

    void print_inorder() {
		if (left)
			left->print_inorder();
		cout << data << " ";
		if (right)
			right->print_inorder();
	}
	void print_preorder() {
		cout << data << " ";
		if (left)
			left->print_preorder();
		if (right)
			right->print_preorder();
	}
    void print_postorder() {
		if (left)
			left->print_postorder();
		if (right)
			right->print_postorder();
        cout << data << " ";
	}

	void print_preorder_complete(){
        cout << data << " ";
        if(left)
            left->print_preorder_complete();
        else
            cout << "-1 ";
        if(right)
            right->print_preorder_complete();
        else
            cout << "-1 ";
	}

	string preorder_parenthesizing(){
        string ret = "(" + toStr(data);
        if(left)
            ret += left->preorder_parenthesizing();
        else
            ret += "()";
        if(right)
            ret += right->preorder_parenthesizing();
        else
            ret += "()";
        ret += ")";

        return ret;
	}

	string parenthesizeing_canonical(){
        string ret = "(" + toStr(data);

        vector<string> v;
        if(left)
            v.push_back(left->parenthesizeing_canonical());
        else
            v.push_back("()");
        if(right)
            v.push_back(right->parenthesizeing_canonical());
        else
            v.push_back("()");

        sort(v.begin(), v.end());
        for(int i=0; i<(int)v.size(); i++)
            ret += v[i];

        ret += ")";
        return ret;
	}
};


void test(){
    BinaryTree tree(1);
    tree.add({2}, {'L'});
    tree.add({3}, {'R'});

    BinaryTree tree2(1);
    tree2.add({3}, {'L'});
    tree2.add({2}, {'R'});

    assert(tree.parenthesizeing_canonical() == tree2.parenthesizeing_canonical());
}

int main() {
    test();

	cout << "\nbye\n";

	return 0;
}


