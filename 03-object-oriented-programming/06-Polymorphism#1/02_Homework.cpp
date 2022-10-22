/// Homework 2: Square
/*
● A fresh engineer design the following diagram for some shapes relations
    ○ Why do you think he thought this way?
    ○ Figure Out a reason why it is incorrect? Provide a tip
    ○ How to fix the design.
■ Assume rectangle class is a heavy class (several functionalities and code).
*/

/// Answer:
/*
- The engineer thought: Square is a rectangle with all sides equal
- This is good for a square class
- But in a polymorphism setup, a square object is sent to a rectangle object
- Then this rectangle can do change for width/height
- We then end up with a corrupted square status!

- Tip: Make sure your sub-class is really a valid superclass. This is related to the Liskov Substitution Principle

- The right way is a composition
- Square class has an instance of type Rectangle
- Delegate all calls to a rectangle
- Now we are safe, without the need for inheritance between rectangle and square


https://effectivesoftwaredesign.com/2010/09/20/when-a-square-is-not-a-rectangle/#:~:text=Let's%20say%20that%20we%20organize,a%2Dkind%2Dof%20relationship.
*/

class Rectangle
{
private:
    double width;
    double hight;
public:
    // several functionalities and code
};

class Square // : public Rectangle WRONG
{
    // The right way is a composition
    Rectangle square;
public:
    // Delegate all calls to a rectangle
};
