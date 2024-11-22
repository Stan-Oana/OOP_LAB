#include <iostream>
#include <cmath>  
using namespace std;

struct QuadraticEquation {
    double a, b, c; 

    // Function to solve the quadratic equation
    void solve() {
        // Calculate 
        double delta = b * b - 4 * a * c;
        if( delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "The equation has two real solutions: " << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (delta == 0) {
            // One real solution 
            double x = -b / (2 * a);
            cout << "The equation has one real solution: " << endl;
            cout << "x = " << x << endl;
        }
        else {
            // Complex solutions
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-delta) / (2 * a);
            cout << "The equation has two complex solutions: " << endl;
            cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
};

int main() {
    QuadraticEquation eq;
    cout << "Enter coefficients a, b, and c of the quadratic equation (ax^2 + bx + c = 0): " << endl;
    cout << "a = ";
    cin >> eq.a;
    cout << "b = ";
    cin >> eq.b;
    cout << "c = ";
    cin >> eq.c;

    if (eq.a == 0) {
        cout << "This is not a quadratic equation (a cannot be zero)." << endl;
    }
    else {
        eq.solve();
    }

    return 0;
}
