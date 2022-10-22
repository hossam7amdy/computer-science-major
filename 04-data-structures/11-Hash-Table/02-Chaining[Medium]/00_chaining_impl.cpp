#include<iostream>
#include<vector>
using namespace std;

int hash_function(const string &data, const int &n){
    long long nn = n;
    long long sum {};

    for(int i=0; i<(int) data.size(); i++)
        sum = (sum * 26 + data[i] - 'a') % nn;
    return sum;
}

struct PhoneEntry{
    int INTERNAL_LIMIT = 65407;
    string name; // key
    string phone_number;

    int Hash() const {
        return hash_function(name, INTERNAL_LIMIT);
    }

    PhoneEntry(const string &name, const string &phone_number):
        name(name), phone_number(phone_number){
    }

    void print() const {
        cout << "(" << name << ", " << phone_number << ") ";
    }
};

class PhoneHashTable{
private:
    int table_size;
    vector< vector<PhoneEntry>> table;

public:
    PhoneHashTable(const int &table_size):
        table_size(table_size){
            table.resize(table_size);
    }

    void put(const PhoneEntry &entry){
        int bucket = entry.Hash() % table_size; // strict it to my table size

        for(int i=0; i<(int)table[bucket].size(); i++){
            if(table[bucket][i].name == entry.name){ // update
                table[bucket][i].phone_number = entry.phone_number;
                return;
            }
        }
        table[bucket].push_back(entry);
    }

    bool remove_entry(const PhoneEntry &entry){
        int bucket = entry.Hash() % table_size;

        for(int i=0; i<(int)table[bucket].size(); i++){
            if(table[bucket][i].name == entry.name){
                swap(table[bucket][i], table[bucket].back());
                table[bucket].pop_back();
                return true;
            }
        }
        return false;
    }

    bool get(PhoneEntry &entry){
        int bucket = entry.Hash() % table_size;

        for(int i=0; i<(int)table[bucket].size(); i++){
            if(table[bucket][i].name == entry.name){
                entry.phone_number = table[bucket][i].phone_number;
                return true;
            }
        }
        return false;
    }
    void print_all(){
        for(int bucket=0; bucket<table_size; bucket++){
            if(!(int)table[bucket].size())
                continue;

            cout << "Hash " << bucket << ": ";
            for(const auto &entry : table[bucket])
                entry.print();
            cout << "\n";
        }
    }
};

int main() {

	PhoneHashTable table(3);
	table.put(PhoneEntry("mostafa", "604-401-120"));
	table.put(PhoneEntry("mostafa", "604-401-777"));	// update
	table.put(PhoneEntry("ali", "604-401-343"));
	table.put(PhoneEntry("ziad", "604-401-17"));
	table.put(PhoneEntry("hany", "604-401-758"));
	table.put(PhoneEntry("belal", "604-401-550"));
	table.put(PhoneEntry("john", "604-401-223"));

	PhoneEntry e("mostafa", "");
	if (table.get(e))
		cout << e.phone_number << "\n";	// 604-401-777

	table.print_all();
	// Hash 0: (ali, 604-401-343)  (hany, 604-401-758)  (john, 604-401-223)
	// Hash 1: (mostafa, 604-401-777)  (ziad, 604-401-17)
	// Hash 2: (belal, 604-401-550)

	cout << table.remove_entry(PhoneEntry("smith", "")) << "\n"; // 0
	cout << table.remove_entry(PhoneEntry("hany", "")) << "\n";  // 1
	cout << table.remove_entry(PhoneEntry("belal", "")) << "\n";  // 1
	table.print_all();
	// Hash 0: (ali, 604-401-343)  (john, 604-401-223)
	// Hash 1: (mostafa, 604-401-777)  (ziad, 604-401-17)


	return 0;
}
