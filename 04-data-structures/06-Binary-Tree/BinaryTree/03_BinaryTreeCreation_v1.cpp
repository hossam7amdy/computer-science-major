#include<iostream>
#include<queue>
using namespace std;



typedef int type;
class BinaryTree{
private:
    struct Node {
        type data{ };
        Node *right { };
        Node *left { };

        Node(const int &data) :
                data(data) {
        }
        ~Node() {
            cout << "Node " << data << " deleted with address " << this << "\n";
        }
    };

    Node *root{ };

    void preOrder_traversal(const Node *const current) {
        if (!current)
            return;

        cout << current->data << " ";
        preOrder_traversal(current->left);
        preOrder_traversal(current->right);
    }
    void InOrder_traversal(const Node *const current) {
        if (!current)
            return;

        InOrder_traversal(current->left);
        cout << current->data << " ";
        InOrder_traversal(current->right);
    }
    void postOrder_traversal(const Node *const current) {
        if (!current)
            return;

        postOrder_traversal(current->left);
        postOrder_traversal(current->right);
        cout << current->data << " ";
    }
    void add_node(Node *node){
        queue<Node*> que;
        que.push(root);

        while(!que.empty()){
            Node* top = que.front();
            que.pop();

            if(!top->left){
                top->left = node;
                return;
            }
            else if(!top->right){
                top->right = node;
                return;
            }
            else{
                que.push(top->left);
                que.push(top->right);
            }
        }
    }
    void free_nodes(Node *current) {
        if (!current)
            return;

        free_nodes(current->right);
        free_nodes(current->left);
        delete current;
        current = nullptr;
    }
public:
    void add(const type &data){
        Node *node = new Node(data);
        if(!root)
            root = node;
        else
            add_node(node);
    }
    void print_inOrder(){
        InOrder_traversal(root);
        cout << "\n";
    }
    void print_preOrder(){
        preOrder_traversal(root);
        cout << "\n";
    }
    void print_postOrder(){
        postOrder_traversal(root);
        cout << "\n";
    }
    ~BinaryTree() {
        free_nodes(root);
        root = nullptr;
    }
};


int main() {
    BinaryTree bt;
    bt.add(1);
    bt.add(2);
    bt.add(3);
    bt.add(4);
    bt.add(5);
    bt.add(6);

    bt.print_inOrder();
    bt.print_postOrder();
    bt.print_preOrder();

	return 0;
}
