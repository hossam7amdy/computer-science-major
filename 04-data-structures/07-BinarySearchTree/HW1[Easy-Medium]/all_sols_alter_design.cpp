#include<iostream>
#include<assert.h>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

template<class type>
class BST{
private:
    struct BinaryNode{
        type data{};
        BinaryNode* left{};
        BinaryNode* right{};

        BinaryNode(const type &data):
            data(data){
        }
        BinaryNode(const type &data, BinaryNode* left, BinaryNode* right):
            data(data), left(left), right(right){
        }
    };

    BinaryNode* root{};

    BinaryNode* insert_item(BinaryNode* node, const type &item){
        if(!node)
            return new BinaryNode(item);

        if(node->data > item)
            node->left = insert_item(node->left, item);
        else if(node->data < item)
            node->right = insert_item(node->right, item);
        return node;
    }

    void inorder_traversal(BinaryNode* node) const {
        if(!node)
            return;

        inorder_traversal(node->left);
        cout << node->data << " ";
        inorder_traversal(node->right);
    }

    bool is_bst(BinaryNode* node) const {
        if(!node)
            return true;

        bool bst = !node->left || node->data > node->left->data;
        return bst && is_bst(node->left);

        bst = !node->right || node->data < node->right->data;
        return bst && is_bst(node->right);
    }

    BinaryNode* arrayToBalancedBST(const vector<type> &sorted, int st = 0, int en = -5){
        if(en == -5)
            en = (int)sorted.size() - 1;
        if(st > en)
            return nullptr;

        int mid{ (st + en) / 2 };
        BinaryNode* left = arrayToBalancedBST(sorted, st, mid-1);
        BinaryNode* right = arrayToBalancedBST(sorted, mid+1, en);
        BinaryNode* root = new BinaryNode(sorted[mid], left, right);

        return root;
    }

    void free(BinaryNode* node){
        if(!node)
            return;

        free(node->left);
        free(node->right);

        //cout << "Node " << node->data << " deleted at address " << node << endl;
        delete node;
        node = nullptr;
    }

    type kthInorder(BinaryNode* node, int &k){
        if(k == 0)
            return -1234;

        if(node->left){
            int res = kthInorder(node->left, k);
            if(k == 0)
                return res;
        }

        --k;
        if(k == 0)
            return node->data;

        if(node->right)
            return kthInorder(node->right, k);

        return -1234;
    }

    type lca(const type &x, const type &y, BinaryNode* node){
        if(node->data > x && node->data > y)
            return lca(x, y, node->left);

        if(node->data < x && node->data < y)
            return lca(x, y, node->right);

        return node->data;
    }
public:
    BST(){
    }
    BST(const type &data):
        root( new BinaryNode(data) ){
    }

    void add(const vector<type> &data, const string &direction){
        assert((int)data.size() == (int)direction.size());
        BinaryNode* current = root;

        for(int i=0; i<(int)data.size(); i++){
            if(direction[i] == 'L'){
                if(!current->left)
                    current->left = new BinaryNode(data[i]);
                else
                    assert(current->left->data == data[i]);
                current = current->left;
            }else{
                if(!current->right)
                    current->right = new BinaryNode(data[i]);
                else
                    assert(current->right->data == data[i]);
                current = current->right;
            }
        }
    }

    void insertItem(const type &item){
        if(!root)
            root = new BinaryNode(item);
        root = insert_item(root, item);
    }

    void inorderTraversal() const {
        inorder_traversal(root);
        cout << "\n";
    }


    ~BST(){
        free(root);
    }

    /// p1
    bool isExistsIter(const type &key) const {
        BinaryNode* cur = root;

        while(cur){
            if(cur->data > key)
                cur = cur->left;
            else if(cur->data < key)
                cur = cur->right;
            else
                return cur->data == key;
        }
        return false;
    }
    /// p2
    bool isBST() const {
        return is_bst(root);
    }
    /// p3
    BST(const vector<type> &sorted){
        root = arrayToBalancedBST(sorted);
    }
    /// p4
    type kthSmallest(int kth){
        return kthInorder(root, kth);
    }
    /// p5
    type lowestCommAnc(const type &x, const type &y){
        return lca(x, y, root);
    }
};

void p1() {
	BST<int> tree(50);
	tree.insertItem(20);
	tree.insertItem(45);
	tree.insertItem(35);
	tree.insertItem(70);
	tree.insertItem(73);
	tree.insertItem(74);
	tree.insertItem(10);

	//tree.inorderTraversal();
	cout << tree.isExistsIter(50) << endl;
	cout << tree.isExistsIter(9) << endl;
	cout << tree.isExistsIter(10) << endl;
	cout << tree.isExistsIter(70) << endl;
	cout << tree.isExistsIter(74) << endl;
	cout << tree.isExistsIter(75) << endl;
}

void p2() {
	BST<int> tree(1);
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

	cout<<"\n"<<tree.isBST()<<endl;
	tree.inorderTraversal();

    BST<int> tree1(1);

	tree1.insertItem(2);
	tree1.insertItem(3);


	tree1.insertItem(4);
	tree1.insertItem(8);
	tree1.insertItem(9);
	tree1.insertItem(15);


	tree1.insertItem(13);
	tree1.insertItem(12);
	tree1.insertItem(14);
	tree1.insertItem(16);

	cout << tree1.isBST() << endl;
	tree1.inorderTraversal();
}

void p3() {
	BST<int> tree({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12 });

	tree.inorderTraversal();

	assert(tree.isBST());

}

void p4() {
	BST<int> tree(50);
    tree.insertItem(20);
	tree.insertItem(60);
	tree.insertItem(15);
	tree.insertItem(45);
	tree.insertItem(70);
	tree.insertItem(35);
	tree.insertItem(73);

	tree.insertItem(14);
	tree.insertItem(16);
	tree.insertItem(36);
	tree.insertItem(58);

    tree.inorderTraversal();

	for(int i = 1; i < 5; ++i)
        cout << tree.kthSmallest(i) << " ";

}

void p5() {
	BST<int> tree(50);

    tree.insertItem(20);
	tree.insertItem(60);
	tree.insertItem(15);
	tree.insertItem(45);
	tree.insertItem(70);
	tree.insertItem(35);
	tree.insertItem(73);

	tree.insertItem(14);
	tree.insertItem(16);
	tree.insertItem(36);
	tree.insertItem(58);

    tree.inorderTraversal();

	cout << tree.lowestCommAnc(16, 45) << "\n";
	cout << tree.lowestCommAnc(15, 70) << "\n";
	cout << tree.lowestCommAnc(35, 60) << "\n";
	cout << tree.lowestCommAnc(14, 16) << "\n";
	cout << tree.lowestCommAnc(70, 73) << "\n";
	cout << tree.lowestCommAnc(45, 36) << "\n";
}


int main() {
    //p1();
    //p2();
    //p3();
    //p4();
    p5();


    cout << "bye\n";
	return 0;
}



