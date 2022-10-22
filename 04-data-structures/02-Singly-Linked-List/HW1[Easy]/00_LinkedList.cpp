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

    int Search(const int &key){ // O(n)

        int idx{};

        for(Node *prev{}, *cur{ head }; cur; prev=cur, cur=cur->next){
            if(cur->data == key){
                if(!prev)
                    return idx; // first element
                swap(prev->data, cur->data); // next access faster
                return idx - 1;
            }
            ++idx;
        }

        return -1;
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
};



int main(){
    LinkedList List;
    List.insertEnd(1);
    List.insertEnd(2);
    List.insertEnd(3);
    List.insertEnd(4);
    cout << List.Search(2) << endl;
    cout << List.Search(2) << endl;
    List.insertEnd(5);
    List.insertEnd(6);
    List.insertEnd(7);
    List.insertEnd(8);
    List.Print();


    return 0;
}
