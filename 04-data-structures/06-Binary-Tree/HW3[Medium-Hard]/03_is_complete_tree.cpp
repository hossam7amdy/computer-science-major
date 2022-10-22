#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
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
        //cout << "Node " << data << " deleted at address " << this << "\n";
        clear_nodes();
    }

    bool is_complete(){
        // Once there is a single missing node (left before right)
		// Nothing else should be there: on this level or next level
		queue<BinaryTree*> ready;
		ready.push(this);

		bool not_complete = false;
		while(!ready.empty()){
            BinaryTree* cur = ready.front();
            ready.pop();

            if(cur == nullptr)
                not_complete = true;
            else{
                if(not_complete)
                    return false;
                ready.push(cur->left);
                ready.push(cur->right);
            }
		}
        return true;
    }

};

void test1() {
	BinaryTree tree(1);

	assert(tree.is_complete());

	tree.add( { 2, 4}, { 'L', 'L'});
	tree.add( { 2, 5}, { 'L', 'R'});
	tree.add( { 3}, { 'R'});

	assert(tree.is_complete());

	tree.add( { 3, 7}, { 'R', 'R'});
	assert(!tree.is_complete());


	tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
	tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });

	assert(!tree.is_complete());

	tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
	tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
	tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
	tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });

	assert(tree.is_complete());
}

void test2() {
    // [1,2,3,5,null,7,8]
    BinaryTree tree2(1);

    tree2.add({2,4}, {'L','L'});
    tree2.add({3,7}, {'R','L'});
    tree2.add({3,8}, {'R','R'});

    assert(!tree2.is_complete());
}

int main() {
    test1();
    test2();

	cout << "bye\n";
	return 0;
}


