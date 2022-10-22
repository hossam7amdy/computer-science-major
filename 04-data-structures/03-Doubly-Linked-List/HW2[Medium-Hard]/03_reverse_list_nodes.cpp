#include <iostream>
using namespace std;

class LinkedList{
private:
    struct Node{
        int data{ };
        Node* next{ };
        Node* prev{ };

        Node(int data): data(data){ }
        ~Node(){
            //cout << "Destroy value: " << data << " at address " << this << "\n";
        }
    };

    Node* head{ };
    Node* tail{ };
    int length{ };

    void link(Node* first, Node* second){
        if(first)
            first->next = second;
        if(second)
            second->prev = first;
    }
public:
    LinkedList() { }
    ~LinkedList(){
        while(head){
            Node* cur = head;
            head=head->next;
            delete(cur);
        }
        head = tail = nullptr;
    }

    void insert_end(int value){
        Node* item = new Node(value);

        if(!head)
            head = tail = item;
        else{
            link(tail, item);
            tail = item;
        }
        ++length;
    }

    void print(){
        for(Node* cur=head; cur; cur=cur->next){
            cout << cur->data << " ";
            if(cur == head)
                cout << "<- head ";
            else if(cur == tail)
                cout << "<- tail\n";
        }
    }

    void reverseList(){
        if(!length)
            return;

        Node *first = head, *second = head->next;
        while(second){
            Node *secondNext = second->next;

            link(second, first);

            first = second;
            second = secondNext;
        }
        swap(head, tail);
        head->prev = tail->next = nullptr;
    }
};

void test1() {
	cout << "test1\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.reverseList();

	List.print();
}

void test2() {
	cout << "\n\ntest2\n";
	LinkedList List;

	List.insert_end(1);
	List.reverseList();

	List.print();
}

void test3() {
	cout << "\n\ntest3\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.insert_end(3);
	List.insert_end(4);
	List.insert_end(5);
	List.insert_end(6);
	List.reverseList();

	List.print();
}

void test4() {
	cout << "\n\ntest4\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.insert_end(3);
	List.insert_end(4);
	List.insert_end(5);
	List.reverseList();

	List.print();
}

int main() {
	test1();
	test2();
	test3();
	test4();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}

