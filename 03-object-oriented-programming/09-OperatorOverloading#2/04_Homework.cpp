/// Array 1D
/*
● Implement Array class to have these members
● We need support for the following operators
    ○ Creating Array of N elements
    ○ Accessing using []
    ○ Cin and Cout
    ○ ++ prefix and postifx to increment every array cell with 1
    ○ Comparing: == and !=
    ○ Assigning array to another
    ○ See following main
*/

/// Dr's Note:
/*
 Observe that: copy constructors and operators can directly access private variables
 of another object of same class
 https://stackoverflow.com/questions/4117002/why-can-i-access-private-variables-in-the-copy-constructor
 */

#include<iostream>
#include<vector>
using namespace std;

class Array {
private:
	int sz;
	int *ptr;

public:
    explicit Array(int sz = 100): sz(sz), ptr(new int[sz])
    {
        for(int i=0; i<sz; i++)
            ptr[i] = 0;
    }
    Array(const Array &another): sz(another.sz), ptr(new int[sz])
    {
        for(int i=0; i<sz; ++i)
            ptr[i] = another.ptr[i];
    }
    Array & operator=(const Array &another)
    {
        if(this != &another)
        {
            if(this->sz != another.sz)
            {
                delete[] ptr;
                this->sz = another.sz;
                this->ptr = new int[sz];
            }
        }
        for(int i=0; i<sz; ++i)
            ptr[i] = another.ptr[i];
        return *this;
    }
    int &operator[](const int &pos) const
    {
        if(pos>=sz)
            throw out_of_range("Invalid Index\n");
        return ptr[pos];
    }
    bool operator==(const Array &another) const
    {
        if(sz != another.sz)
            return false;
        for(int i=0; i<sz; i++)
            if(ptr[i] != another.ptr[i])
                return false;

        return true;
    }
    bool operator!=(const Array &a) const
    {
        return !(*this == a);
    }
    Array &operator++() // prefix
    {
        for(int i=0; i<sz; ++i)
            ++ptr[i];
        return *this;
    }
    Array operator++(int) // postfix
    {
        Array temp = *this;
        ++*this;
        return temp;
    }
    int getSize() const
    {
        return sz;
    }
    ~Array()
    {
        delete[] ptr;
        ptr = nullptr;
        cout << "Bye\n";
    }
};

std::ostream &operator<<(ostream &output, const Array &a)
{
    for(int i=0; i<a.getSize(); i++)
        output << a[i] << " ";
    return output;
}

void test_Array() {
	Array arr1(6);

	int counter = 0;
	for (int i = 0; i < arr1.getSize(); ++i)
		arr1[i] = counter++;

	cout<<arr1<<"\n";

	Array arr2 = ++arr1;	// copy
	cout<<arr2<<"\n";

	if(arr2 == arr1)
		cout<<"arr2 == arr1\n";
	else
		cout<<"arr2 != arr1\n";

	Array arr3;
	arr3 = arr2++;
	cout<<arr3<<"\n";



	if(arr3 != arr1)
		cout<<"arr3 != arr1\n";
	else
		cout<<"arr3 == arr1\n";
}

int main() {
	test_Array();

	return 0;
}
