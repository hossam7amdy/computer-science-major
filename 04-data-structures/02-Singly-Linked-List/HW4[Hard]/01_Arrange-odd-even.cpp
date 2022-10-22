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

    void arrangeOddEven(){
        if(length <= 2)
            return;

        Node *cur_odd = head, *first_even = head->next;
        while(cur_odd->next && cur_odd->next->next){
            Node* cur_even = cur_odd->next;
            // connect odd with odd and even with even
            cur_odd->next = cur_odd->next->next;
            cur_even->next = cur_even->next->next;
            cur_odd = cur_odd->next;

            // utilize tail on the go
            tail = cur_even;
        }
        cur_odd->next = first_even;
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
    LinkedList List;
    List.insertEnd(10);
    List.insertEnd(20);
    List.insertEnd(3);
    List.insertEnd(7);
    List.insertEnd(15);
    List.arrangeOddEven();
    List.Print();
}

void test2(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);
    List.insertEnd(5);
    List.arrangeOddEven();
    List.Print();
}

void test3(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.arrangeOddEven();
    List.Print();
}

void test4(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);
    List.insertEnd(5);
    List.insertEnd(6);
    List.insertEnd(7);
    List.arrangeOddEven();
    List.Print();
}

void test5(){
    LinkedList List;
    List.insertEnd(11);
    List.insertEnd(33);
    List.insertEnd(55);
    List.insertEnd(4);
    List.insertEnd(50);
    List.insertEnd(17);
    List.insertEnd(8);
    List.arrangeOddEven();
    List.Print();
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
