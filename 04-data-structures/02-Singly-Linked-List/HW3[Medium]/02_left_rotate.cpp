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
    Node* getNth(int index){ // O(n)
        return getNthBack(length - index + 1);
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

    void leftRotate(int k){
        k %= length; // remove useless cycles

        if(k <= 0) return;

        Node* new_tail{ getNth(k) };

        // cycle
        tail->next = head;
        head = new_tail->next;

        // break cycle
        tail = new_tail;
        tail->next = nullptr;
    }

};

void test1(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);

    List.leftRotate(1);
    List.Print();
}

void test2(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);

    List.leftRotate(2);
    List.Print();
}

void test3(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);

    List.leftRotate(3);
    List.Print();
}

void test4(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);

    List.leftRotate(4);
    List.Print();
}

void test5(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);

    List.leftRotate(5);
    List.Print();
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
