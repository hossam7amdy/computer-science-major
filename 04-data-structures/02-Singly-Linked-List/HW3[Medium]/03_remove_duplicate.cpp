#include<iostream>
using namespace std;

class LinkedList{
private:
    // the { } initialize object pointer to null.
    //TIP: Always Initialize

    struct Node{
        int data { };
        Node* next { }; // initialized with null

        Node(int data): data(data) {  }
    };

    Node *head { };
    Node *tail { };
    int length {0};

    void deleteNode(Node* node){
        --length;
        delete node;
    }

    void deleteNext(Node* prev){
        if(prev == tail) return;
        // hold next
        Node* tar { prev->next };

        // connect prev with next and delete target
        prev->next = tar->next;
        deleteNode(tar);

        if(!prev->next)
            tail = prev, tail->next = nullptr;
    }

public:
    void insertEnd(const int &value){ // O(1)
        Node* item = new Node(value);

        if(!head)
            head = tail = item;
        else{
            tail->next = item;
            tail = item;
        }

        ++length;
    }

    void Print(){ // O(n)
        for(Node* cur{head}; cur; cur=cur->next){
            cout << cur->data << " ";
            if(cur == head)
                cout << "<-head ";
            if(cur == tail)
                cout << "<-tail";
        }
    }

    ~LinkedList(){ // O(n)
        while(head){
            Node* cur = head;
            head = head->next;

            delete cur;
        }
        cout << "\n\nBye\n";
    }

    void removeDuplicates(){ // O(n^2)
        if(!length)
            return;

        for(Node* cur1{ head }; cur1; cur1 = cur1->next){
            for(Node *prev{ cur1 }, *cur2{ cur1->next }; cur2;){
                if(cur1->data == cur2->data){
                    cur2 = cur2->next;
                    deleteNext(prev);
                }
                else
                    prev = cur2, cur2 = cur2->next;
            }
        }
    }
};

void test1(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);

    List.removeDuplicates();

    List.Print();
}

void test2(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(1);
    List.insertEnd(1);

    List.removeDuplicates();

    List.Print();
}

void test3(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);

    List.removeDuplicates();

    List.Print();
}

int main(){
    test1();
    test2();
    test3();

    return 0;
}
