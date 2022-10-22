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

    Node* getNthBack(int index) { // O(n)
        index = length - index;
        if(0 > index || index > length)
            return nullptr;

        Node* cur{ head };
        while(index--)
            cur = cur->next;

        return cur;
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
        cout << "\n";
    }

    ~LinkedList(){ // O(n)
        while(head){
            Node* cur = head;
            head = head->next;

            delete cur;
        }
        cout << "\n\nBye\n";
    }

    void swapHeadTail(){ // O(n)
        Node* temp { getNthBack(2) };
        if(!temp)
            return;

        temp->next = head;
        tail->next = head->next;

        swap(head, tail);
        tail->next = nullptr;
    }
};



int main(){
    LinkedList List;
    List.insertEnd(1);
    List.swapHeadTail();
    List.Print();

    List.insertEnd(2);
    List.swapHeadTail();
    List.Print();

    List.insertEnd(3);
    List.swapHeadTail();
    List.Print();

    List.insertEnd(4);
    List.swapHeadTail();
    List.Print();

    List.insertEnd(5);
    List.swapHeadTail();
    List.Print();

    List.insertEnd(6);
    List.swapHeadTail();
    List.Print();

    List.insertEnd(7);
    List.swapHeadTail();
    List.Print();

    List.insertEnd(8);
    List.swapHeadTail();
    List.Print();


    return 0;
}
