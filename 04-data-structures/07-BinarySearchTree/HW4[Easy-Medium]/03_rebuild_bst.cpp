#include<iostream>
#include<queue>
using namespace std;


class BinarySearchTree{
private:
    struct BinaryNode{
        int data;
        BinaryNode* left{};
        BinaryNode* right{};

        BinaryNode(const int& data):
            data(data){ }
    };

    void insert_node(const int& value, BinaryNode* node){
        if(value > node->data){
            if(!node->right)
                node->right = new BinaryNode(value);
            else
                insert_node(value, node->right);
        }else if(value < node->data){
            if(!node->left)
                node->left = new BinaryNode(value);
            else
                insert_node(value, node->left);
        }
    }

    bool find_node(const int& target, BinaryNode* node){
        if(!node)
            return false;
        if(target == node->data)
            return true;

        if(target > node->data)
            return find_node(target, node->right);
        return find_node(target, node->left);
    }

    BinaryNode* root{};
public:
    void insert_value(const int& value){
        if(!root)
            root = new BinaryNode(value);
        else
            insert_node(value, root);
    }

    void delete_value(const int& target){
    }

    bool Search(const int& target){
        if(find_node(target, root))
            return true;
        return false;
    }

    void print_inorder(){
    }

    void print_levelorder(){
        queue<BinaryNode*> que;
        que.push(root);

        while(!que.empty()){
            int sz = que.size();

            while(sz--){
                BinaryNode* cur = que.front();
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

void test1(){
    BinarySearchTree tree;
    tree.insert_value(5);
    tree.insert_value(3);
    tree.insert_value(8);
    tree.insert_value(2);
    tree.insert_value(4);
    tree.insert_value(7);
    tree.insert_value(10);
    tree.insert_value(1);
    tree.insert_value(6);
    tree.insert_value(9);

    tree.print_levelorder();
    cout << tree.Search(5) << "\n";
    cout << tree.Search(9) << "\n";
    cout << tree.Search(4) << "\n";
    cout << tree.Search(8) << "\n";
    cout << tree.Search(15) << "\n";


}

int main(){
    test1();


    cout << "\n";

    return 0;
}
