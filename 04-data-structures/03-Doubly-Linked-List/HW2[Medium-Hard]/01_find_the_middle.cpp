#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node{
    int data{ };
    Node* next{ };
    Node* prev{ };

    Node(int data): data(data){ }
    ~Node(){
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

bool sort_data(const Node* n1, const Node* n2){
    return n1->data < n2->data;
}

class LinkedList{
private:
    Node* head{ };
    Node* tail{ };
    int length{ };

    // for debugging
    vector<Node*> debug_data;

    void debug_add_node(Node* node){
        debug_data.push_back(node);
    }
    void debug_remove_node(Node* node){
        auto it = find(debug_data.begin(), debug_data.end(), node);

        if(it!=debug_data.end())
            debug_data.erase(it);
        else
            cout << "Node does not exist\n";
    }
public:
    LinkedList() { }
    LinkedList(const LinkedList&) = delete;
    void operator=(const LinkedList&) = delete;
    ~LinkedList(){
        while(head){
            Node* cur = head;
            head=head->next;
            delete(cur);
        }
        head = tail = nullptr;
    }

    ////////////////////// Debugging Utilities /////////////////////
    string debug_to_string(){
        if(!length)
            return "";

        ostringstream oss;
        for(Node* cur=head; cur; cur=cur->next){
            oss << cur->data;

            if(cur->next)
                oss << " ";
        }
        return oss.str();
    }

    void debug_print_node(Node* node){
        if(node==nullptr){
            cout << "nullptr\n";
            return;
        }

        if(node->prev==nullptr)
            cout << "X\t";
        else
            cout << node->prev->data << "\t";

        cout << "<= [" << node->data << "] =>\t";

        if(node->next==nullptr)
            cout << "X\t";
        else
            cout << node->next->data << "\t";

        if(node==head)
            cout << "head\n";
        else if(node==tail)
            cout << "tail\n";
        else
            cout << "\n";
    }
    void debug_print_List(){
        for(const auto item : debug_data)
            debug_print_node(item);
        cout << "\n";
    }

    void debug_verify_data_integrity(){
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
			assert(!head->prev);
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++) {
			if (len == length-1)	// make sure we end at tail
				assert(cur == tail);
		}

		assert(length == len);
		assert(length == (int )debug_data.size());

		len = 0;
		for (Node* cur = tail; cur; cur = cur->prev, len++) {
			if (len == length-1)	// make sure we end at head
				assert(cur == head);
		}
    }
    ///////////////////////////////////////////////////////////////

    // maintain vector data & length
    void add_node(Node* item){
        debug_add_node(item);
        ++length;
    }
    void delete_node(Node* item){
        debug_remove_node(item);
        --length;
        delete item;
    }

    void print(){
        for(Node* cur=head; cur; cur=cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }
    void print_reversed(){
        for(Node* cur=tail; cur; cur=cur->prev)
            cout << cur->data << " ";
        cout << "\n";
    }

    void link(Node* first, Node* second){
        if(first)
            first->next = second;
        if(second)
            second->prev = first;
    }

    void insert_front(int value){
        Node* item = new Node(value);
        add_node(item);

        if(!head)
            head = tail = item;
        else{
            link(item, head);
            head = item;
        }

        debug_verify_data_integrity();
    }
    void insert_end(int value){
        Node* item = new Node(value);
        add_node(item);

        if(!head)
            head = tail = item;
        else{
            link(tail, item);
            tail = item;
        }

        debug_verify_data_integrity();
    }

    void embed_after(Node* node_before, int value){
        Node* item = new Node(value);
        add_node(item);

        Node* node_after = node_before->next;

        link(node_before, item);
        link(item, node_after);
    }
    void insert_sorted(int value){
        if(!length || head->data >= value)
            insert_front(value);
        else if(tail->data <= value)
            insert_end(value);
        else{
            for(Node* cur=head; cur; cur=cur->next){
                if(cur->data >= value){
                    embed_after(cur->prev, value);

                    debug_verify_data_integrity();
                    break;
                }
            }
        }
        sort(debug_data.begin(), debug_data.end(), sort_data);
    }

    void delete_front(){
        if(!head)
            return;

        Node* cur=head->next;
        delete_node(head);

        head = cur;
        if(head)
            head->prev = nullptr;
        else
            tail = nullptr;

        debug_verify_data_integrity();
    }
    void delete_end(){
        if(!head)
            return;

        Node* cur=tail->prev;
        delete_node(tail);

        tail = cur;
        if(tail)
            tail->next = nullptr;
        else
            head = nullptr;

        debug_verify_data_integrity();
    }

    Node* delete_and_link(Node* cur){
        Node* ret = cur->prev;
        // delete and connect
        link(ret, cur->next);
        delete_node(cur);

        return ret;
    }
    void delete_node_with_key(int key){ // time O(n) - memory O(1)
        if(!head)
            cout << "List is empty\n";
        else if(head->data == key)
            delete_front();
        else if(tail->data == key)
            delete_end();
        else{
            for(Node* cur=head; cur; cur=cur->next){
                    if(cur->data == key){
                        delete_and_link(cur);
                        return;
                    }
                }
                cout << "No value with such a key\n";
            }
        debug_verify_data_integrity();
    }
    /// Problem #1: Find the middle
    int middle_value1(){ // time O(n) - memory O(1)
        assert(head);

        Node *h=head, *t=tail;

        while(h!=t && h->prev!=t)
            h=h->next, t=t->prev;

        return h->data;
    }
    int middle_value2(){
        assert(head);
        /*
		 * The idea is simple but smart!
		 * use 2 pointers
		 * The first (slow) moves normally step by step
		 * The second (fast) jump 2 steps each time!
		 * If the list has e.g. 10 elements
		 * When the slow in the middle (e.g. 5), the fast is at the double (10)
		 * From that we know we found the middle.
		 */

        Node *slow=head, *fast=head;

        while(fast && fast->next){
                fast = fast->next->next; // Hare: jump 2 steps
            slow = slow->next;       // Tortoise
        }

        return slow->data;
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

	List.print();
	//List.print_reversed();

	int expected = 3;
	int result = List.middle_value2();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	List.debug_print_List();
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

	List.print();
	//List.print_reversed();

	int expected = 4;
	int result = List.middle_value2();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	List.debug_print_List();
}

void test3() {
	cout << "\n\ntest3\n";
	LinkedList List;

	List.insert_end(1);
	List.insert_end(2);

	List.print();
	//List.print_reversed();

	int expected = 2;
	int result = List.middle_value2();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	List.debug_print_List();
}

int main() {
	test1();
	test2();
	test3();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}

