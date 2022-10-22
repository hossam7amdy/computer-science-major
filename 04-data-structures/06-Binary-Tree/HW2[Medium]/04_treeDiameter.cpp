#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;



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
    void print_inOrder() {
        if (left)
            left->print_inOrder();
        cout << data << " ";
        if(right)
            right->print_inOrder();
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
        // cout << "Node " << data << " deleted at address " << this << "\n";
        clear_nodes();
    }

    int tree_hieght() {
        int height = 0;
        if(left)
            height = 1 + left->tree_hieght();
        if(right)
            return max(height, 1 + right->tree_hieght());

        return height;
    }

    int tree_diameter() {
        if(!left && !right)
            return 0;

        int left_height = 0, right_height = 0;
        if(left)
            left_height = left->tree_hieght();
        if(right)
            right_height = right->tree_hieght();

        int diam_left = 0, diam_right = 0;
        if(left)
            diam_left = left->tree_diameter();
        if(right)
            diam_right = right->tree_diameter();

        return max(left_height + right_height + 1, max(diam_left, diam_right));
    }
};

void test() {
	BinaryTree tree(1);

	// assert(tree.tree_diameter() == 0);
	cout << tree.tree_diameter() << "\n";

	tree.add( { 2 }, { 'L' });
	tree.add( { 3 }, { 'R' });

	// assert(tree.tree_diameter() == 2);
	cout << tree.tree_diameter() << "\n";

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

	// assert(tree.tree_diameter() == 6);
	cout << tree.tree_diameter() << "\n";
}



int main() {
	test();

	cout << "\nbye\n";

	return 0;
}

