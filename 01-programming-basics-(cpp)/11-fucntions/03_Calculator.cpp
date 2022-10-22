#include <iostream>
using namespace std;

/*
● Develop a function that allows user to do the following (menu options):
    ○ Add 2 numbers
    ○ Subtract 2 numbers
    ○ Multiply 2 numbers
    ○ Divide 2 numbers
    ○ End the program
● Consider the following functions:
    ○ Function to read 2 double numbers - by reference
    ○ 4 functions, one for each operation. Don’t divide by zero!
    ○ Function to display the menu of the 5 options - read number and return it.
■ User should enter number from 1 to 5. If not, display error message
■ If exit, end the program by printing how many operations were done
*/

int menu(){
    int choice = -1;
    while(choice == -1){
        cout << "\nMenu\n";
        cout << "1- Add 2 numbers\n";
        cout << "2- Subtract 2 numbers\n";
        cout << "3- Multiply 2 numbers\n";
        cout << "4- Divide 2 numbers\n";
        cout << "5- End the program\n";
        cin >> choice;
        if(!(1<=choice && choice <=5)){
            cout << "Invalid input. Try again!\n";
            choice == -1;
        }
    }
    return choice;
}

void sum(int a, int b){
    cout << a+b;
}

void sub(int a, int b){
    cout << a-b;
}

void multiply(int a, int b){
    cout << a*b;
}

void divide(double a, double b){
    if(!b){
        cout << "Cannot divide by ZERO\n";
        return;
    }
    cout << a/b;
}

void calculator(){
    int x,y,cnt;
    while(true){
        int choice = menu();
        if(choice == 1){
            cin >> x >> y;
            sum(x,y);
            cnt++;
        }
        else if(choice == 2){
            cin >> x >> y;
            sub(x,y);
            cnt++;
        }
        else if(choice == 3){
            cin >> x >> y;
            multiply(x,y);
            cnt++;
        }
        else if(choice == 4){
            cin >> x >> y;
            divide(x,y);
            cnt++;
        }
        else{
            cout << "You did " << cnt << " operations.\n";
            break;
        }
    }
}

int main() {
    calculator();

	return 0;
}
