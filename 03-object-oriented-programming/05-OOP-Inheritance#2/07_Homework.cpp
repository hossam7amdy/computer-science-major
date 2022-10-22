#include<iostream>
#include<vector>
using namespace std;

class Color
{
private:
    string color;
public:

};

class Shape
{
protected:
    vector<Color> colors;
public:
    const double ComputeArea() const
    {

    }

    void Draw() const
    {

    }
};

class Point
{
private:
    int x;
    int y;

};

class Rectangle: protected Shape
{
private:
    Point top_left;
    Point top_right;
public:
    const double ComputeArea() const
    {

    }

    void Draw() const
    {

    }
};

class Circle: protected Shape
{
private:
    double radius;
    Point center;
public:
    Circle():radius(0)
    {

    }
    const double ComputeArea() const
    {

    }

    void Draw() const
    {

    }
};

class ImagEditor
{
protected:
    // aggregation (has a)
    vector<Shape> shapes;
public:
    void Draw() const
    {

    }
};

class AdobePhotoshop: public ImagEditor
{
 public:
     void EnlargeShapes(const double& percent)
     {

     }
    void Draw() const
    {

    }
};

int main()
{

    /*
1) The system explains an image editor which is "aggregated" of a set of shapes to draw (0 or more shape)
    Each shape supports the Draw function to draw it and another to compute its area
    The shape can be either rectangle or circle that should override the draw/area functions
    
    Adobe Photo-shop is an image editor with extra functionality of Enlarging the drawn shape by percent
    
    From the data perspective
        both color and shapes are protected variables
        rectangle and circle use a point class (x, y) which is enough to compute area or draw
            
            
2) There are 2 implementation concerns
    First, the Image editor has an array of shapes! Maybe we should have an array of rectangles and another array of circles
        But also this is so weird. We will keep duplicating code to do the same tasks of each shape
        Can't we just iterate on Shapes parent somehow?
        
    Second: Method Draw/ComputeArea in parent class shape. No default implementation can be provided!
        Should we do just empty function? What if someone just forgot to implement?
        Or maybe an assert?
        Can't we force a compile error if the user forgot to implement it?
        
    Both issues are handled with polymorphism!
    */

    return 0;
}
