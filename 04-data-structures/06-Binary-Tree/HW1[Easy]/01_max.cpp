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
};


int main() {
	BinaryTree tree(2);
	tree.add( { 3 }, { 'L' });
	tree.add( { 13 }, { 'R' });
	tree.add( { 13, 7 }, { 'R', 'L' });
	tree.add( { 13, 8 }, { 'R', 'R' });

	tree.print_inOrder();
	// 3 2 7 13 8
	cout << "\n" << tree.tree_max() << "\n";

	return 0;
}
