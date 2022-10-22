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

char convert_sign(const char &s1, const char &s2){
    if(s1 == s2)
       return '+';
    return '-';
}

string remove_brackets(const string &exp){
    Stack op;
    op.push('+'); // causes no change

    string res;
    for(int i=0; i<(int)exp.size(); i++){
        char ch = exp[i];
        if(isdigit(ch))
            res+=ch;
        else if(ch == '(')
            op.push(res[(int)res.size()-1]);
        else if(ch == ')')
            op.pop();
        else
            res += convert_sign(op.top(), ch);
    }
    return res;
}

int main(){

    string test;

	test = "1+2-3-4+5-6-7+8";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1+2-3-4+5-6-7+8" == remove_brackets(test));

	test = "9-(2+3)";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("9-2-3" == remove_brackets(test));

	test = "9-(2-3)";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("9-2+3" == remove_brackets(test));

	test = "9+(2-3)";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("9+2-3" == remove_brackets(test));

	test = "1-(2-3-(4+5))-6-(7-8)";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1-2+3+4+5-6-7+8" == remove_brackets(test));

	test = "1-(2-3-(4+5)+6-7)";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1-2+3+4+5-6+7" == remove_brackets(test));

	test = "1-(2-3-(4+5-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1-2+3+4+5-6+7" == remove_brackets(test));

	test = "1-((4+5)-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1-4-5+6-7" == remove_brackets(test));

	test = "1-(((4-5)-(6-7))))";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1-4+5+6-7" == remove_brackets(test));

	test = "1-(2-3-((4+5)-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1-2+3+4+5-6+7" == remove_brackets(test));

	test = "1-(2-3-((4-5)-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1-2+3+4-5-6+7" == remove_brackets(test));

	test = "1-(2-3+((4-5)-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";
	assert("1-2+3-4+5+6-7" == remove_brackets(test));

    return 0;
}
