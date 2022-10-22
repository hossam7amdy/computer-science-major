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
        ~Node(){
            cout << "node " << data << " deleted, address " << this << endl;
        }
    };

    Node *head { };
    Node *tail { };
    int length {0};
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
                cout << "<-tail\n";
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

    void deleteFront(){ // O(1)
        if(!head)
            return;
        Node* target = head;
        head = head->next;
        delete target;
    }
};



int main(){
    LinkedList List;

    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);
    List.insertEnd(5);
    List.insertEnd(6);

    List.deleteFront();

    List.insertEnd(7);
    List.insertEnd(8);

    List.Print();


    return 0;
}
