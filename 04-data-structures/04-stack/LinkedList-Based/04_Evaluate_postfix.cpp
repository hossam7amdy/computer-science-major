#include<iostream>
#include<assert.h>
#include<cmath>
using namespace std;

typedef double type;

class Stack{
private:
    struct Node{
        type data;
        Node *next{ };

        Node(const type &data): data(data) { }
        ~Node(){
            //cout << "Node " << data << " deleted with address " << this << "\n";
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

double calculator(const double &l, const double &r, const char &op){
    if(op == '+')
        return l + r;
    else if(op == '-')
        return l - r;
    else if(op == '*')
        return l * r;
    else if(op == '/')
        return l / r;
    return pow(l,r);
}

double evaluate_postfix(const string &postfix){
    Stack st;

    for(int i=0; i<(int)postfix.size(); i++){
        char ch = postfix[i];
        if(isdigit(ch))
            st.push(ch-'0');
        else{
            double res = calculator(st.pop(), st.pop(), ch);
            st.push(res);
        }
    }
    return st.pop();
}

int main(){
    cout << evaluate_postfix("52/") << "\n";
    cout << evaluate_postfix("12+3+") << "\n";
    cout << evaluate_postfix("123*+") << "\n";
    cout << evaluate_postfix("23*4+") << "\n";
    cout << evaluate_postfix("135*+72/-") << "\n";
    cout << evaluate_postfix("432^^") << "\n";

    return 0;
}
