/// Array 2D
/*
● We will extend the Array class we did and make use of it as much as possible
● Provide access as arr(i, j)
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
    Array(const Array &another): sz(another.sz), ptr(new int[sz]) // copy constructor
    {
        for(int i=0; i<sz; ++i)
            ptr[i] = another.ptr[i];
    }
    Array & operator=(const Array &another) // assignment copy constructor
    {
        if(this != &another) // don't copy youself
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

class Array2D: public Array {
private:
	int rows;
	int cols;

public:
    Array2D(const int &r = 2, const int &c = 5):
        Array(r*c), rows(r), cols(c)  {  }

    int& operator()(const int &r, const int &c) const
    {
        int pos = r * cols + c;
        return Array::operator[](pos);
    }
    // If we did not override ++, the return from parent will be base-class!
    Array2D& operator++() // prefix
    {
        Array::operator++();
        return *this;
    }
    Array2D operator++(int) // postfix
    {
        Array2D temp = *this;
        ++*this;
        return temp;
    }
    friend ostream &operator<<(ostream &output, const Array2D &A2d);
};

ostream &operator<<(ostream &output, const Array2D &A2d)
{
    for(int r=0; r<A2d.rows; r++){
        for(int c=0; c<A2d.cols; c++){
            output << A2d(r,c) << " ";
        }
        cout << "\n";
    }
    return output;
}

void test_Array2d() {
	Array2D arr1(2, 3);

	int counter = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			arr1(i, j) = counter++;
		}
	}

	cout<<arr1<<"\n";

	Array2D arr2 = ++arr1;	// copy
	cout<<arr2<<"\n";

	if(arr2 == arr1)
		cout<<"arr2 == arr1\n";
	else
		cout<<"arr2 != arr1\n";

	Array2D arr3;
	arr3 = arr2++;
	cout<<arr3<<"\n";



	if(arr3 != arr1)
		cout<<"arr3 != arr1\n";
	else
		cout<<"arr3 == arr1\n";
}

int main() {
	test_Array2d();
	cout << "Bye\n";

	return 0;
}
