#include<iostream>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

class LinkedList{
private:
    struct Node{
        int data { };
        Node* next { };

        Node(int data): data(data){  }
        ~Node() {
            //To easily test your nodes are destructed
            cout << "Destroy value: " << data << "\n";
        }
    };

    Node* head{};
    Node* tail{};
    int length{};

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

            delete_node(head);
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

    void delete_front(){
        if(!length)
            return;

        Node* temp = head->next;
        delete_node(head);
        head = temp;

        if(length<=1)
            tail = head;

        debug_verify_data_integrity();
    }

    /// Problem #4: Delete even positions
    void delete_even_positions(){
        if(!head)
            return;

        for(Node* cur{ head }; cur; cur = cur->next){
            Node* target {cur->next};
            if(target)
                cur->next = target->next;
            else
                tail = cur;

            delete_node(target);
        }

    }
};

void test1() {
	cout << "\n\ntest1\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.insert_end(3);
	List.insert_end(4);
	List.insert_end(5);
	List.delete_even_positions();
	// some actions
	List.Print();

	string expected = "1 3 5";
	string result = List.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	List.debug_print_List("********");
}

void test2() {
	cout << "\n\ntest2\n";
	LinkedList List;


	List.insert_end(1);
	List.insert_end(2);
	List.insert_end(3);
	List.insert_end(4);
	List.insert_end(5);
	List.insert_end(6);
	List.delete_even_positions();
	// some actions
	List.Print();

	string expected = "1 3 5";
	string result = List.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	List.debug_print_List("********");
}

void test3() {
	cout << "\n\ntest3\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);
	List.delete_even_positions();
	List.Print();

	string expected = "1";
	string result = List.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	List.debug_print_List("********");
}


int main() {
	test1();
	test2();
	test3();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}
