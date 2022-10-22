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

    void moveToBack(const int &key){ // O(n)
        Node *prev{}, *cur { head };
        for(int i = 0; i < length - 1; ++i){ // length - 1 steps
            if(cur->data == key){
                Node* tar = cur;

                cur = cur->next; // move

                if(tar == head)
                    head = head->next;
                else
                    prev->next = tar->next; // connect

                tail->next = tar;
                tail = tail->next;
                tail->next = nullptr;
            }
            else
                prev = cur, cur = cur->next; // normal step
        }
    }
};



int main(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(1);
    List.insertEnd(5);
    List.insertEnd(1);
    List.insertEnd(7);
    List.insertEnd(1);

    List.moveToBack(1);

    List.Print();


    return 0;
}
