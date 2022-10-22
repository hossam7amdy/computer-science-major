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
    Node* get_nth(int k){
        if(k > length)
            return nullptr;
        if(k == length)
            return tail;

        Node* cur = head;
        while(--k)
            cur = cur->next;
        return cur;
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

    void swap_kth_using_length(int k){
        if(k > length)
            return; // nothing to do

        int kth_back = length - k + 1;
        if(k == kth_back) // same
            return;

        if(k > kth_back) // cross
            swap(k, kth_back);

        Node *first = get_nth(k);
        Node *last = get_nth(kth_back);

        Node *firstPrev = first->prev;
        Node *firstNext = first->next;

        Node *lastPrev = last->prev;
        Node *lastNext = last->next;

        if(k + 1 == kth_back){ // consecutive
            link(firstPrev, last);
            link(last, first);
            link(first, lastNext);
        }else{               // normal swaping
            link(firstPrev, last);
            link(last, firstNext);

            link(lastPrev, first);
            link(first, lastNext);
        }

        if(k == 1)
            swap(head, tail);
    }
};

void test0() {
	cout << "test0\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.insert_end(3);
	List.insert_end(4);
	List.insert_end(5);
	List.swap_kth_using_length(2);

	List.print();
}

void test1() {
	cout << "\n\ntest1\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.insert_end(3);
	List.insert_end(4);
	List.insert_end(5);
	List.swap_kth_using_length(1);

	List.print();
}

void test2() {
	cout << "\n\ntest2\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.insert_end(3);
	List.insert_end(4);
	List.insert_end(5);
	List.swap_kth_using_length(3);

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
	List.swap_kth_using_length(3);

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
	List.insert_end(6);
    List.insert_end(7);

	List.swap_kth_using_length(3);

	List.print();
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}

