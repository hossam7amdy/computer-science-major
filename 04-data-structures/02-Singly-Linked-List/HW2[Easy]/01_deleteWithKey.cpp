#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data { };
        Node* next { };
        Node(int data) : data(data) {}
        ~Node() {
            cout << "\nDestroy value: " << data <<" at address "<< this<< "\n\n";
        }
    };

	Node *head { };
	Node *tail { };
	int length = 0;	// let's maintain how many nodes

    void deleteNode(Node* node) {
		--length;
		debug_remove_node(node);
		delete node;
	}

	/////////////// Debug Utilities ///////////////////
    vector<Node*> debug_data;	// add/remove nodes you use
	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}
	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void debug_print_node(Node* node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void debug_print_list(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int) debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		cout << "************\n"<<flush;
	}

	string debug_to_string() {
		if (length == 0)
			return "";
		ostringstream oss;
		for (Node* cur = head; cur; cur = cur->next) {
			oss << cur->data;
			if (cur->next)
				oss << " ";
		}
		return oss.str();
	}

	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		} else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++)
			assert(len < 10000);	// Consider infinite cycle?
		assert(length == len);
		assert(length == (int)debug_data.size());
	}
	////////////////////////////////////////////////////////////

public:
    LinkedList() { }
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;

    void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	void addEnd(const int &value) {
	    Node* item = new Node(value);
	    if(!head)
            head = tail = item;
        else{
            tail->next = item;
            tail = item;
        }
		++length;

		debug_add_node(item);
	}

	void deleteFront(){
	    if(head){
            Node* curr = head;
            head = head->next;
            deleteNode(curr);
	    }

        if(!head)
            tail = nullptr;

        debug_verify_data_integrity();
	}
	void deleteEnd(){
	    if(length <= 1){
            deleteFront();
            return;
	    }

	    Node* previous = getNth(length - 1);

	    deleteNode(tail);
	    tail = previous;
	    tail->next = nullptr;

	    debug_verify_data_integrity();
	}

	~LinkedList(){
        while(head){
            Node* temp = head;
            head = head->next;

            delete temp;
        }
	}

	Node* getNth(int idx){ // O(n)
        if(1 > idx || idx > length)
            return nullptr;

        Node* target{ head };
        while(--idx) // Zero-Based
            target = target->next;

        return target;
	}
	int Search(const int &key){ // O(n)
	    int idx{};
        for(Node* cur{ head }; cur; cur = cur->next, ++idx)
            if(cur->data == key)
                return idx + 1; // One-Based => more general

        return -1;
	}
	void deleteWithKey(const int &key){
	    int index{ Search(key) };
	    if(index == -1)
            cout << ;
        else if(index == 1)
            deleteFront();
        else if(index == length)
            deleteEnd();
        else{ // delete middle
            Node* prev { getNth(index - 1) };
            Node* target { prev->next };

            prev->next = target->next; // connect
            deleteNode( target );
        }
        debug_verify_data_integrity();
	}
};

int main(){
    LinkedList List;
    List.addEnd(10);
    List.addEnd(20);
    List.addEnd(30);

    List.deleteWithKey(30);
    List.deleteWithKey(10);
    List.deleteWithKey(10);

    List.print();

    return 0;
}
