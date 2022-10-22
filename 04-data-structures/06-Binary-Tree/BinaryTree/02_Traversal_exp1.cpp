#include<iostream>
using namespace std;

typedef char type;
struct TreeNode{
    type data;
    TreeNode *right{ };
    TreeNode *left{ };

    TreeNode(const int &data):
        data(data){
    }
    ~TreeNode(){
        cout << "Node " << data << " deleted with address " << this << "\n";
    }
};

void prefix_traversal(const TreeNode* const current) {
    if(!current)
        return;

    cout << current->data << " ";
    prefix_traversal(current->left);
    prefix_traversal(current->right);
}

void Infix_traversal(const TreeNode* const current) {
    if(!current)
        return;

    Infix_traversal(current->left);
    cout << current->data << " ";
    Infix_traversal(current->right);
}

void postfix_traversal(const TreeNode* const current) {
    if(!current)
        return;

    postfix_traversal(current->left);
    postfix_traversal(current->right);
    cout << current->data << " ";
}

void free_nodes(TreeNode* node){
    if(!node)
        return;

    free_nodes(node->right);
    free_nodes(node->left);
    delete node;
    node = nullptr;
}

int main(){
     // Create Nodes
	TreeNode* Plus = new TreeNode('+');
	TreeNode* node1 = new TreeNode('1');
	TreeNode* node2 = new TreeNode('2');

	// Link them!
	Plus->left = node1;
	Plus->right = node2;

	prefix_traversal(Plus);
	cout << "\n";

    Infix_traversal(Plus);
	cout << "\n";

    postfix_traversal(Plus);
	cout << "\n***********\n";

	//free_nodes(Plus); // RTE

	/// Became: (1 + 2) * 4
	// Build/connect root to + *
	TreeNode* Multiply = new TreeNode('*');
	TreeNode* node3 = new TreeNode('4');
	Multiply->left = Plus;
	Multiply->right = node3;

	prefix_traversal(Multiply);
	cout << "\n";

    Infix_traversal(Multiply);
	cout << "\n";

    postfix_traversal(Multiply);
	cout << "\n***********\n";

	free_nodes(Multiply);

    /// (2 + 3) * (9 - 8 / 4)
	TreeNode* plus = new TreeNode('+');
	plus->left = new TreeNode('2');
	plus->right = new TreeNode('3');

	TreeNode* div = new TreeNode('/');
	div->left = new TreeNode('8');
	div->right = new TreeNode('4');

	TreeNode* minus = new TreeNode('-');
	minus->left = new TreeNode('9');
	minus->right = div;

	TreeNode* multiply = new TreeNode('*');
	multiply->left = plus;
	multiply->right = minus;

	prefix_traversal(multiply);
	cout << "\n";

    Infix_traversal(multiply);
	cout << "\n";

    postfix_traversal(multiply);
	cout << "\n***********\n";

	free_nodes(multiply);

    return 0;
}
