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

    void insertAlternate(const LinkedList &another){
        // nothing to do
        if(another.length == 0)
            return;
        // mine is empty
        if(!length){
            head = another.head;
            tail = another.tail;
            length = another.length;
            return;
        }
        // do alternating process
        Node *h1 = head, *h2 = another.head;
        while(h1 && h2){
            Node *cur1 = h1, *cur2 = h2;
            // mine done
            if(!h1->next){
                h1->next = h2;
                break;
            }
            // move
            h1 = h1->next;
            h2 = h2->next;
            // insert
            cur1->next = cur2;
            cur2->next = h1;
        }
        if(length <= another.length)
            tail = another.tail;
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

    LinkedList list2;
    list2.insertEnd(4);
    list2.insertEnd(5);
    list2.insertEnd(6);

    list1.insertAlternate(list2);
    list1.Print();
}

void test2(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(3);

    LinkedList list2;
    list2.insertEnd(4);

    list1.insertAlternate(list2);
    list1.Print();
}

void test3(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(3);

    LinkedList list2;
    list2.insertEnd(4);
    list2.insertEnd(5);
    list2.insertEnd(6);
    list2.insertEnd(7);
    list2.insertEnd(8);

    list1.insertAlternate(list2);
    list1.Print();
}

void test4(){
    LinkedList list1;

    LinkedList list2;
    list2.insertEnd(1);
    list2.insertEnd(2);
    list2.insertEnd(3);

    list1.insertAlternate(list2);
    list1.Print();
}

int main(){
    test1();
    test2();
    test3();
    test4();

    cout << "NO RTE";
    return 0;
}
