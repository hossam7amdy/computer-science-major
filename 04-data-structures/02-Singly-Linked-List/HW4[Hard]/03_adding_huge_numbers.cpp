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

    void addTwoNumbers(const LinkedList &another) {
        if(!another.length) // nothing to do
            return;

        // do processing
        Node *l1 = head, *l2 = another.head;
        int carry = 0, sum = 0;
        while(l1 || l2){
            sum = carry;
            if(l1)
                sum += l1->data;
            if(l2)
                sum += l2->data, l2 = l2->next;

            carry = sum > 9;
            if(carry)
                sum -= 10;

            if(l1)
                l1->data = sum, l1 = l1->next;
            else
                insertEnd(sum);

        }
        if(carry)
            insertEnd(carry);
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
    list2.insertEnd(3);

    list1.addTwoNumbers(list2);
    list1.Print(); // 5 7 6
}

void test2(){
    LinkedList list1;
    list1.insertEnd(9);
    list1.insertEnd(6);
    list1.insertEnd(5);

    LinkedList list2;
    list2.insertEnd(8);
    list2.insertEnd(7);
    list2.insertEnd(6);
    list2.insertEnd(4);
    list2.insertEnd(5);
    list2.insertEnd(7);
    list2.insertEnd(8);
    list2.insertEnd(9);

    list1.addTwoNumbers(list2);
    list1.Print(); // 7 4 2 5 5 7 8 9
}

void test3(){
    LinkedList list1;
    list1.insertEnd(1);
    list1.insertEnd(7);
    list1.insertEnd(9);

    LinkedList list2;
    list2.insertEnd(2);
    list2.insertEnd(5);
    list2.insertEnd(1);

    list1.addTwoNumbers(list2);
    list1.Print(); // 3 2 1 1
}

void test4(){
    LinkedList list1;
    list1.insertEnd(5);

    LinkedList list2;
    list2.insertEnd(1);
    list2.insertEnd(2);
    list2.insertEnd(3);

    list1.addTwoNumbers(list2);
    list1.Print(); // 6 2 3
}

int main(){
    test1();
    test2();
    test3();
    test4();

    cout << "NO RTE";
    return 0;
}
