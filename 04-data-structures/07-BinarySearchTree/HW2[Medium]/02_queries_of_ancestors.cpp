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

    pair<BinarySearchTree*, BinarySearchTree*> Find(const int& target, pair<BinarySearchTree*, BinarySearchTree*> res = make_pair(nullptr,nullptr)){
	    if(data>target)
            res.first = this; // parent

	    if(target == data){
            res.second = this; // child
            return res;
	    }

        if(left && target<data)
            return left->Find(target, res);

        if(right && target>data)
            return right->Find(target, res);

        return res;
	}

public:
    BinarySearchTree(const type &data):
        data(data){
    }

    void Insert(const int& val){
        if(val<data){
            if(!left)
                left = new BinarySearchTree(val);
            else
                left->Insert(val);
        }
        else{
            if(!right)
                right = new BinarySearchTree(val);
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
	    pair<BinarySearchTree*, BinarySearchTree*> p = Find(target);

        if(p.second && p.second->right)
            return make_pair(true, p.second->right->min_value());

        if(p.first)
            return make_pair(true, p.first->data);

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


