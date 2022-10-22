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

    BinarySearchTree* get_next(vector<BinarySearchTree*> &ancestors){
	    if(ancestors.empty())
            return nullptr;

        BinarySearchTree* node = ancestors.back();
        ancestors.pop_back();

        return node;
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

	// modified search to get a chain of ancestors to the target
	bool find_chain(vector<BinarySearchTree*> &ancestors, const type& target){
	    ancestors.push_back(this);

	    if(target == data)
            return true;

        if(target<data)
            return left && left->find_chain(ancestors, target);

	    return right && right->find_chain(ancestors, target);
	}
	type get_min(){
        if(left)
            return left->get_min();
        return data;
	}
	pair<bool, type> successor(const type &target){
        vector<BinarySearchTree*> ancestors;

        if(!find_chain(ancestors, target))
            return make_pair(false, -1);

        BinarySearchTree* child = get_next(ancestors);
        if(child->right)
            return make_pair(true, child->right->get_min());

        BinarySearchTree* parent = get_next(ancestors);
        while(parent && parent->right == child)
            child = parent, parent = get_next(ancestors);

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
		pair<bool, int> p = tree.successor(v[i]);

		if (p.first)
			cout << p.second << "\n";
		else
			cout << "NA\n";

	}

	cout << "bye\n";

	return 0;
}
