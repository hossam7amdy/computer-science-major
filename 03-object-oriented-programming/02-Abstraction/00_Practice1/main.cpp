#include <iostream>
using namespace std;

#include "Rectangle.h"

int main()
{
    Rectangle r1(10,12.5);
    cout << r1.CalcArea() << endl;

    Rectangle r2;
    cout << r2.CalcPerimeter() << endl;
    r2.SetLength(5);
    cout << r2.GetLength() << " " << r2.GetWidth() << endl;

    return 0;
}
