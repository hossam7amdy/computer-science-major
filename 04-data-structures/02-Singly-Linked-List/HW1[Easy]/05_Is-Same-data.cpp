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
    void Print(){
        Node *temp = head;
        while(temp != nullptr){
            debug_print_node(temp);
            temp = temp->next;
        }
        cout << "\n";
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
    void delete_front(){

        Node* temp = head->next;
        delete_node(head);
        head = temp;

        if(length<=1)
            tail = head;

        debug_verify_data_integrity();
    }
    Node* get_nth(int n){
        n--; // Zero-Based
        if(0>n || n>length)
            return nullptr;

        Node* res = head;
        while(n--)
            res = res->next;
        return res;
    }
    Node* get_nth_back(int n){
        return get_nth(length - n + 1);
    }
    bool is_same1(const LinkedList &other){
        if(this->length!=other.length)
            return false;
        else{
            for(Node* curr_h=this->head, *other_h=other.head; curr_h; curr_h=curr_h->next, other_h=other_h->next)
                if(curr_h->data!=other_h->data)
                    return false;
        }

        return true;
    }
    bool is_same2(const LinkedList &other){
        Node* h1=this->head, *h2=other.head;

        while(h1&&h2){
            if(h1->data!=h2->data)
                return false;

            h1=h1->next, h2=h2->next;
        }

        return !h1&&!h2;
    }
    ~LinkedList(){
        while(head){
            Node* current = head->next;
            length--;
            delete head;
            head = current;
        }
    }
};


int main(){
    LinkedList list1;
    LinkedList list2;

    cout << list1.is_same2(list2) << "\n";
    list1.insert_front(1);
    list1.insert_front(3);
    list2.insert_front(1);
    cout << list1.is_same2(list2) << "\n";
    list2.insert_front(3);
    cout << list1.is_same2(list2) << "\n";
    list1.insert_end(8);
    list1.insert_end(15);
    list2.insert_end(8);
    list2.insert_end(77);
    cout << list2.is_same2(list1) << "\n";
    cout << list2.is_same2(list2) << "\n";


    return 0;
}
