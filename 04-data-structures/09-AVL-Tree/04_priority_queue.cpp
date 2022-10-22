#include <iostream>
#include <cassert>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;


class PriorityQueue {
private:
	struct BinaryNode {
		int priority { };
		vector<int> tasks;

		int height { };
		BinaryNode* left { };
		BinaryNode* right { };

		BinaryNode(int task, int priority) :
				priority(priority) {
            tasks.push_back(task);
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
		cout << "right_rotation " << Q->priority << "\n";
		BinaryNode* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return P;
	}

	BinaryNode* left_rotation(BinaryNode* P) {
		cout << "left_rotation " << P->priority << "\n";
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

	BinaryNode* insert_node(int task, int priority, BinaryNode* node) {
		if (priority < node->priority) {
			if (!node->left)
				node->left = new BinaryNode(task, priority);
			else	// change left. update left as it might be balanced
				node->left = insert_node(task, priority, node->left);
		} else if (priority > node->priority) {
			if (!node->right)
				node->right = new BinaryNode(task, priority);
			else
				node->right = insert_node(task, priority, node->right);
		}else
            node->tasks.push_back(task);
		node->update_height();
		return balance(node);
	}

	BinaryNode* min_node(BinaryNode* cur) {
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}
	BinaryNode* max_node(BinaryNode* cur){
	    while(cur && cur->right)
            cur = cur->right;
        return cur;
	}

	BinaryNode* delete_node(int priority, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (priority < node->priority)
			node->left = delete_node(priority, node->left);
		else if (priority > node->priority)
			node->right = delete_node(priority, node->right);
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
				node->priority = mn->priority;	// copy & go delete
				node->right = delete_node(node->priority, node->right);
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

public:
	void enqueue(int task, int priority) {
		if (!root)
			root = new BinaryNode(task, priority);
		else
			root = insert_node(task, priority, root);
	}
	int dequeue() {
        assert(!isempty());

        BinaryNode* mx = max_node(root);
        assert((int) mx->tasks.size() > 0);

        int task = mx->tasks.back();
        mx->tasks.pop_back();
        if((int) mx->tasks.size() == 0)
            root = delete_node(mx->priority, root);

		return task;
	}
	bool isempty(){
        return root == nullptr;
	}
};


int main() {
	PriorityQueue tasks;

	tasks.enqueue(1131, 1);
	tasks.enqueue(3111, 3);
	tasks.enqueue(2211, 2);
	tasks.enqueue(3161, 3);
	tasks.enqueue(7761, 7);

	cout << tasks.dequeue() << "\n";	// 7761
	cout << tasks.dequeue() << "\n";	// 3161

	tasks.enqueue(1535, 1);
	tasks.enqueue(2815, 2);
	tasks.enqueue(3845, 3);
	tasks.enqueue(3145, 3);

	// 3145 3845 3111 2815 2211 1535 1131
	while (!tasks.isempty())
		cout << tasks.dequeue() << " " << flush;

	cout<<"\n\nbye";
	return 0;
}



