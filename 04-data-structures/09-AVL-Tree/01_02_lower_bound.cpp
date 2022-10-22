#include <iostream>
#include <cassert>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;


class AVLTree {
private:
	struct BinaryNode {
		int data { };
		int height { };
		BinaryNode* left { };
		BinaryNode* right { };

		BinaryNode(int data) :
				data(data) {
		}

		int ch_height(BinaryNode* node) {	// child height
			if (!node)
				return -1;			// -1 for null
			return node->height;	// 0 for leaf
		}
		int update_height() {	// call in end of insert function
			return height = 1 + max(ch_height(left), ch_height(right));
		}
		int balance_factor() {
			return ch_height(left) - ch_height(right);
		}
	};

	BinaryNode *root { };

	///////////////// AVL /////////////////////
	BinaryNode* right_rotation(BinaryNode* Q) {
		cout << "right_rotation " << Q->data << "\n";
		BinaryNode* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return P;
	}

	BinaryNode* left_rotation(BinaryNode* P) {
		cout << "left_rotation " << P->data << "\n";
		BinaryNode* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		P->update_height();
		Q->update_height();
		return Q;
	}

	BinaryNode* balance(BinaryNode* node) {
		if (node->balance_factor() == 2) { 			// Left
			if (node->left->balance_factor() == -1)	// Left Right?
				node->left = left_rotation(node->left);	// To Left Left

			node = right_rotation(node);	// Balance Left Left
		} else if (node->balance_factor() == -2) {
			if (node->right->balance_factor() == 1)
				node->right = right_rotation(node->right);

			node = left_rotation(node);
		}
		return node;
	}

	BinaryNode* insert_node(int target, BinaryNode* node) {
		if (target < node->data) {
			if (!node->left)
				node->left = new BinaryNode(target);
			else	// change left. update left as it might be balanced
				node->left = insert_node(target, node->left);
		} else if (target > node->data) {
			if (!node->right)
				node->right = new BinaryNode(target);
			else
				node->right = insert_node(target, node->right);
		}
		node->update_height();
		return balance(node);
	}

	BinaryNode* min_node(BinaryNode* cur) {
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	BinaryNode* delete_node(int target, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (target < node->data)
			node->left = delete_node(target, node->left);
		else if (target > node->data)
			node->right = delete_node(target, node->right);
		else {
			BinaryNode* tmp = node;

			if (!node->left && !node->right)	// case 1: no child
				node = nullptr;
			else if (!node->right) 	// case 2: has left only
				node = node->left;		// connect with child
			else if (!node->left)	// case 2: has right only
				node = node->right;
			else {	// 2 children: Use successor
				BinaryNode* mn = min_node(node->right);
				node->data = mn->data;	// copy & go delete
				node->right = delete_node(node->data, node->right);
				tmp = nullptr;	// Don't delete me. Successor will be deleted
			}
			if (tmp)
				delete tmp;
		}
		if (node) {
			node->update_height();
			node = balance(node);
		}
		return node;
	}

    //////////////// Homeworks/Private //////////////////
	BinaryNode* get_lower_bound(const int& target, BinaryNode* node){
	    if(!node)
            return nullptr;

        if(node->data >= target){
            BinaryNode* ans = get_lower_bound(target, node->left);
            if(ans)
                return ans;
            return node;
        }
        return get_lower_bound(target, node->right);
	}
	BinaryNode* get_upper_bound(const int& target, BinaryNode* node, BinaryNode* ans = nullptr){
	    if(!node) return ans;

	    if(node->data > target)
            return get_upper_bound(target, node->left, ans = node);

        return get_upper_bound(target, node->right, ans);
	}

public:
	void insert_value(int target) {
		if (!root)
			root = new BinaryNode(target);
		else
			root = insert_node(target, root);
	}
	void delete_value(int target) {
		if (root) {
			root = delete_node(target, root);
		}
	}

    //////////////// Homeworks/Public ///////////////////
	pair<bool, int> lowerBound(const int& target){
        if(root){
            BinaryNode* ans = get_lower_bound(target, root);
            if(ans)
                return make_pair(true, ans->data);
        }
        return make_pair(false, -1);
	}
	pair<bool, int> upperBound(const int& target){
        if(root){
            BinaryNode* ans = get_upper_bound(target, root);
            if(ans)
                return make_pair(true, ans->data);
        }
        return make_pair(false, -1);
	}

};


void test_lower() {
	AVLTree tree;

	vector<int> v { 10, 5, 20, 15, 50, 70, 2, 13, 40 };
	// 2, 5, 10, 13, 15, 20, 40, 50, 70

	for (int i = 0; i < v.size(); ++i)
		tree.insert_value(v[i]);

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
		cout << v[i]+1<< " " << tree.lowerBound(v[i]+1 ).second << "\n";
}

void test_upper() {
	AVLTree tree;

	vector<int> v { 10, 5, 20, 15, 50, 70, 2, 13, 40 };

	for (int i = 0; i < v.size(); ++i)
		tree.insert_value(v[i]);

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i]<< " " << tree.upperBound(v[i] ).second << "\n";
}

int main() {
	//test_lower();
	test_upper();

	cout << "bye\n";

	return 0;
}



