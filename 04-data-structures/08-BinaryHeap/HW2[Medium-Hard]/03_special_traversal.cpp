#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

class BinaryTree {
private:
	int data { };
	BinaryTree* left { };
	BinaryTree* right { };

public:

	BinaryTree(int data) :
			data(data) {
	}

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		BinaryTree* current = this;
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new BinaryTree(values[i]);
				else
					assert(current->left->data == values[i]);
				current = current->left;
			} else {
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->data == values[i]);
				current = current->right;
			}
		}
	}

	void print_inorder() {
		if (left)
			left->print_inorder();
		cout << data << " ";
		if (right)
			right->print_inorder();
	}
	////////////////////////////////////////////

	void level_order_traversal_sorted() {
		priority_queue< pair<int, BinaryTree*> > heaps[2];

		bool flag = 0;
		heaps[flag].push( make_pair(data, this) );


		int level = 0;
		while (!heaps[flag].empty()) {
			int sz = heaps[flag].size();

			cout<<"Level "<<level<<": ";
			while(sz--) {
                pair<int, BinaryTree*> cur_pair = heaps[flag].top();
				heaps[flag].pop();
				BinaryTree* cur = cur_pair.second;

				cout << cur_pair.first << " ";

				if (cur->left)
					heaps[!flag].push(make_pair(cur->left->data, cur->left));
				if (cur->right)
					heaps[!flag].push(make_pair(cur->right->data, cur->right));
			}
			level++;
			flag = !flag;
			cout << "\n";
		}
	}

};

void test() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

	tree.level_order_traversal_sorted();
}

void test1_level_order_traversal() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
	tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });

	tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
	tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
	tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
	tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });

	tree.level_order_traversal_sorted();
	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	tree.level_order_traversal_sorted();
	// Level 0: 1
	// Level 1: 2 3
	// Level 2: 4 5 6 7
	// Level 3: 8 9 10 11 12 13 14 15
}

int main() {
    test();
	test1_level_order_traversal();

	cout << "bye\n";

	return 0;
}

