#include<iostream>
using namespace std;

struct Node{
    int data { };
    Node* next { }; // initialized with null

    Node(int data): data(data) {  }
};

class LinkedList{
private:
    // the { } initialize object pointer to null.
    //TIP: Always Initialize

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

    const Node* getNthBack(int index) const { // O(n)
        index = length - index;
        if(0 > index || index > length)
            return nullptr;

        Node* cur{ head };
        while(index--)
            cur = cur->next;

        return cur;
    }
};



int main(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);
    List.insertEnd(5);

    for(int i=0; i<10; i++){
        const Node* item = List.getNthBack(i);
        cout << i << "th = ";
        if(item)
            cout << item->data << "\n";
        else
            cout << " not found\n";
    }


    return 0;
}
