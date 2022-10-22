#include<iostream>
#include<vector>
#include<cmath>
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
    type tree_max(){
        int mx = data;
        if(left)
            mx = max(mx, left->tree_max());
        if(right)
            mx = max(mx, right->tree_max());
        return mx;
    }
    int tree_height(){
        int res = 0;
        if(left)
            res = 1 + left->tree_height();
        if(right)
            res = max(res, 1 + right->tree_height());

        return res;
    }
    int count_nodes(){
        int res = 1;
        if(left)
            res += left->count_nodes();
        if(right)
            res += right->count_nodes();
        return res;
    }
    int count_leaves(){
        int res = !left && !right;
        if(left)
            res += left->count_leaves();
        if(right)
            res += right->count_leaves();

        return res;
    }
    bool is_exist(const type &value){
        bool found = data == value;

        if(!found && left)
            found = left->is_exist(value);
        if(!found && right)
            found = right->is_exist(value);

        return found;
    }
    bool is_perfect(int h = -1){
        if(h == -1)
            h = tree_height();

        if(!left && !right) // at leave
            return h == 0; // hight must be == 0

        if(!left && right || left && !right)
            return false; // one child

        return left->is_perfect(h-1) && right->is_perfect(h-1); // we are less one hight
    }
    bool is_perfect_formula(){
        int n = count_nodes();
        int h = tree_height();
        return pow(2, h+1)-1 == n;
    }
};


void test1_numbers() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	assert(tree.tree_max() == 15);
	assert(tree.tree_height() == 3);
	assert(tree.count_nodes() == 10);
	assert(tree.count_leaves() == 4);

	assert(tree.is_exist(1));
	assert(tree.is_exist(15));
	assert(tree.is_exist(4));
	assert(!tree.is_exist(61));
}

void test2_is_perfect() {
	BinaryTree tree(1);

	assert(tree.is_perfect() == 1);

	tree.add( { 2 }, { 'L' });
	tree.add( { 3 }, { 'R' });

	assert(tree.is_perfect() == 1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	assert(tree.is_perfect() == 0);

	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

	assert(tree.is_perfect() == 1);	// now 8 leaf nodes
}

int main() {
	test1_numbers();
	test2_is_perfect();

	cout << "bye\n";

	return 0;
}

