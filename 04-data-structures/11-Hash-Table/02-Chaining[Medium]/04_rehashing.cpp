#include<iostream>
#include<vector>
#include<sstream>
#include<assert.h>
using namespace std;

int hash_string(const string &str, int n = 65407){
    long long base = 2 * 26 + 10;
    long long n_ = n;
    long long sum{};
    for(int i=0; i<(int)str.size(); i++){
        int val{};
        if(islower(str[i]))
            val = str[i] - 'a';
        else if(isupper(str[i]))
            val = 26 + str[i] - 'A';
        else if(isdigit(str[i]))
            val = 26 + 26 + str[i] - '0';
        else
            assert(false);
        sum = sum * base + val;
        sum %= n_;
    }
    return sum;
}

struct PhoneEntry{
    const static int INTERNAL_LIMIT = 2147483647;
    string name; // key
    string number; // data

    PhoneEntry(const string &name, const string &number):
        name(name), number(number){
    }

    int Hash() const {
        return hash_string(name, INTERNAL_LIMIT);
    }

    void print(){
        cout << "(" << name << ", " << number << ")  ";
    }
};

class PhoneHashTable{
private:
    int table_size{};
    vector< vector<PhoneEntry> > table;

    double limit_load_factor{};
    int total_elements{};

public:
    PhoneHashTable(int table_size = 10, double limit_load_factor = 0.75):
        table_size(table_size), limit_load_factor(limit_load_factor){
            table.resize(table_size);
    }

    void put(const PhoneEntry &entry){
        int idx = entry.Hash() % table_size;

        for(int i=0; i<(int)table[idx].size(); ++i){
            if(table[idx][i].name == entry.name){
                table[idx][i] = entry;
                return;
            }
        }
        ++total_elements;
        rehashing();
        table[idx].push_back(entry);
    }

    void rehashing(){
        double cur_load_factor = (double)total_elements / table_size;
        cout << cur_load_factor << "\n";
        if(cur_load_factor < limit_load_factor)
            return;

        PhoneHashTable new_table(2 * table_size, limit_load_factor);

        for(int i=0; i<table_size; ++i){
            if((int)table[i].size() == 0)
                continue;

            for(int j=0; j<(int)table[i].size(); ++j)
                new_table.put(table[i][j]);
        }

		// Copy & delete
		table_size *= 2;
		table = new_table.table;

		print_all();
    }

    bool remove_entry(const string &name){
        // do something
    }

    void get(PhoneEntry &p){
        // do something
    }

    void print_all(){
        cout<<"**********************\n";
		for (int hash = 0; hash < table_size; ++hash) {
			if (table[hash].size() == 0)
				continue;

			cout << "Hash " << hash << ": ";
			for (int i = 0; i < (int) table[hash].size(); ++i)
				table[hash][i].print();
			cout << "\n" << flush;
		}
    }

};

string to_str(int val) {
	ostringstream oss;
	oss << val;
	return oss.str();
}

int main(){

    PhoneHashTable table;
	for (int i = 0; i < 100; ++i) {
		table.put(PhoneEntry(to_str(i), to_str(i * 10)));
	}

    return 0;
}
