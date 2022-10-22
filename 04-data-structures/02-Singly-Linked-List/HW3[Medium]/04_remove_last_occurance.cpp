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

    void deleteFront(){ // O(1)
        if(!head)
            return;
        Node* target = head;
        head = head->next;
        delete target;
    }

    void deleteLastOccurance(const int &key){ // O(n)
        if(!head)
            return;

        Node* before{};
        bool found{ false };

        for(Node *prev{}, *cur{ head }; cur; prev = cur, cur = cur->next)
            if(cur->data == key)
                found = true, before = prev;

        // 3 cases [ not exist - exist but first - exist at middle ]
        if(found){
            if(!before) // first element
                deleteFront();
            else
                deleteNext(before);
        }
    }
};



int main(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);
    List.insertEnd(5);
    //List.insertEnd(1);
    List.insertEnd(7);
    //List.insertEnd(1);

    List.deleteLastOccurance(1);

    List.Print();


    return 0;
}
