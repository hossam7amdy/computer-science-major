#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<deque>
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

    void print_level_order_spiral(){
        deque<BinaryTree*> ready;
        ready.push_front(this);

        int level = 1;
        while(!ready.empty()){
            int sz = (int)ready.size();
            cout << "Level " << level << ": ";
            while(sz--){
                BinaryTree* cur;
                if(level % 2 != 0){
                    cur = ready.front();
                    ready.pop_front();

                    if(cur->left)
                        ready.push_back(cur->left);
                    if(cur->right)
                        ready.push_back(cur->right);
                }else{
                    cur = ready.back();
                    ready.pop_back();

                    if(cur->right)
                        ready.push_front(cur->right);
                    if(cur->left)
                        ready.push_front(cur->left);
                }
                cout << cur->data << " ";
            }
            cout << "\n";
            ++level;
        }
    }

};

void test1() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.print_level_order_spiral();
	/*
	Level 1: 1
    Level 2: 3 2
    Level 3: 4 5 6
    Level 4: 15 9 8 7
    */
	cout << "\n";
}

void test2() {
	BinaryTree tree(1);

	tree.add( { 2 }, { 'L' });
	tree.add( { 3 }, { 'R' });


	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });


	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

	tree.print_level_order_spiral();
    /*
    Level 1: 1
    Level 2: 3 2
    Level 3: 4 5 14 6
    Level 4: 12 15 16 15 9 13 8 7
    */
	cout << "\n";
}

int main() {
    test1();
    test2();

	cout << "bye\n";

	return 0;
}


