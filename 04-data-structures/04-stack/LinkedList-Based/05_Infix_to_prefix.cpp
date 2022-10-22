#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;

typedef char type;

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
    void insert_at_bottom(const type &data){ // time O(n) = memory O(n)
        if(isEmpty())
            push(data);
        else{
            type cur = pop();

            insert_at_bottom(data);

            push(cur);
        }
    }
    void Reverse(){
        if(isEmpty())
            return;

        type cur = pop();
        Reverse();
        insert_at_bottom(cur);
    }
    void display() const {
        for(Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }
};

int precedence(const char &ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    return 0;
}

string InfixToPrefix(const string &infix){
    string prefix;
    Stack operators;

    //infix += "-";
    //operators.push('#');

    for(int i=0; i<(int)infix.size(); i++){
        char ch = infix[i];
        if(isalnum(ch))
            prefix += ch;
        else if(!operators.isEmpty() && precedence(operators.top()) > precedence(ch)){
            prefix += ch;
            int idx = (int)prefix.size() - 1;
            swap(prefix[idx-1],prefix[idx]);
        }
        else
            operators.push(ch);
    }
    string str;
    while(!operators.isEmpty())
        str += operators.pop();
    //cout << str << "\n";
    //reverse(str.begin(), str.end());
    prefix = str + prefix;
    return prefix;
}

int main(){
    cout << InfixToPrefix("1+2") << "\n";
    cout << InfixToPrefix("9-2+3") << "\n";
    cout << InfixToPrefix("4^3^2") << "\n";
    cout << InfixToPrefix("1+2+3") << "\n";
    cout << InfixToPrefix("1+2*3") << "\n";
    cout << InfixToPrefix("2*3+4") << "\n";
    cout << InfixToPrefix("1+3*5-8/2") << "\n";

    return 0;
}
