#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

typedef int type;
class BinarySearchTree{
private:
    type data{ };
    BinarySearchTree* left{ };
    BinarySearchTree* right{ };

public:
    BinarySearchTree(const type &data):
        data(data){
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
};


void test1() {
	BinarySearchTree tree(1);
	tree.Insert(20);
	tree.Insert(45);
	tree.Insert(35);
	tree.Insert(70);
	tree.Insert(73);
	tree.Insert(74);
	tree.Insert(10);

	cout<<"\n"<<tree.isBST2()<<endl;
	tree.print_inorder();
}

void test2() {
	BinarySearchTree tree(1);

	tree.Insert(2);
	tree.Insert(3);


	tree.Insert(4);
	tree.Insert(8);
	tree.Insert(9);
	tree.Insert(15);


	tree.Insert(13);
	tree.Insert(12);
	tree.Insert(14);
	tree.Insert(16);

	tree.print_inorder();
	cout << "\n";
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
    test1();
    //test2();
    test_is_BST();

	cout << "\nbye\n";

	return 0;
}


