#include<iostream>
using namespace std;

// Create Node
struct Node{
    int data { };
    Node* next { };

    Node(int data): data(data) {  }
};

// Display Nodes
void print1(Node* head){
    while(head!=nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
void print2(Node* head){
    if(head == nullptr){
        cout << "\n";
        return;
    }

    cout << head->data << " ";
    print2(head->next);
}
void print3(Node* head){
    for(Node* h = head; h!=nullptr; h = h->next)
        cout << h->data << " ";
    cout << "\n";
}

// Find a Node !
Node* Find(Node* node, int value){
    for(Node* h = node; h!=nullptr; h = h->next){
        if(h->data == value)
            return h;
    }
    return nullptr;
}

int main(){

    Node * n1 = new Node(10);
    Node * n2 = new Node(20);
    Node * n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    cout << n1->next->next->data << "\n";
    cout << n2->next->data << "\n";
    cout << n3->data << "\n";

    print1(n1);
    print2(n1);
    print3(n1);

    cout << Find(n2, 10) << "\n";


    return 0;
}
