#include<iostream>
#include<assert.h>
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
    return 0;
}

/// Algorithm for parsing - simple expressions
string infixToPostfix(const string &infix){
    string postfix;
    Stack operators;

    for(int i=0; i<(int)infix.size(); i++){
        char ch = infix[i];
        if(isdigit(ch))
            postfix+=ch;
        else{
            while(!operators.isEmpty() && precedence(operators.top()) >= precedence(ch))
                postfix+=operators.pop();
            operators.push(ch);
        }
    }
    while(!operators.isEmpty())
        postfix += operators.pop();
    return postfix;
}

string infixToPostfix_v2(string infix){
    string postfix;
    Stack operators;

    infix += '-'; // what ever lowest priority: force stack got empty
    operators.push('#'); // removes isEmpty() condition

    for(int i=0; i<(int)infix.size(); i++){
        char ch = infix[i];
        if(isdigit(ch))
            postfix+=ch;
        else{
            while(precedence(operators.top()) >= precedence(ch))
                postfix+=operators.pop();
            operators.push(ch);
        }
    }

    return postfix;
}

int main(){

    cout << infixToPostfix("1+3*5-8/2") << "\n";

    cout << infixToPostfix_v2("2+3-2") << "\n";

    //cout << infixToPostfix("2+(3*(4-5*2)*(9/3+6))") << "\n";




    return 0;
}
