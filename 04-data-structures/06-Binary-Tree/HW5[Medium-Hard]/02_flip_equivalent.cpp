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

	string parenthesizing_canonical(){
        string ret = "(" + toStr(data);

        vector<string> v;
        if(left)
            v.push_back(left->parenthesizing_canonical());
        else
            v.push_back("()");
        if(right)
            v.push_back(right->parenthesizing_canonical());
        else
            v.push_back("()");

        sort(v.begin(), v.end());
        for(int i=0; i<(int)v.size(); i++)
            ret += v[i];

        ret += ")";
        return ret;
	}
	/// 1) Is Symmetric
	bool is_mirror(BinaryTree* first, BinaryTree* second){
	    if(!first && !second)
            return true;

        if(!first && second || first && !second || first->data != second->data)
            return false;

        return is_mirror(first->left, second->right) && is_mirror(first->right, second->left);
	}
	bool isSymmetric(){ // O(n)
	    return is_mirror(left, right);
	}
	string left_str(const BinaryTree* root){
        string ret;
        ret += "(" + toStr(root->data);
        if(root->left)
            ret += left_str(root->left);
        if(root->right)
            ret += left_str(root->right);
        ret += ")";

        return ret;
	}
	string right_str(const BinaryTree* root){
        string ret;
        ret += "(" + toStr(root->data);
        if(root->right)
            ret += right_str(root->right);
        if(root->left)
            ret += right_str(root->left);
        ret += ")";

        return ret;
	}
	bool isSymmetric2(){ // O(n)
        return left_str(left) == right_str(right);
	}
	/// 2) Flip Equivalent Binary Tree
	bool is_flip_equiv(BinaryTree* other){
	    return parenthesizing_canonical() == other->parenthesizing_canonical();
	}
};


void test1_isSymmetric() {
	BinaryTree tree(1);

	assert(tree.isSymmetric() == 1);

	tree.add( { 2 }, { 'L' });
	tree.add( { 2 }, { 'R' });

	assert(tree.isSymmetric() == 1);

	tree.add( { 2, 3, 5 }, { 'L', 'L', 'L' });
	tree.add( { 2, 3, 6 }, { 'L', 'L', 'R' });
	tree.add( { 2, 4, 7 }, { 'L', 'R', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'R', 'R' });

	assert(tree.isSymmetric() == 0);

	tree.add( { 2, 4, 8 }, { 'R', 'L', 'L' });
	tree.add( { 2, 4, 7 }, { 'R', 'L', 'R' });
	tree.add( { 2, 3, 6 }, { 'R', 'R', 'L' });

	assert(tree.isSymmetric() == 0);

	tree.add( { 2, 3, 5 }, { 'R', 'R', 'R' });

	assert(tree.isSymmetric() == 1);
}

void test2_isSymmetric() {
	BinaryTree tree(1);

	tree.add( { 2, 3 }, { 'L', 'L' });
	tree.add( { 2, 4, 5 }, { 'L', 'R', 'L' });
	tree.add( { 2, 4, 6 }, { 'L', 'R', 'R' });

	tree.add( { 2, 4, 6 }, { 'R', 'L', 'L' });
	tree.add( { 2, 4, 5 }, { 'R', 'L', 'R' });
	tree.add( { 2, 3 }, { 'R', 'R' });

	assert(tree.isSymmetric() == 1);
}

void test_all_duplicates() {
	BinaryTree tree(1);
	/*
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
	tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });

	tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
	tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
	tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
	tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });
	tree.add( { 3, 7, 15, 16 }, { 'R', 'R', 'R', 'R' });
	*/

	tree.add( { 2, 3 }, { 'L', 'L'});
	tree.add( { 4, 5, 6, 8, 9 }, { 'R', 'R', 'R', 'R', 'R' });
	tree.add( { 4, 2, 3 }, { 'R', 'L', 'L'});
	tree.add( { 4, 5, 6, 7 }, { 'R', 'R', 'L', 'L'});
	tree.add( { 4, 5, 6, 8, 9 }, { 'R', 'R', 'L', 'R', 'R'});
	tree.add( { 4, 5, 6, 7 }, { 'R', 'R', 'R', 'L'});

	// (2(3()())())
	// (6(7()())(8()(9()())))
	// (8()(9()()))

	//tree.print_duplicate_subtrees();
}

int main() {
	//test1_isSymmetric();
	test_all_duplicates();

	cout << "bye\n";

	return 0;
}

