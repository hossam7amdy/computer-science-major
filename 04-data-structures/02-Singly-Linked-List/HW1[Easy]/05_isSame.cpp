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

    bool isSame(const LinkedList &other){ // O(n)
        Node *l1{ other.head }, *l2 { head };

        while(l1 && l2){
            if(l1->data != l2->data)
                return false;
            l1 = l1->next, l2 = l2->next;
        }
        return !l1 && !l2;
    }

    bool isSame_v2(const LinkedList &other){ //
        int length2{ other.length };

        if(length != length2)
            return false;

        return isSame(other);
    }
};



int main(){
    LinkedList List1, List2;
    List1.insertEnd(1);
    List1.insertEnd(2);
    List1.insertEnd(3);
    List2.insertEnd(1);
    List2.insertEnd(2);
    List2.insertEnd(3);

    cout << List1.isSame_v2(List2) << endl;

    List1.insertEnd(7);
    List2.insertEnd(7);

    cout << List1.isSame_v2(List2) << endl;

    //List1.insertEnd(8);


    return 0;
}
