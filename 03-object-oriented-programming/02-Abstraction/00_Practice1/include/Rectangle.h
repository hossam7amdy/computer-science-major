#ifndef RECTANGLE_H
#define RECTANGLE_H

/// Interface of Rectangle class ( WHAT )

class Rectangle
{
    public:
        Rectangle();
        Rectangle(double _length, double _width);

        //getters & setters
        void SetLength(double _length);
        double GetLength();
        void SetWidth(double _width);
        double GetWidth();

        //member functions
        double CalcArea();
        double CalcPerimeter();

        virtual ~Rectangle();

    protected:

    private:
        double length;
        double width;
};

#endif // RECTANGLE_H
