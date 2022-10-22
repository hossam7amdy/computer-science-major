#include<iostream>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

struct Node{
    int data { };
    Node* next { };

    Node(int data): data(data){  }
    ~Node() {
		//To easily test your nodes are destructed
		cout << "Destroy value: " << data << "\n";
	}
};

class LinkedList{
private:
    Node* head { };
    Node* tail { };
    int length { };

    void delete_node(Node* item){
        debug_remove_node(item);
        delete item;
        length--;
    }

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

public:
    LinkedList() {  }
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;
    ~LinkedList(){
        while(head){
            Node* current = head->next;
            length--;
            delete head;
            head = current;
        }
    }

	///////////////// Debugging Utilities ///////////////
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
	void debug_print_List(string msg = "") {
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
	////////////////////////////////////////////////////
    void Print(){
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
        debug_print_List();
    }
    void insert_end(int value){
        Node* item = new Node(value);

        if(!head)
            head = tail = item;
        else{
            tail->next = item;
            tail = item;
        }
        debug_add_node(item);
        length++;
    }
    void insert_front(int value){
        Node* item = new Node(value);

        if(!head)
            head = tail = item;
        else{
            item->next = head;
            head = item;
        }
        debug_add_node(item);
        length++;
    }

    /// Problem #3: Reverse list nodes
    void reverseList(){ // O(n) time - O(1) space
        if(!head)
            return;

        tail = head;

        Node* prev{ head };
        head = head->next;
        while(head){
            // store & reverse link
            Node* next { head->next };
            head->next = prev;

            // move step
            prev = head;
            head = next;
        }
        // Finalize head and tail
        head = prev;
        tail->next = nullptr;

        reverse(debug_data.begin(), debug_data.end());
        debug_verify_data_integrity();
    }
};


int main() {
    LinkedList List;
    List.insert_end(1);
    List.insert_end(2);
    List.insert_end(3);
    List.insert_end(4);
    List.insert_end(5);

    List.Print();
    List.reverseList();
    List.Print();

    string expected = "5 4 3 2 1";
	string result = List.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}

	cout << "\n\nNO RTE\n";		// must see it, otherwise RTE

	return 0;
}
