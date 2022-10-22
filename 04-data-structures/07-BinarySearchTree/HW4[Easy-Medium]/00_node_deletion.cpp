#include<iostream>
#include<assert.h>
using namespace std;

typedef int type;
class BinarySearchTree{
private:
    type data{ };
    BinarySearchTree* left{ };
    BinarySearchTree* right{ };

    BinarySearchTree* min_node(){
        BinarySearchTree* cur = this;
        while(cur && cur->left)
            cur = cur->left;
        return cur;
    }

    void special_delete(BinarySearchTree* child) {
		// Instead of deleting node and return its child
		// copy child data and remove him
		// why? as sometimes node is actually the original this
		// Deleting it is RTE
		// This is another complication we pay for our coding style
		// to use only a single class instead of class + struct like linkedlist
		data = child->data;
		left = child->left;
		right = child->right;
		delete child;
	}
    BinarySearchTree* delete_node(int target, BinarySearchTree* node){
        if(!node)
            return nullptr;

        if(target < node->data)
            node->left = delete_node(target, node->left);
        else if(target > node->data)
            node->right = delete_node(target, node->right);
        else{
            if(!node->left && !node->right){
                delete node;
                node = nullptr;
            }
            else if(!node->right)
                node->special_delete(node->left);
            else if(!node->left)
                node->special_delete(node->right);
            else{
                BinarySearchTree* mn = node->right->min_node();
                node->data = mn->data;
                node->right = delete_node(node->data, node->right);
            }
        }
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

	void delete_value(const type& target){
	    if(target == data && !left && !right)
            return; // design concern

        delete_node(target, this);
	}

    void Clear(){
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

	bool Search(const int& val){
	    if(val == data)
            return true;

        if(val<data)
            return left && left->Search(val);

	    return right && right->Search(val);
	}

	type min_value(){
        if(left)
            return left->min_value();
        return data;
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

	tree.delete_value(45);
	tree.print_inorder();

	cout << "bye\n";

	return 0;
}


