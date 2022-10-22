#include<iostream>
#include<cassert>
#include<unordered_set>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data {};
        Node* next {};
        Node(int data) : data(data) {}
    };

	Node *head { };
	Node *tail { };
public:
	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
	}
    void print() {
		for(Node* cur=head; cur; cur=cur->next)
			cout<<cur->data<<" ";
		cout<<"\n";
	}

	/// Homework ///
    void create_cycle() {
		for (int i = 0; i < 4; ++i)
			insert_end(i);
		Node* now = tail;
		for (int i = 0; i < 3; ++i)
			insert_end(14 + i);
		tail->next = now;// cycle
	}
	void remove_cycle(){
        unordered_set<Node*> visited;

        for(Node *prev{}, *cur=head; cur; prev=cur, cur=cur->next){
            if(visited.count(cur)){
                prev->next = nullptr;
                tail = prev;
                break;
            }
            visited.insert(cur);
        }
	}
};

int main() {

	LinkedList List;

	List.create_cycle();
	List.remove_cycle();

	List.remove_cycle();
	List.print();


	return 0;
}


