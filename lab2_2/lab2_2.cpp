#include <iostream>
#include <cmath>

using namespace std;


struct nrComplex {
    float a; // Real part
    float b; // Imaginary part
};

float absoluteValue(float real) {
    if (real >= 0) {
        return real; 
    }
    else {
        return -real; 
    }
}

// Function to compute the absolute value of a complex number
float absoluteValue(nrComplex complex) {
    return sqrt(complex.a * complex.a + complex.b * complex.b);
}

int main() {
    
    float real = -7.5;
    cout << "Absolute value of real number " << real << ": " << absoluteValue(real) << endl;

   
    nrComplex complexNumber;
    complexNumber.a = 3.0;  // Real part
    complexNumber.b = 4.0;  // Imaginary part
    cout << "Absolute value of complex number (" << complexNumber.a << " + " << complexNumber.b << "i): "
        << absoluteValue(complexNumber) << endl;

    return 0;
}
