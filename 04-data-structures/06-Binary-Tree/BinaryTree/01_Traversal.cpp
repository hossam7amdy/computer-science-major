#include<iostream>
using namespace std;

typedef int type;
struct TreeNode{
    type data;
    TreeNode *right{ };
    TreeNode *left{ };

    TreeNode(const int &data):
        data(data){
    }
};

void traverse(const TreeNode* const root) {
    if(!root)
        return;
    else
        cout << root->data << " ";

    traverse(root->right);
    traverse(root->left);
}

int main(){
    // Create Nodes
	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);

	// Link them!
	root->left = node2;
	root->right = node3;

	node2->left = node4;
	node2->right = node5;

	node5->right = node7;

	node3->right = node6;

	node6->left = node8;

	traverse(root);

    return 0;
}
