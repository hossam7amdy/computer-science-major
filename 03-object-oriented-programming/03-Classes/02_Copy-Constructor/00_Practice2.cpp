///Revise: const with functions, pointers, and objects

#include<iostream>
using namespace std;

class Rectangle{
private:
    double length;
    double width;
public:
    Rectangle(double len, double wid): length(len), width(wid){
        // if any was a constant = cannot initialize here.
        //width = wid;
    }

    double ComputeArea() const {
        return length * width;
    }

    void SetLen(int len){
        this->length = len;
    }

    double GetLen() const { //
        return length;
    }
};

int main(){
    Rectangle r1(10.1, 2.1);
    cout << r1.GetLen() << endl;

    const Rectangle r2(2.2, 2.1);
    // only calls const functions
    cout << r2.ComputeArea() << endl;
    //r2.SetLen(10);

    const Rectangle* r3 = new Rectangle(3.1, 4);
    //r3->SetLen(11); // can't, const data
    r3 = &r2;

    Rectangle* const r4 = new Rectangle(3.1, 4);
    //r4 = &r2; // can't: assignment of read-only variable
    r4->SetLen(11);

    const Rectangle* const r5 = new Rectangle(3.1, 4);
    //r5 = &r2; // can't: assignment of read-only variavle
    //r5->SetLen(11); // can't: const data



    return 0;
}
