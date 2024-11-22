#include <iostream>

using namespace std;

class Rectangle {
private:
    double width, height;  
public:
 
    Rectangle(double w, double h) {
        width = w;  
        height = h; 
    }

    
    double perimeter() {
        return 2 * (width + height);  
    }

   
    double area() {
        return width * height;  
    }

    static void comparePerimeter(Rectangle r1, Rectangle r2) {
        double p1 = r1.perimeter();  
        double p2 = r2.perimeter();  

        cout << "Rectangle 1 perimeter: " << p1 << endl;  
        cout << "Rectangle 2 perimeter: " << p2 << endl;  

        if (p1 > p2) {
            cout << "Rectangle 1 has a larger perimeter." << endl;
        }
        else if (p1 < p2) {
            cout << "Rectangle 2 has a larger perimeter." << endl;
        }
        else {
            cout << "Both rectangles have the same perimeter." << endl;
        }
    }

    static void compareArea(Rectangle r1, Rectangle r2) {
        double a1 = r1.area();  
        double a2 = r2.area();  
        cout << "Rectangle 1 area: " << a1 << endl;  
        cout << "Rectangle 2 area: " << a2 << endl;  
        if (a1 > a2) {
            cout << "Rectangle 1 has a larger area." << endl;
        }
        else if (a1 < a2) {
            cout << "Rectangle 2 has a larger area." << endl;
        }
        else {
            cout << "Both rectangles have the same area." << endl;
        }
    }
};

int main() 
{
    Rectangle rect1(5.0, 10.0);  
    Rectangle rect2(7.0, 8.0);   
    rect1.comparePerimeter(rect1, rect2);  
    cout << endl; 
    rect2.compareArea(rect1, rect2); 
    return 0;  
}
