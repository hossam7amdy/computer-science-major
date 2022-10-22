#include <iostream>
using namespace std;

int main() {
    int val1 = 10;
    int val2 = 20;

    const int val3 = 30;

    /// 1)Pointers to constant
    const int* ptr1 = &val1;
    cout << *ptr1 << endl;
    // *ptr1 = 11; =>> CAN'T change the data it points to (Read-Only)

    ptr1 = &val2; // =>> BUT can change the pointer value itself
    cout << *ptr1 << endl;

    ptr1 = &val3; // =>> Notice val3 is CONSTANT also
    cout << *ptr1 << endl;

    /// 2)Constant Pointers
    int* const ptr2 = &val1;
    cout << *ptr2 << endl;
    *ptr2 = 11; // OK

    //ptr = &val2; =>> NO: As pointer itself is constant

    /// 3)Constant Pointers to Constant
    const int* const ptr3 = &val3;
    cout << *ptr3 << endl; // OK

    //*ptr3 = 31; =>> CAN'T change data it points to

    //ptr3 = &val1; =>> CAN'T change its value



	return 0;
}
