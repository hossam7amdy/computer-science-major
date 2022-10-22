#include<iostream>
#include<deque>
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
    BinarySearchTree(const type &data):
        data(data){
    }
    bool is_bst1() {
		bool left_bst = !left || data > left->data && left->is_bst1();
		bool right_bst = !right || data < right->data && right->is_bst1();
		return left_bst && right_bst;
	}
    BinarySearchTree(deque<type> &dq){

        data = dq.front();
        dq.pop_front();

        queue< pair<BinarySearchTree*, pair<int, int> >> que;
        que.push(make_pair(this, make_pair(0, 10001)));

        // level order: 50 20 60 15 45 70 35 73
        while(!que.empty()){
            int sz {(int)que.size()};

            while(sz--){
                BinarySearchTree* cur = que.front().first;
                int mn = que.front().second.first;
                int mx = que.front().second.second;

                int cur_data = cur->data;
                que.pop();

                if(mn < dq.front() && dq.front() < cur_data){
                    cur->left = new BinarySearchTree(dq.front());
                    que.push(make_pair(cur->left, make_pair(mn, cur_data)));
                    dq.pop_front();
                }

                if(cur_data < dq.front() && dq.front() < mx){
                    cur->right = new BinarySearchTree(dq.front());
                    que.push(make_pair(cur->right, make_pair(cur->data, mx)));
                    dq.pop_front();
                }

            }
        }
        assert(is_bst1());
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
	void print_levelorder(){
	    queue<BinarySearchTree*> que;
        que.push(this);

        while(!que.empty()){
            int sz = (int)que.size();

            while(sz--){
                BinarySearchTree* cur = que.front();
                que.pop();

                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);

                cout << cur->data << " ";
            }
        }
        cout << "\n";
	}

};


void test1() {
    // level order: 50 20 60 15 45 70 35 73
    deque<int> dq;

    dq.push_back(50);
    dq.push_back(20);
    dq.push_back(60);
    dq.push_back(15);
    dq.push_back(45);
    dq.push_back(70);
    dq.push_back(35);
    dq.push_back(73);

    BinarySearchTree tree(dq);
    tree.print_levelorder();
	tree.print_preorder();
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


