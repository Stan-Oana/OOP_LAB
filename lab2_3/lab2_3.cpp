#include <iostream>
#include <stdexcept> // For exceptions

using namespace std;

// Function to solve the linear equation ax + b = 0
double solveEquation(double a, double b) {
    // Handle cases related to coefficients
    if (a == 0) {
        if (b == 0) {
            throw invalid_argument("The equation has infinitely many solutions.");
        }
        else {
            throw invalid_argument("The equation has no solution.");
        }
    }
    // Calculate the solution
    double result = -b / a;

    // Correct -0 to 0 if it occurs
    if (result == -0.0) {
        result = 0.0;
    }
    return result;
}

int main() {
    try {
        double a, b;

        // Input coefficients
        cout << "Enter coefficient a: ";
        cin >> a;
        cout << "Enter coefficient b: ";
        cin >> b;

        // Solve the equation
        double solution = solveEquation(a, b);
        cout << "The solution to the equation " << a << "x + " << b << " = 0 is: x = " << solution << endl;
    }
    catch (exception& e) {
        // Handle exceptions
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
