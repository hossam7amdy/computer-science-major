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
    BinaryTree(queue<pair<int, bool>> &preorder){
        auto cur = preorder.front();
        preorder.pop();

        data = cur.first;

        if(!cur.second){
            left = new BinaryTree(preorder);
            right = new BinaryTree(preorder);
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
    queue<pair<int, bool>> preorder;
    preorder.push({1,0});
    preorder.push({2,1});
    preorder.push({3,1});

    BinaryTree tree(preorder);

    tree.print_preorder();
	cout << "\n";
    tree.print_postorder();
	cout << "\n";
    tree.print_inorder();
	cout << "\n";
    tree.print_level_order();
	cout << "\n";
}

int main() {
    test1();

	cout << "bye\n";

	return 0;
}


