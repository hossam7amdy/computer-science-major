#include<iostream>
#include<assert.h>
#include<deque>
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
    BinarySearchTree(deque<type> &preorder, int st = 0, int en = -1){
        if(en == -1)
            en = (int)preorder.size() - 1;

        data = preorder[st];

        for(int split=st; split <= en+1; split++){
            if(preorder[split] > data){
                if(st+1 <= split-1)
                    left = new BinarySearchTree(preorder, st + 1, split - 1);
                if(split <= en)
                    right = new BinarySearchTree(preorder, split, en);
                break;
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
};


void test1() {
    // preorder: 50 20 15 45 35 60 70 73
    deque<int> dq;
    dq.push_back(50);
    dq.push_back(20);
    dq.push_back(15);
    dq.push_back(45);
    dq.push_back(35);
    dq.push_back(60);
    dq.push_back(70);
    dq.push_back(73);

    BinarySearchTree tree(dq);
	tree.print_inorder();
	cout << "\n";
	tree.print_preorder();
	cout << "\n";
	tree.print_postorder();
}

int main() {
    test1();
    //test2();

	cout << "\nbye\n";

	return 0;
}


