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
    void Print(){
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    void insert_end(int value){
        Node* item = new Node(value);

        if(!head)
            head = tail = item;
        else{
            tail->next = item;
            tail = item;
        }
        length++;
    }
    Node* get_nth(int idx){
        idx--; // zero-based
        Node* nth_node = head;
        if(0<=idx && idx<=length){
            while(idx--)
                nth_node = nth_node->next;

            return nth_node;
        }

        return nullptr;
    }
    int Search(int value){
        int idx = 0;
        for(Node* curr = head; curr; curr = curr->next, idx++)
            if(curr->data == value)
                return idx;

        return -1;
    }
    int Improved_search(int value){
        int idx = 0;
        for(Node* curr=head, *prev=nullptr; curr; prev=curr, curr=curr->next){ // observe the order [FIRST prev=curr THEN curr=curr->next]
            if(curr->data == value){
                if(!prev)
                    return idx;

                swap(prev->data, curr->data);
                return idx-1;
            }
            ++idx;
        }

        return -1;
    }

    void f() { // RTE
        int cnt = 0;
        while(head) {
            ++cnt;
            cout<<cnt<<flush<<"\n";
            head->data += head->next->next->next->data;
            head = head->next;
        }
    }
};



int main(){
    LinkedList List;
    List.insert_end(1);
    List.insert_end(2);
    List.insert_end(3);
    List.insert_end(4);
    List.insert_end(5);
    List.insert_end(6);
    List.insert_end(7);
    List.insert_end(8);
    List.Print();
    // List.f();



    return 0;
}
