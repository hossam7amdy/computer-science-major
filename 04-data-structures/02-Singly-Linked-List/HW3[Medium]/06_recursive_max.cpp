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

    int listMax(Node* node = nullptr, int first_call = true){ // O(n) time && space
        if(first_call)
            node = head;
        if(!node)
            return INT_MIN;

        return max(node->data, listMax(node->next, false));
    }
};



int main(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(20);
    List.insertEnd(3);
    List.insertEnd(4);
    List.insertEnd(15);
    List.insertEnd(6);
    List.insertEnd(7);
    List.insertEnd(89);

    cout << List.listMax() << endl;


    return 0;
}
