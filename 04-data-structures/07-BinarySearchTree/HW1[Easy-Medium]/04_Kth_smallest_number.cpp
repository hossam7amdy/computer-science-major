#include<iostream>
#include<vector>
#include<queue>
#include<assert.h>
using namespace std;

typedef int type;
class BinarySearchTree{
private:
    type data{ };
    BinarySearchTree* left{ };
    BinarySearchTree* right{ };

public:
    BinarySearchTree(type data, BinarySearchTree* left = nullptr, BinarySearchTree* right = nullptr) :
			data(data), left(left), right(right) {
	}

    void add(const vector<type> &data, const vector<char> &direction){
        assert((int)data.size() == (int)direction.size());
        BinarySearchTree* current = this;

        for(int i=0; i<(int)data.size(); i++){
            if(direction[i] == 'L'){
                if(!current->left)
                    current->left = new BinarySearchTree(data[i]);
                else
                    assert(current->left->data == data[i]);
                current = current->left;
            }else{
                if(!current->right)
                    current->right = new BinarySearchTree(data[i]);
                else
                    assert(current->right->data == data[i]);
                current = current->right;
            }
        }
    }
    void Insert(const int& val){
        if(val<data){
            if(!left)
                left = new BinarySearchTree(val);
            else
                left->Insert(val);
        }
        else{
            if(!right)
                right = new BinarySearchTree(val);
            else
                right->Insert(val);
        }
	}

    void Clear() {
        if(left){
            delete left;
            left = nullptr;
        }
        if(right){
            delete right;
            right = nullptr;
        }
    }
    ~BinarySearchTree(){
        //cout << "Node " << data << " deleted at address " << this << "\n";
        Clear();
    }

    void print_inorder() {
		if (left)
			left->print_inorder();

		cout << data << " ";

		if (right)
			right->print_inorder();
	}
	void print_preorder() {
		cout << data << " ";
		if (left)
			left->print_preorder();
		if (right)
			right->print_preorder();
	}
    void print_postorder() {
		if (left)
			left->print_postorder();
		if (right)
			right->print_postorder();
        cout << data << " ";
	}
	void print_level_order(){
        queue<BinarySearchTree*> que;
        que.push(this);

        while(!que.empty()){
            BinarySearchTree* cur = que.front();
            que.pop();

            if(cur->left)
                que.push(cur->left);
            if(cur->right)
                que.push(cur->right);

            cout << cur->data << " ";
        }
	}

	bool Search(const int& target){
	    if(target == data)
            return true;

        if(target<data)
            return left && left->Search(target);

	    return right && right->Search(target);
	}
	bool Iterative_search(const int& target){
	    BinarySearchTree* cur = this;
	    while(cur){
            if(target>cur->data)
                cur = cur->right;
            else if(target<cur->data)
                cur = cur->left;
            else
                return true;
	    }
	    return false;
	}

	bool isBST(){
        bool BST = !left || left->data<data && left->isBST(); // short circuit

        if(!BST)
            return false; // no need to proceed

        BST = !right || right->data>data && right->isBST();

        return BST;
	}
	void get_inorder(vector<type> &res){
        if(left)
            left->get_inorder(res);
        res.push_back(data);
        if(right)
            right->get_inorder(res);
	}
	bool isBST2(){
	    vector<type> all_data;
	    get_inorder(all_data);

	    for(int i=1; i<(int)all_data.size(); i++)
            if(all_data[i]<all_data[i-1])
                return false;

        return true;
	}

	type get_Kth(int &kth){ // TODO
	}
};

BinarySearchTree* build_balanced_bst_tree(const vector<type> &v, int st=0, int en=-2){
    if(en==-2)
        en = (int)v.size()-1;
    if(st>en)
        return nullptr;

    int mid = (st + en) / 2;
    BinarySearchTree* left = build_balanced_bst_tree(v, st, mid-1);
    BinarySearchTree* right = build_balanced_bst_tree(v, mid+1, en);
    BinarySearchTree* root = new BinarySearchTree(v[mid], left, right);

    return root;
}

BinarySearchTree* GetTree() {
	BinarySearchTree* tree = new BinarySearchTree(50);
	tree->Insert(20);
	tree->Insert(60);
	tree->Insert(15);
	tree->Insert(45);
	tree->Insert(70);
	tree->Insert(35);
	tree->Insert(73);

	tree->Insert(14);
	tree->Insert(16);
	tree->Insert(36);
	tree->Insert(58);
	return tree;
}

void build_bst() {
	vector<int> values = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	BinarySearchTree* tree = build_balanced_bst_tree(values);
	values.clear();
	tree->get_inorder(values);
	assert(tree->isBST());

    tree->print_level_order();
}

void test_get_kth(){
    BinarySearchTree tree(20);
    tree.Insert(10);
    tree.Insert(15);
    tree.Insert(80);

    //cout<<tree.get_Kth(1)<<endl;
}

void test_is_BST() {
	BinarySearchTree tree(1);
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

	cout<<"\n"<<tree.isBST2()<<endl;
	tree.print_inorder();
}

int main() {
    //build_bst();
    test_get_kth();
	cout << "\nbye\n";

	return 0;
}


