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
/*
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
	////////////////////////////////////////////////////
	*/
public:
    LinkedList() {  }
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;

	void print(){ // time O(n)
	    for(Node* curr = head; curr; curr = curr->next)
            cout << curr->data << " ";
        cout << "\n";
	}
	void add_element(int value){ // time O(n) memory O(1)
	    Node* item = new Node(value);
        if(!head){
            head = item;
            return;
        }

	    for(Node* curr=head, *prev={ }; ;prev=curr, curr=curr->next){
            if(!curr){
                curr = item;
                prev->next = curr;
                return;
            }
	    }
	}
	Node* get_tail(){ // time O(n) memory O(1)

	    Node* curr = head;

        for(; curr->next; curr = curr->next);

        return curr;
	}

    ~LinkedList(){
        while(head){
            Node* current = head->next;
            //length--;
            delete head;
            head = current;
        }
    }
};


int main(){
    LinkedList List;
    List.add_element(1);
    List.add_element(2);
    List.add_element(3);
    List.print();
    cout << List.get_tail() << "\n";


    return 0;
}
