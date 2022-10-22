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
        int c = 1;
        if(left)
            c += left->count_nodes();
        if(right)
            c += right->count_nodes();
        return c;
    }
    int count_leaves(){
        int res = !left && !right;
        if(left)
            res += left->count_leaves();
        if(right)
            res += right->count_leaves();

        return res;
    }
};


int main() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	tree.print_inOrder();
	// 7 4 8 2 5 9 1 3 10 6

	cout << "\n" << tree.count_leaves() <<"\n";

    BinaryTree tree2(2);
	tree2.add( { 3 }, { 'L' });
	tree2.add( { 13 }, { 'R' });
	tree2.add( { 13, 7 }, { 'R', 'L' });
	tree2.add( { 13, 8 }, { 'R', 'R' });

	cout << tree2.count_leaves() << "\n";

	return 0;
}
