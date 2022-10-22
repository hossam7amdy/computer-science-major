#include<iostream>
#include<vector>
#include<cmath>
#include<assert.h>
using namespace std;

template<class type>
class BinaryTree{
private:
    struct TreeNode{
        type data;
        TreeNode* left{};
        TreeNode* right{};

        TreeNode(const type &data): data(data){
        }
    };

    TreeNode* root{};

    int tree_max(TreeNode* node) const {
        if(!node)
            return INT_MIN;

        int left_max = max(node->data, tree_max(node->left));
        return max(left_max, tree_max(node->right));
    }

    int tree_height(TreeNode* node) const {
        if(!node)
            return 0;

        int left_hight = 1 + tree_height(node->left);
        return max(left_hight, 1 + tree_height(node->right));
    }

    int count_nodes(TreeNode* node) const {
        if(!node)
            return 0;

        int left_count = 1 + count_nodes(node->left);
        return left_count += count_nodes(node->right);
    }

    int count_leaves(TreeNode* node) const {
        if(!node)
            return 0;
        if(!node->left && !node->right)
            return 1;
        return count_leaves(node->left) + count_leaves(node->right);
    }

    bool is_exists(TreeNode* node, const type &value) const {
        if(!node)
            return false;
        if(node->data == value)
            return true;

        bool search_left = is_exists(node->left, value);
        return search_left || is_exists(node->right, value);
    }

    bool is_perfect(TreeNode* node) const {
        if(!node)
            return false;
        if(!node->left && !node->right)
            return true;

        return is_perfect(node->left) && is_perfect(node->right) && tree_height(node->left) == tree_height(node->right);
    }

public:
    BinaryTree(const type &data):
        root( new TreeNode(data) ){
    }

    void add(const string &direction, const vector<type> &data){
        assert(direction.length() == (int)data.size());

        TreeNode* node{ root };
        for(int i=0; i<(int)data.size(); ++i){
            if(direction[i] == 'L'){
                if(!node->left)
                    node->left = new TreeNode(data[i]);
                node = node->left;
            }
            else if(direction[i] == 'R'){
                if(!node->right)
                    node->right = new TreeNode(data[i]);
                node = node->right;
            }
            else
                assert(false);
        }
    }

    int treeMax() const {
        return tree_max(root);
    }

    int treeHeight() const {
        if(!root)
            return 0;

        int left_height = tree_height(root->left);
        return max(left_height, tree_height(root->right));
    }

    int totalNodes() const {
        return count_nodes(root);
    }

    int totalLeaves() const {
        return count_leaves(root);
    }

     bool isExists(const type &value) const {
         return is_exists(root, value);
     }

     bool isPerfect() const {
        return is_perfect(root);
     }

     bool isPerfect2() const {
        int h{ treeHeight() };
        int n{ totalNodes() };

        return pow(2, h + 1) == n + 1;
     }
};

void test1_numbers() {
    BinaryTree<int> tree(1);
	tree.add({'L','L','L'}, { 2, 4, 7 });
	tree.add({'L','L','R'}, { 2, 4, 8 });
	tree.add({'L','R','R'}, { 2, 5, 9 });
	tree.add({'R','R','L'}, { 3, 6, 15});

	assert(tree.treeMax() == 15);
	assert(tree.treeHeight() == 3);
	assert(tree.totalNodes() == 10);
	assert(tree.totalLeaves() == 4);

	assert(tree.isExists(1));
	assert(tree.isExists(15));
	assert(tree.isExists(4));
	assert(!tree.isExists(61));
}

void test2_is_perfect() {
	BinaryTree<int> tree(1);

	assert(tree.isPerfect() == 1);
	assert(tree.isPerfect2() == 1);

	tree.add("L", { 2 });
	tree.add("R", { 3 });

	assert(tree.isPerfect() == 1);
	assert(tree.isPerfect2() == 1);

	tree.add("LLL", { 2, 4, 7 });
	tree.add("LLR", { 2, 4, 8 });
	tree.add("LRR", { 2, 5, 9 });
	tree.add("RRL", { 3, 6, 15 });

	assert(tree.isPerfect() == 0);
	assert(tree.isPerfect2() == 0);

	tree.add("LRL", { 2, 5, 13 });
	tree.add("RRR", { 3, 6, 12 });
	tree.add("RLL", { 3, 14, 15 });
	tree.add("RLR", { 3, 14, 16 });

	assert(tree.isPerfect() == 1);	// now 8 leaf nodes
    assert(tree.isPerfect2() == 1);
}

int main(){
	test1_numbers();
	test2_is_perfect();

	cout << "bye\n";
    return 0;
}
