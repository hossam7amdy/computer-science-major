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
            cout << data << " deleted at address " << this << "\n";
        }
    };

    Node *head {};

    void printReversed(const Node* item){
        if(!item)
            return;

        printReversed(item->next);
        cout << item->data << " ";
    }

public:
    void addItem(const int &value){ // O(1)
        Node* item = new Node(value);

        if(!head)
            head = item;
        else{
            item->next = head;
            head = item;
        }
    }

    void Print(){ // O(n)
        printReversed(head);
        cout << "\n";
    }

    const Node* getTail() const { // O(1)
        if(!head)
            return nullptr;

        return head;
    }

    ~LinkedList(){ // O(n)
        while(head){
            Node* cur = head;
            head = head->next;

            delete cur;
        }
        cout << "\n\nBye\n";
    }
};



int main(){
    LinkedList List;
    List.addItem(1);
    List.addItem(2);
    List.addItem(3);
    List.addItem(4);

    cout << List.getTail()->data << endl; // private

    List.addItem(5);
    List.addItem(6);
    List.addItem(7);
    List.addItem(8);
    List.Print();


    return 0;
}
