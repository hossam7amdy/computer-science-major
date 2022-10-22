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

    void deleteDuplicates() { // O(n)
        Node *prev = new Node(-123), *cur = head;
        int target = -123;
        while(cur){
            if(target == cur->data){
                Node* toDelete = cur;

                cur = cur->next;
                prev->next = cur;

                deleteNode(toDelete);
            }
            else if(cur->next && cur->data == cur->next->data)
                target = cur->data;
            else
                prev = cur, cur = cur->next;
        }
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
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(2);
    list1.insertEnd(2);
    list1.insertEnd(3);
    list1.insertEnd(5);

    list1.deleteDuplicates();
    list1.Print(); // 3 5
}

void test2(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(1);

    list1.deleteDuplicates();
    list1.Print(); // empty

    list1.insertEnd(2);
    list1.insertEnd(5);
    list1.Print();
}

void test3(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(2);
    list1.insertEnd(2);

    list1.deleteDuplicates();
    list1.Print(); // empty
}

void test4(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(2);
    list1.insertEnd(2);
    list1.insertEnd(5);

    list1.deleteDuplicates();
    list1.Print(); // 5
}

void test5(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(2);
    list1.insertEnd(2);
    list1.insertEnd(3);

    list1.deleteDuplicates();
    list1.Print(); // 1 3
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();

    cout << "NO RTE";
    return 0;
}
