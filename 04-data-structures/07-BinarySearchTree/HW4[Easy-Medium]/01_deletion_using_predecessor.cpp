#include<iostream>
using namespace std;

class BinarySearchTree{
private:
    int data;
    BinarySearchTree* left{};
    BinarySearchTree* right{};

    BinarySearchTree* find_max(){
        if(right)
            right->find_max();
        return this;
    }
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
            if(!node->left && !node->right){ // leaf
                delete node;
                node = nullptr;
            }
            else if(!node->left && node->right)
                node->special_deletion(node->right);
            else if(node->left && !node->right)
                node->special_deletion(node->left);
            else{
                BinarySearchTree* mx = node->left->find_max();
                node->data = mx->data;
                node->left = delete_node(node->data, node->left); // new sub-problem
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
    BinarySearchTree tree(3);
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(5);
    tree.Insert(4);
    tree.Insert(6);

    tree.delete_value(5);
    tree.print_inorder();
}

int main(){
    test1();

    return 0;
}
