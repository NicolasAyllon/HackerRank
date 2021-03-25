#include <iostream>

using namespace std;

// Solution
// Rectangle holds the width and height of a rectangle
class Rectangle {
    protected:
        int width;
        int height;
    public:
        void display() {
            cout << width << " " << height << '\n';
        }
        void read_input() {
            cin >> width >> height;
        }
};

// RectangleArea is derived from Rectangle
class RectangleArea : public Rectangle {
    // Inherits protected members from Rectangle
        // width
        // height
    public:
    // Inherits read_input() from Rectangle

    // Overrides display() to print area instead of dimensions
        void display() {
            cout << width * height << '\n';
        }
};


// From HackerRank
int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}