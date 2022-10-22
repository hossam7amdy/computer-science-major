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

    void mergeList(LinkedList &another){
        if(!another.length)
            return;

        if(head){
            Node *cur1 = head;
            Node *cur2 = another.head;
            Node *last{};
            head = nullptr;

            while(cur1 && cur2){
                Node* Next{};
                if(cur1->data <= cur2->data){
                    Next = cur1;
                    cur1 = cur1->next;
                }else{
                    Next = cur2;
                    cur2 = cur2->next;
                }
                link(last, Next);
                last = Next;
                if(!head)
                    head = last;
            }
            if(cur2){
                tail = another.tail;
                link(last, cur2);
            }else if(cur1){
                link(last, cur1);
            }
        }
        else{
            head = another.head;
            tail = another.tail;
        }
        length += another.length;
        another.head = another.tail = nullptr;
        another.length = 0;
    }
};

void test1() {
	cout << "test1\n";
	LinkedList List1;
	List1.insert_end(10);
	List1.insert_end(20);
	List1.insert_end(30);
	List1.insert_end(40);
	List1.insert_end(50);

    LinkedList List2;
	List2.insert_end(10);
	List2.insert_end(25);
	List2.insert_end(35);
	List2.insert_end(45);
	List2.insert_end(55);

	List1.mergeList(List2);
	List1.print();
}

void test2() {
	cout << "\n\ntest2\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.insert_end(3);
	List.insert_end(4);
	List.insert_end(5);

	LinkedList List2;

	List.mergeList(List2);
	List.print();
}

void test3() {
	cout << "\n\ntest3\n";
	LinkedList List;

	LinkedList List2;

	List2.insert_end(1);
	List2.insert_end(2);
	List2.insert_end(3);
	List2.insert_end(4);
	List2.insert_end(5);
	List2.insert_end(6);

	List.mergeList(List2);
	List.print();
}

int main() {
	test1();
	test2();
	test3();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}

