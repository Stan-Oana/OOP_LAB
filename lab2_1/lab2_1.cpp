#include <iostream>
#include <string>

using namespace std;

// Check if a string is a valid number
bool isValidNumber(string str) {
    bool hasDecimal = false;
    for (char c : str) {
        if (c == '.') {
            if (hasDecimal) return false; // More than one decimal point
            hasDecimal = true;
        }
        else if (c < '0' || c > '9') {
            return false; // Non-numeric character
        }
    }
    return !str.empty(); // Ensure the string is not empty
}

// Calculate area of a rectangle or square
double calculateArea(double length, double width = 0) {
    if (width == 0) return length * length; // Area of a square
    return length * width; // Area of a rectangle
}

int main() {
    string lengthStr, widthStr;

    // Input length
    cout << "Enter the length: ";
    cin >> lengthStr;
    if (!isValidNumber(lengthStr)) {
        cout << "Error: Invalid length input." << endl;
        return 1;
    }
    double length = stod(lengthStr);

    // Check if square
    cout << "Is this a square (yes/no)? ";
    string response;
    cin >> response;

    if (response == "yes" || response == "y") {
        // Calculate square area
        double area = calculateArea(length);
        cout << "Area: " << area << endl;
    }
    else {
        // Input width for rectangle
        cout << "Enter the width: ";
        cin >> widthStr;
        if (!isValidNumber(widthStr)) {
            cout << "Error: Invalid width input." << endl;
            return 1;
        }
        double width = stod(widthStr);

        // Calculate rectangle area
        double area = calculateArea(length, width);
        cout << "Area: " << area << endl;
    }

    return 0;
}
