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
    BinaryTree(deque<int> &preorder, deque<int> &inorder, int inorder_start = 0, int inorder_end = -1){
        if(inorder_end == -1)
            inorder_end = (int)inorder.size() - 1;

        int cur_root = preorder.front();
        preorder.pop_front();

        data = cur_root;

        for(int split = inorder_start; split <= inorder_end; ++split){
            if(inorder[split] == cur_root){
                if(inorder_start < split)
                    left = new BinaryTree(preorder, inorder, inorder_start, split - 1);
                if(split < inorder_end)
                    right = new BinaryTree(preorder, inorder, split + 1, inorder_end);
                break;
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

    void print_preorder() {
        cout << data << " ";
        if(left)
            left->print_preorder();
        if(right)
            right->print_preorder();
    }

    void print_postorder() {
        if(left)
            left->print_postorder();
        if(right)
            right->print_postorder();
        cout << data << " ";
    }

    void print_inorder() {
        if(left)
            left->print_inorder();
        cout << data << " ";
        if(right)
            right->print_inorder();
    }

    void print_level_order() {
        queue<BinaryTree*> que;
        que.push(this);

        int level = 0;
        while(!que.empty()){
            int sz = (int)que.size();

            cout << "Level " << level << ": ";
            while(sz--){
                BinaryTree* cur = que.front();
                que.pop();

                cout << cur->data << " ";

                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            level++;
            cout << "\n";
        }
    }

};


void test1() {
    // 1 2 4 7 8 5 9 3 6 10
    deque<int> preorder;
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(4);
    preorder.push_back(7);
    preorder.push_back(8);
    preorder.push_back(5);
    preorder.push_back(9);
    preorder.push_back(3);
    preorder.push_back(6);
    preorder.push_back(10);

    //7 4 8 2 5 9 1 3 10 6
    deque<int> inorder;
    inorder.push_back(7);
    inorder.push_back(4);
    inorder.push_back(8);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(9);
    inorder.push_back(1);
    inorder.push_back(3);
    inorder.push_back(10);
    inorder.push_back(6);

	BinaryTree tree(preorder,inorder);

	tree.print_preorder();
	cout << "\n";
    tree.print_postorder();
	cout << "\n";
	tree.print_inorder();
	cout << "\n";
	tree.print_level_order();
	cout << "\n";
}

void test2() {

	cout << "\n";
}

int main() {
    test1();
    //test2();

	cout << "bye\n";

	return 0;
}


