#include<iostream>
#include<sstream>
#include<vector>
using namespace std;


class Shape
{
private:
    string name;
public:
    Shape(const string& name): name(name)
    {

    }

    string getName() const
    {
        return name;
    }

    virtual double ComputeArea() const
    {
        throw invalid_argument("Not Implemented. Do Override\n");
        return -1;
    }

    virtual void Draw() const
    {
        cout << "Draw " << getName() << " its Area = " << ComputeArea() << endl;
    }

    virtual Shape* Clone() const
    {
        invalid_argument("Not Implemented. Do Override\n");
        return nullptr;
    }

    virtual ~Shape()
    {

    }
};

class Point
{
private:
    double x;
    double y;
public:
    Point(double x, double y): x(x), y(y)
    {

    }

    double getX() const
    {
        return x;
    }
    void setX(const double& x)
    {
        this->x = x;
    }
    double getY() const
    {
        return y;
    }
    void setY(const double& y)
    {
        this->y = y;
    }
    string ToString() const
    {
        ostringstream oss;
        oss << "(" << x << ", " << y <<")";
        return oss.str();
    }
    ~Point()
    {

    }
};

class Rectangle: public Shape
{
private:
    Point top_left;
    Point top_right;
public:
    Rectangle(const string &name, const Point &top_left, const Point &top_right):
        Shape(name), top_left(top_left), top_right(top_right)
    {
    }

    virtual double ComputeArea() const override
    {
        return top_left.getX() * top_right.getY();
    }

    virtual void Draw() const override
    {
        Shape::Draw();

        cout << "\tTopLeft " << top_left.ToString()
                << " - TopRight " << top_right.ToString() <<"\n";
    }

    virtual Rectangle* Clone() const override
    {
        return new Rectangle(*this);
    }

    virtual ~Rectangle()
    {

    }
};

class Circle: public Shape
{
private:
    double radius;
    Point center;
public:
    Circle(const string& name, const double& radius, const Point &center):
        Shape(name), radius(radius), center(center)
    {
    }

    virtual double ComputeArea() const override
    {
        return (center.getX() + center.getY()) * radius * radius;
    }

    virtual void Draw() const override
    {
        Shape::Draw();
        cout << "\tCenterPoint = " << center.ToString() << "\n";
    }

    virtual Circle* Clone() const
    {
        return new Circle(*this);
    }

    virtual ~Circle()
    {

    }
};

class ImageEditor
{
protected:
    vector<Shape*> shapes;
public:
    void AddShape(const Shape &shape)
    {
        shapes.push_back(shape.Clone());
    }

    virtual void Draw() const
    {
        cout << "ImageEditor::Draw\n";
        for(const auto& shape : shapes)
        {
            shape->Draw();
        }
    }

    ~ImageEditor()
    {
        for(auto& shape : shapes)
        {
            delete shape;
            shape = nullptr;
        }
        this->shapes.empty();
    }
};

class AdobePhotoshop: public ImageEditor
{
 public:
     virtual void Draw() const override
     {
         cout << "Adobe Photoshop\n";
         ImageEditor::Draw();
     }

     void EnlargeShapes(double percent)
     {
         for(auto &shape : shapes)
         {
             // to be Implemented
         }
     }
     virtual ~AdobePhotoshop()
     {

     }
};

void Intialize(AdobePhotoshop* ImgEdit)
{
    Rectangle r1("MyRoom", Point(1.5,2.5), Point(2,3));
    Circle c1("MyBall", 2.1, Point(1.4, 1.7));

    ImgEdit->AddShape(r1);
    ImgEdit->AddShape(c1);
}

int main()
{
    AdobePhotoshop* ImgEdit = new AdobePhotoshop();

    Intialize(ImgEdit);

    ImgEdit->Draw();

    delete ImgEdit;
    ImgEdit = nullptr;

    cout << "\nFreed YaY!\n";

    return 0;
}
