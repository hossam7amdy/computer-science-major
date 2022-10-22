#include<iostream>
using namespace std;

class BinarySearchTree{
private:
    int data;
    BinarySearchTree* left{};
    BinarySearchTree* right{};

    void special_deletion(BinarySearchTree* child){
        data = child->data;
        left = child->left;
        right = child->right;

        delete child;
    }
    BinarySearchTree* delete_node(const int& value, BinarySearchTree* node){
        if(!node) // not exist
            return nullptr;

        if(value < node->data)
            node->left = delete_node(value, node->left);
        else if(value > node->data)
            node-> right = delete_node(value, node->right);
        else{
            if(!node->left && !node->right){ // CASE 1: leaf
                delete node;
                node = nullptr;
            }
            else if(!node->left && node->right) // CASE 2: right only
                node->special_deletion(node->right);
            else if(node->left && !node->right) // CASE 2: left only
                node->special_deletion(node->left);
            else{ //CASE 3: 2 children

                // Get the minimum node AND its parent
                BinarySearchTree* parent = node;
                BinarySearchTree* child = node->right;

                while(child->left)
                    parent = child, child = child->left;

                node->data = child->data;

				// child->left must be null, but child->right might not be
				// we need to link parent to child->right
					// But link with parent->left? or parent->right?
				// Simply same as current parent-child relations
					// In details: 2 cases: either successor was directly node's right
					// Or it was deeper on chain of left nodes
                if(parent->right == child)
                    parent->right = child->right;
                else
                    parent->left = child->right;

                delete child;
            }
        }
        return node;
    }

    void Clear(){
        if(left)
            delete left, left = nullptr;
        if(right)
            delete right, right = nullptr;
    }

public:
    BinarySearchTree(const int& data):
        data(data){
    }
    ~BinarySearchTree(){
        //cout << "node " << data << " deleted at address " << this << "\n";
        Clear();
    }

    void Insert(const int& value){
        if(value < data){
            if(left)
                left->Insert(value);
            else
                left = new BinarySearchTree(value);
        }else if(value > data){
            if(right)
                right->Insert(value);
            else
                right = new BinarySearchTree(value);
        } // already exist
    }

    void delete_value(const int& value){
        if(value == this->data)
            return;
        delete_node(value, this);
    }

    void print_inorder(){
        if(left)
            left->print_inorder();

        cout << data << " ";

        if(right)
            right->print_inorder();
    }
};

void test1(){
    BinarySearchTree tree(5);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(2);
    tree.Insert(4);
    tree.Insert(7);
    tree.Insert(10);
    tree.Insert(1);
    tree.Insert(6);
    tree.Insert(9);


    for(int i=0; i<15; i++){
        tree.delete_value(i);
        tree.print_inorder();
        cout << "\n";
    }
}

int main(){
    test1();

    cout << "bye\n";

    return 0;
}
