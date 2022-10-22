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

bool debug_sort_data(const Node* n1, const Node* n2){
    return n1->data < n2->data;
}

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
    Node* reverse_from(Node* node){ // time O(n) - memory O(n)
        if(node->next)
            reverse_from(node->next)->next = node;

        return node;
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
    /// Problem #1: Delete with key
    void delete_middle(Node* node){
        Node* to_delete = node->next;

        if(to_delete==tail){
            tail = node;
            tail->next = nullptr;
        }
        else
            node->next = node->next->next;

        delete_node(to_delete);
    }
    void delete_node_with_key(int value){
        if(length==0)
            cout << "Empty List\n";
        else if(head->data==value)
            delete_front();
        else{
            for(Node* cur=head, *prev { }; cur; prev=cur, cur=cur->next){
                if(cur->data == value){
                    delete_middle(prev);
                    break;
                }
            }
            cout << "There is no such a value\n";
        }
        debug_verify_data_integrity();
    }
    /// Problem #2: Swap each pair vales
    void swap_pairs(){
        for(Node* cur=head; cur&&cur->next; cur=cur->next->next)
            swap(cur->data, cur->next->data);
    }
    /// Problem #3: Reverse List nodes
    void Reverse(){ // memory O(n)
        reverse_from(head);
        swap(head,tail);
        tail->next = nullptr;
        reverse(debug_data.begin(), debug_data.end());
        debug_verify_data_integrity();
    }
    void Reverse2(){ // time O(n) - memory O(1)
        if(length<=1)
            return;

        tail = head;
        Node* prev = head;

        head = head->next;
        while(head){
            Node* next = head->next;
            head->next = prev;

            prev = head;
            head = next;
        }

        head = prev;
        tail->next = nullptr;

        reverse(debug_data.begin(), debug_data.end());
        debug_verify_data_integrity();

    }
    /// Problem #4: Delete even positions
    void delete_even_positions(){
        if(length<=1)
            return;
        Node* cur = head;
        while(cur && cur->next){ // time O(n/2) - memory O(1)
            Node* target = cur;
            cur = cur->next->next;
            delete_middle(target);
        }
        debug_verify_data_integrity();
    }
    /// Problem #5: Insert to be sorted
    void embed_after(Node* prev, int value){
        Node* item = new Node(value);

        item->next = prev->next;
        prev->next = item;
        length++;

        debug_add_node(item);
        sort(debug_data.begin(), debug_data.end(),debug_sort_data);
    }
    void insert_sorted(int value){
        if(!head || value<=head->data)
            insert_front(value);
        else if(value>=tail->data)
            insert_end(value);
        else{
            for(Node *cur=head, *prev{ }; cur; prev=cur,cur=cur->next){
                if(value<=cur->data){
                    embed_after(prev, value);
                    break;
                }
            }
        }
        debug_verify_data_integrity();
    }
};

void test1() {
	cout << "\n\ntest1\n";
	LinkedList List;

	List.insert_sorted(1);
	List.insert_sorted(3);
	List.insert_sorted(5);
	List.insert_sorted(2);
	List.insert_sorted(4);
	// some actions
	List.Print();

	string expected = "1 2 3 4 5";
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

	List.insert_sorted(6);
	List.insert_sorted(2);
	List.insert_sorted(1);
	List.insert_sorted(2);
	List.insert_sorted(5);
	List.insert_sorted(3);
	// some actions
	List.Print();

	string expected = "1 2 2 3 5 6";
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

	List.insert_sorted(1);
	//List.insert_sorted(2);
	List.Print();

	string expected = "1";
	string result = List.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	List.debug_print_List("********");
}

void test4() {
	cout << "test1\n";
	LinkedList List;

	List.insert_sorted(10);
	List.insert_sorted(2);
	List.insert_sorted(30);
	List.insert_sorted(4);
	// some actions
	List.Print();

	string expected = "2 4 10 30";
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
	test4();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}
