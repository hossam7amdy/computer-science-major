#include<iostream>
using namespace std;

class Regtangle{
private:
    double length;
    double width;
    Regtangle(){ length = width = 0; }

public:
    Regtangle(double _len, double _width){
        length = _len;
        width = _width;
    }

    //Setters
    void SetLen(double _len){ length = _len; }
    void SetWidth(double _wid){ width = _wid; }

    //Getters
    double GetLen(){ return length; }
    double GetWidth(){ return width; }

    double CalcArea(){ return length * width; }
    double CalcPerimeter(){  return 2 * (length + width);  }
};

int main(){
    Regtangle r1(3.2,4);
    cout << r1.CalcArea() << "\n" << r1.CalcPerimeter();
}
