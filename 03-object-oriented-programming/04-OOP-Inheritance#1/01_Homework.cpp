#include<iostream>
using namespace std;


class Shape
{

};

class TowDimentional: public Shape
{

};

class ThreeDimentional: public Shape
{

};

class Circle: public TowDimentional
{

};

class Square: public TowDimentional
{

};

class Triangle: public TowDimentional
{

};

class Sphere: public ThreeDimentional
{

};

class Cube: public ThreeDimentional
{

};

class Tetrahedron: public ThreeDimentional
{

};


int main()
{
    return 0;
}
