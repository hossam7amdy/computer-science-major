#include<iostream>
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

	bool Search(const int& val){
	    if(val == data)
            return true;

        if(val<data)
            return left && left->Search(val);

	    return right && right->Search(val);
	}

};


void test1() {
	BinarySearchTree tree(50);
	tree.Insert(20);
	tree.Insert(45);
	tree.Insert(35);
	tree.Insert(70);
	tree.Insert(73);
	tree.Insert(74);
	tree.Insert(10);

	cout <<tree.subtree_min_value()<<endl;
	cout <<tree.subtree_max_value()<<endl;
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

int main() {
    test1();
    //test2();

	cout << "\nbye\n";

	return 0;
}


