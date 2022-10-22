#include "Rectangle.h"

/// Implementation of Rectangle class ( HOW )

//ctor
Rectangle::Rectangle(){ length = width = 0; }
Rectangle::Rectangle(double _length, double _width){ length = _length, width = _width; }

//setters
void Rectangle::SetLength(double _length){ length = _length; }
void Rectangle::SetWidth(double _width){ width = _width; }

//getters
double Rectangle::GetLength(){return length; }
double Rectangle::GetWidth(){return width; }

//member functions
double Rectangle::CalcArea(){return length * width; }
double Rectangle::CalcPerimeter(){return 2 * (length + width); }

//dtor
Rectangle::~Rectangle(){ }
