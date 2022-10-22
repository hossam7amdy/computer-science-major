#include <iostream>
#include <cassert>
#include <queue>
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

	///////////////////////////
	bool Search(int target, BinaryNode* node) {
		if(!node)
			return false;

		if (target == node->data)
			return true;

		if (target < node->data)
			return Search(target, node->left);

		return Search(target, node->right);
	}

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

	bool is_bst(BinaryNode* node) {
		bool left_bst = !node->left || node->data > node->left->data && is_bst(node->left);

		if (!left_bst)
			return false;

		bool right_bst = !node->right || node->data < node->right->data && is_bst(node->right);
		return right_bst;
	}

	void verify() {
		assert(abs(root->balance_factor()) <= 1);
		assert(is_bst(root));
	}

	void print_inorder(BinaryNode* node) {
		if(!node)
			return;

		print_inorder(node->left);
		cout << node->data << " ";
		print_inorder(node->right);
	}

public:
	void insert_value(int target) {
		if (!root)
			root = new BinaryNode(target);
		else
			root = insert_node(target, root);

		verify();
	}

	void delete_value(int target) {
		if (root) {
			root = delete_node(target, root);
			verify();
		}
	}

	bool Search(int target) {
		return Search(target, root);
	}

	void print_inorder() {
		print_inorder(root);
	}

	void level_order_traversal() {
		if (!root)
			return;

		cout << "******************\n";
		queue<BinaryNode*> nodes_queue;
		nodes_queue.push(root);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout << "Level " << level << ": ";
			while (sz--) {
				BinaryNode*cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->data << " ";
				if (cur->left)
					nodes_queue.push(cur->left);
				if (cur->right)
					nodes_queue.push(cur->right);
			}
			level++;
			cout << "\n";
		}
	}
};


void f1() {
	AVLTree tree;

	for (int i = 0; i <= 32; ++i) {	// degenerate
		tree.insert_value(i);
		tree.level_order_traversal();
	}
}


int main() {
	f1();

	cout << "bye\n";

	return 0;
}



/*


 Level 0: 0
 Level 1: 1
 ******************
 Level 0: 1
 Level 1: 0 2
 ******************
 Level 0: 1
 Level 1: 0 2
 Level 2: 3
 ******************
 Level 0: 1
 Level 1: 0 3
 Level 2: 2 4
 ******************
 Level 0: 3
 Level 1: 1 4
 Level 2: 0 2 5
 ******************
 Level 0: 3
 Level 1: 1 5
 Level 2: 0 2 4 6
 ******************
 Level 0: 3
 Level 1: 1 5
 Level 2: 0 2 4 6
 Level 3: 7
 ******************
 Level 0: 3
 Level 1: 1 5
 Level 2: 0 2 4 7
 Level 3: 6 8
 ******************
 Level 0: 3
 Level 1: 1 7
 Level 2: 0 2 5 8
 Level 3: 4 6 9
 ******************
 Level 0: 3
 Level 1: 1 7
 Level 2: 0 2 5 9
 Level 3: 4 6 8 10
 ******************
 Level 0: 7
 Level 1: 3 9
 Level 2: 1 5 8 10
 Level 3: 0 2 4 6 11
 ******************
 Level 0: 7
 Level 1: 3 9
 Level 2: 1 5 8 11
 Level 3: 0 2 4 6 10 12
 ******************
 Level 0: 7
 Level 1: 3 11
 Level 2: 1 5 9 12
 Level 3: 0 2 4 6 8 10 13
 ******************
 Level 0: 7
 Level 1: 3 11
 Level 2: 1 5 9 13
 Level 3: 0 2 4 6 8 10 12 14
 ******************
 Level 0: 7
 Level 1: 3 11
 Level 2: 1 5 9 13
 Level 3: 0 2 4 6 8 10 12 14
 Level 4: 15
 ******************
 Level 0: 7
 Level 1: 3 11
 Level 2: 1 5 9 13
 Level 3: 0 2 4 6 8 10 12 15
 Level 4: 14 16
 ******************
 Level 0: 7
 Level 1: 3 11
 Level 2: 1 5 9 15
 Level 3: 0 2 4 6 8 10 13 16
 Level 4: 12 14 17
 ******************
 Level 0: 7
 Level 1: 3 11
 Level 2: 1 5 9 15
 Level 3: 0 2 4 6 8 10 13 17
 Level 4: 12 14 16 18
 ******************
 Level 0: 7
 Level 1: 3 15
 Level 2: 1 5 11 17
 Level 3: 0 2 4 6 9 13 16 18
 Level 4: 8 10 12 14 19
 ******************
 Level 0: 7
 Level 1: 3 15
 Level 2: 1 5 11 17
 Level 3: 0 2 4 6 9 13 16 19
 Level 4: 8 10 12 14 18 20
 ******************
 Level 0: 7
 Level 1: 3 15
 Level 2: 1 5 11 19
 Level 3: 0 2 4 6 9 13 17 20
 Level 4: 8 10 12 14 16 18 21
 ******************
 Level 0: 7
 Level 1: 3 15
 Level 2: 1 5 11 19
 Level 3: 0 2 4 6 9 13 17 21
 Level 4: 8 10 12 14 16 18 20 22
 ******************
 Level 0: 15
 Level 1: 7 19
 Level 2: 3 11 17 21
 Level 3: 1 5 9 13 16 18 20 22
 Level 4: 0 2 4 6 8 10 12 14 23
 ******************
 Level 0: 15
 Level 1: 7 19
 Level 2: 3 11 17 21
 Level 3: 1 5 9 13 16 18 20 23
 Level 4: 0 2 4 6 8 10 12 14 22 24
 ******************
 Level 0: 15
 Level 1: 7 19
 Level 2: 3 11 17 23
 Level 3: 1 5 9 13 16 18 21 24
 Level 4: 0 2 4 6 8 10 12 14 20 22 25
 ******************
 Level 0: 15
 Level 1: 7 19
 Level 2: 3 11 17 23
 Level 3: 1 5 9 13 16 18 21 25
 Level 4: 0 2 4 6 8 10 12 14 20 22 24 26
 ******************
 Level 0: 15
 Level 1: 7 23
 Level 2: 3 11 19 25
 Level 3: 1 5 9 13 17 21 24 26
 Level 4: 0 2 4 6 8 10 12 14 16 18 20 22 27
 ******************
 Level 0: 15
 Level 1: 7 23
 Level 2: 3 11 19 25
 Level 3: 1 5 9 13 17 21 24 27
 Level 4: 0 2 4 6 8 10 12 14 16 18 20 22 26 28
 ******************
 Level 0: 15
 Level 1: 7 23
 Level 2: 3 11 19 27
 Level 3: 1 5 9 13 17 21 25 28
 Level 4: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 29
 ******************
 Level 0: 15
 Level 1: 7 23
 Level 2: 3 11 19 27
 Level 3: 1 5 9 13 17 21 25 29
 Level 4: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
 ******************
 Level 0: 15
 Level 1: 7 23
 Level 2: 3 11 19 27
 Level 3: 1 5 9 13 17 21 25 29
 Level 4: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
 Level 5: 31
 ******************
 Level 0: 15
 Level 1: 7 23
 Level 2: 3 11 19 27
 Level 3: 1 5 9 13 17 21 25 29
 Level 4: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 31
 Level 5: 30 32


 */
