#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;


int hash_string(const string &str, int n = 65407){
    int base = 2 * 26 + 10;
    long long nn = n;
    long long sum{};

    for(int i=0; i<(int) str.size(); ++i){
        int val{};
        if(islower(str[i]))
            val = str[i] - 'a';
        else if(isupper(str[i]))
            val = 26 + str[i] - 'A';
        else if(isdigit(str[i]))
            val = 2 * 26 + str[i] - '0';
        else
            assert(false);
        sum = base * sum + val;
        sum %= nn;
    }
    return sum;
}

struct PhoneEntry{
    const static int INTERNAL_LIMIT = INT_MAX;
    string name;
    string phone_number;

    PhoneEntry(const string &name, const string &phone_number):
        name(name), phone_number(phone_number){
    }

    int Hash() const {
        return hash_string(name, INTERNAL_LIMIT);
    }

    void print() const {
        cout << "(" << name << ", " << phone_number << ")  ";
    }
};


class PhoneHashTable{
private:
    int table_size{};
    int total_elements{};
    vector<PhoneEntry*> table;

    PhoneEntry* deleted = new PhoneEntry("","");
public:
    PhoneHashTable(const int &table_size):
        table_size(table_size){
            table.resize(table_size);
    }

    void put(const PhoneEntry &entry){
        /*
		 * When to stop?
		 * One might stop when he performs table_size steps
		 * my impression: we better stop when we cycle back to same index
		 *
		 * Computationally, we can see that we can fail to add in both cases
		 * ALTHOUGHT there are still free elements!
		 * This never happens in linear probing
		 *
		 * If we failed to add: then do rehashing and try again
		 * 	which will typically works well (or do rehashing again)		 *
		 */
    }

    bool Remove(const PhoneEntry &entry){
    }

    bool get(PhoneEntry &entry){
    }

    void rehashing(){
        PhoneHashTable new_table(2*table_size);

        for(int i=0; i<table_size; ++i)
            if(table[i])
                new_table.put(*table[i]);

        table_size = 2 * table_size;
        table = new_table.table;
    }

    void print_all() const {
        for(int i=0; i<table_size; ++i){
            if(!table[i])
                cout << "E";
            else if(table[i] == deleted)
                cout << "X";
            else
                table[i]->print();

            cout << "\n";
        }
    }
};


int main() {


	PhoneHashTable table(6);
	table.put(PhoneEntry("xx", "604-401-343"));
	table.put(PhoneEntry("hany", "604-401-758"));
	table.put(PhoneEntry("john", "604-401-223"));
	table.put(PhoneEntry("mostafa", "604-401-120"));
	table.put(PhoneEntry("ziad", "604-401-17"));
	table.put(PhoneEntry("belal", "604-401-550"));

	table.put(PhoneEntry("asmaa", "604-401-778"));
	table.put(PhoneEntry("noha", "604-401-778"));


	table.print_all();
	return 0;
}
