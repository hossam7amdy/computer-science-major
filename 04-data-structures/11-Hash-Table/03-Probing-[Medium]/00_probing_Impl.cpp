#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

int hash_string(const string &str, int n = 65407){
    int base = 2 * 26 + 10;
    long long nn = n;
    long long sum{};

    for(int i=0; i<(int)str.size(); ++i){
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
        sum %= nn;
    }
    return sum;
}

struct PhoneEntry{
    const static int INTERNAL_LIMIT {65407};
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
    vector<PhoneEntry*> table;

    PhoneEntry* deleted = new PhoneEntry("","");

public:
    PhoneHashTable(const int &table_size):
        table_size(table_size){
            table.resize(table_size);
    }

    bool put(const PhoneEntry &entry){
        int idx = entry.Hash() % table_size;

        for(int i=0; i<table_size; ++i){
            if(table[idx]==deleted || !table[idx]){
                table[idx] = new PhoneEntry(entry);
                return true;
            }
            else if(table[idx]->name == entry.name){
                table[idx]->phone_number = entry.phone_number;
                return true;
            }
            idx = (idx+1) % table_size;
        }
        return false;
    }

    bool Remove(const PhoneEntry &entry){
        int idx = entry.Hash() % table_size;


        for(int i=0; i<table_size; ++i){
            if(!table[idx])
                break;
            else if(table[idx]->name == entry.name){
                delete table[idx];
                table[idx] = deleted;
                return true;
            }
            idx = (idx+1) % table_size;
        }
        return false;
    }

    bool get(PhoneEntry &entry){
        int idx = entry.Hash() % table_size;


        for(int i=0; i<table_size; ++i){
            if(!table[idx])
                break;
            else if(table[idx]->name == entry.name){
                entry.phone_number = table[idx]->phone_number;
                return true;
            }
            idx = (idx+1) % table_size;
        }
        return false;
    }

    void print_all(){
        for(int i=0; i<table_size; ++i){
            if(table[i]==deleted)
                cout << "X";
            else if(!table[i])
                cout << "E";
            else
                table[i]->print();
            cout << endl;
        }
        cout << "\n=========================\n";
    }
};


int main() {

	PhoneHashTable table(11);
	table.put(PhoneEntry("mostafa", "604-401-120"));
	table.put(PhoneEntry("mostafa", "604-401-777"));
	table.put(PhoneEntry("ali", "604-401-343"));
	table.put(PhoneEntry("ziad", "604-401-17"));
	table.put(PhoneEntry("hany", "604-401-758"));
	table.put(PhoneEntry("belal", "604-401-550"));
	table.put(PhoneEntry("john", "604-401-223"));

	table.print_all();
	/// I have different because I use different hashing function

	/*
	 0  E
	 1  E
	 2  E
	 3 (john, 604-401-223)
	 4  E
	 5  E
	 6 (mostafa, 604-401-120)
	 7 (hany, 604-401-758)
	 8 (ali, 604-401-343)
	 9 (ziad, 604-401-17)
	 10 (belal, 604-401-550)
	 */

	cout << table.Remove(PhoneEntry("smith", "")) << "\n"; // 0
	cout << table.Remove(PhoneEntry("hany", "")) << "\n";  // 1
	cout << table.Remove(PhoneEntry("john", "")) << "\n";  // 1
	table.print_all();
	/*
	 0  E
	 1  E
	 2  E
	 3  X
	 4  E
	 5  E
	 6 (mostafa, 604-401-120)
	 7  X
	 8 (ali, 604-401-343)
	 9 (ziad, 604-401-17)
	 10 (belal, 604-401-550)
	 */

	PhoneEntry e("belal", "");
	if (table.get(e))
		cout << e.phone_number << "\n";	// 604-401-550

	table.put(PhoneEntry("hany", "604-401-555"));
	table.print_all();
	/*
	 0  E
	 1  E
	 2  E
	 3  X
	 4  E
	 5  E
	 6 (mostafa, 604-401-120)
	 7 (hany, 604-401-555)
	 8 (ali, 604-401-343)
	 9 (ziad, 604-401-17)
	 10 (belal, 604-401-550)
	 */
	return 0;
}
