#include<iostream>
using namespace std;

class LinkedList{
private:
    // the { } initializes object pointer to null.
    //TIP: Always Initialize

    struct Node{
        int data { };
        Node* next { }; // initialized with null

        Node(int data): data(data) {  }
    };

    Node *head { };
    Node *tail { };
    int length {0};

    void deleteNode(Node* target){
        --length;
        if(target == head)
            head = head->next;
        else if(target == tail)
            head = tail = nullptr;

        delete target;
    }
public:
    void insertEnd(const int &dataue){ // O(1)
        Node* item = new Node(dataue);

        if(!head)
            head = tail = item;
        else{
            tail->next = item;
            tail = item;
        }

        ++length;
    }

    void reverseChain(int k){
        if(!head)
            return;

        Node *first = head, *second = head->next;
        while(second && --k){
            Node *secondNext = second->next;

            second->next = head;
            first->next = secondNext;

            head = second;
            second = secondNext;
        }
        if(!first->next)
            tail = first;
    }

    void Print(){ // O(n)
        for(Node* cur{head}; cur; cur=cur->next){
            cout << cur->data << " ";
            if(cur == head)
                cout << "<-head ";
            if(cur == tail)
                cout << "<-tail\n";
        }
        cout << "==========================\n";
    }
};

void test1(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(3);
    list1.insertEnd(4);
    list1.insertEnd(5);
    list1.insertEnd(6);
    list1.insertEnd(7);

    list1.reverseChain(3);
    list1.Print(); //
}

void test2(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(2);

    list1.reverseChain(1);
    list1.Print(); //
}

void test3(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(3);
    list1.insertEnd(4);
    list1.insertEnd(5);

    list1.reverseChain(5);
    list1.Print(); //
}

int main(){
    test1();
    test2();
    test3();

    cout << "NO RTE";
    return 0;
}
