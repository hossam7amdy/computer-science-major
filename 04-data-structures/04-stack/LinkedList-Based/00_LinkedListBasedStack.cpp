#include<iostream>
#include<assert.h>
using namespace std;

typedef int type;

class Stack{
private:
    struct Node{
        type data;
        Node *next{ };

        Node(const type &data): data(data) { }
        ~Node(){
            cout << "Node " << data << " deleted with address " << this << "\n";
        }
    };

    Node* head{ };

public:
    Stack(){
    }
    Stack(const Stack&) = delete;
    void operator=(const Stack&) = delete;
    ~Stack(){
        while(!isEmpty())
            pop();
    }

    void push(const type &data){
        Node* item = new Node(data);

        assert(item);

        item->next = head;
        head = item;
    }
    type pop(){
        assert(head);
        Node* next = head->next;
        type element = head->data;
        delete head;
        head = next;
        return element;
    }
    type top() const {
        assert(head);
        return head->data;
    }
    bool isEmpty(){
        return head==nullptr;
    }
    void display() const {
        for(Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }
};

int main(){
    Stack stk;

    cout << stk.isEmpty() << "\n";

    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.display();

    cout << stk.pop() << "\n";

    return 0;
}
