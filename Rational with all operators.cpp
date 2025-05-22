#include <iostream>
#include <cmath>  // For abs()
using namespace std;

class Rational {
private:
    int num;
    int den;

    // ? Manually Implement GCD Function (Works in All C++ Versions)
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to simplify the fraction
    void simplify() {
        int divisor = gcd(abs(num), abs(den)); // Use custom GCD function
        num /= divisor;
        den /= divisor;
        if (den < 0) { // Ensure denominator is always positive
            num = -num;
            den = -den;
        }
    }

public:
    // Constructor
    Rational(int n = 0, int d = 1) : num(n), den(d) { 
        if (den == 0) {
            cerr << "Error: Denominator cannot be zero! Setting to 1.\n";
            den = 1;
        }
        simplify(); 
    }

    // Display function
    void display() const { cout << num << "/" << den << endl; }

    // Arithmetic Operators
    Rational operator+(const Rational& r) const {
        return Rational(num * r.den + r.num * den, den * r.den);
    }

    Rational operator-(const Rational& r) const {
        return Rational(num * r.den - r.num * den, den * r.den);
    }

    Rational operator*(const Rational& r) const {
        return Rational(num * r.num, den * r.den);
    }

    Rational operator/(const Rational& r) const {
        if (r.den == 0) {
            cerr << "Error: Division by zero!\n";
            return *this;
        }
        return Rational(num * r.den, den * r.num);
    }

    // Overloaded output stream operator
    friend ostream& operator<<(ostream& out, const Rational& r) {
        out << r.num << "/" << r.den;
        return out;
    }
};

int main() {
    Rational r1(8, 12), r2(3, 4);
    
    cout << "r1: " << r1 << endl; // Should be simplified to 2/3
    cout << "r2: " << r2 << endl;

    cout << "r1 + r2 = " << (r1 + r2) << endl;
    cout << "r1 - r2 = " << (r1 - r2) << endl;
    cout << "r1 * r2 = " << (r1 * r2) << endl;
    cout << "r1 / r2 = " << (r1 / r2) << endl;

    return 0;
}

