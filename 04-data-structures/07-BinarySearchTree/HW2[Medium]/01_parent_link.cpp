#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

typedef int type;
class BinarySearchTree{
private:
    type data{ };
    BinarySearchTree* left{ };
    BinarySearchTree* right{ };
    BinarySearchTree* parent{ };

    BinarySearchTree* Find(const int& target){
	    if(target == data)
            return this;

        if(left && target<data)
            return left->Find(target);

        if(right && target>data)
            return right->Find(target);

        return nullptr;
	}

public:
    BinarySearchTree(const type &data, BinarySearchTree* parent = nullptr):
        data(data),parent(parent) {
    }

    void Insert(const int& val){
        BinarySearchTree* cur_parent = this;
        if(val<data){
            if(!left)
                left = new BinarySearchTree(val, this);
            else
                left->Insert(val);
        }
        else{
            if(!right)
                right = new BinarySearchTree(val, this);
            else
                right->Insert(val);
        }
	}

    void Clear() {
        if(left){
            delete left;
            left = nullptr;
        }
        if(right){
            delete right;
            right = nullptr;
        }
    }
    ~BinarySearchTree(){
        //cout << "Node " << data << " deleted at address " << this << "\n";
        Clear();
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


	type min_value(){
	    BinarySearchTree* cur = this;
        while(cur && cur->left)
            cur = cur->left;
        return cur->data;
	}
	pair<bool, type> successor(const type& target){
	    BinarySearchTree* child = Find(target);

	    if(!child)
            return make_pair(false, -1);

        if(child->right)
            return make_pair(true, child->right->min_value());

        BinarySearchTree* parent = child->parent;
        while(parent && parent->right == child)
            child = parent, parent = child->parent;

        if(parent)
            return make_pair(true, parent->data);
        return make_pair(false, -1);
	}

};

int main() {
	BinarySearchTree tree(50);
	tree.Insert(20);
	tree.Insert(45);
	tree.Insert(70);
	tree.Insert(73);
	tree.Insert(35);
	tree.Insert(15);
	tree.Insert(60);

	//tree.print_inorder();
	vector<int> v { 15, 20, 35, 45, 50, 60, 70, 73, 100 };

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
		pair<bool, type> p = tree.successor(v[i]);

		if (p.first)
			cout << p.second << "\n";
		else
			cout << "NA\n";

	}

	cout << "bye\n";

	return 0;
}


