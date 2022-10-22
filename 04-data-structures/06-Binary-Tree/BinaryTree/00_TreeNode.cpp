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
};

int main(){

    return 0;
}
