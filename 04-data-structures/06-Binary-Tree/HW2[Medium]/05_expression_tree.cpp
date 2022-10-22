#include<iostream>
#include<vector>
#include<stack>
#include<assert.h>
using namespace std;



typedef char type;
class BinaryTree{
private:
    type data{ };
    BinaryTree* left{ };
    BinaryTree* right{ };

public:
    BinaryTree(const type &data):
        data(data){
    }
    BinaryTree(const string &postorder){
        stack<BinaryTree*> subTrees;

        for(int i = 0; i < (int)postorder.size(); ++i){
            BinaryTree *cur = new BinaryTree(postorder[i]);

            if(!isdigit(postorder[i])){
                cur->right = subTrees.top();
                subTrees.pop();
                cur->left = subTrees.top();
                subTrees.pop();
            }

            subTrees.push(cur);
        }

        BinaryTree *root = subTrees.top();
        subTrees.pop();

        this->data = root->data;
        this->left = root->left;
        this->right = root->right;
    }

    void print_postorder_expression() {
        if(left)
            left->print_postorder_expression();

        if(right)
            right->print_postorder_expression();

        cout << data;
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
};

void test1() {
	BinaryTree root("51+");

	cout << "postfix expression: ";
	root.print_postorder_expression();
	cout << "\n";
}

void test2() {
	BinaryTree root("51+2/");

	cout << "postfix expression: ";
	root.print_postorder_expression();
	cout << "\n";
}

void test3() {
	BinaryTree root("23+4*");

	cout << "postfix expression: ";
	root.print_postorder_expression();
	cout << "\n";
}


void test4() {
	BinaryTree root("534*2^+");

	cout << "postfix expression: ";
	root.print_postorder_expression();
	cout << "\n";
}

int main() {
	test1();
	test2();
	test3();
	test4();

	return 0;
}
