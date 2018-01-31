#include <iostream>
using namespace std;

class Rational {
public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int _numerator, int _denominator) {
        numerator = _numerator;
        denominator = _denominator;
        this->simplify();
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }
    void SetNumerator(int _numerator) {
        numerator = _numerator;
        this->simplify();
    }

    void SetDenomerator(int _denominator) {
        denominator = _denominator;
        this->simplify();
    }

private:
    int numerator = 0, denominator = 0;

    int gcdr ( int a, int b )
    {
        if ( a == 0 ) return b;
        return gcdr ( b % a, a );
    }

    int lcm(int a, int b) {
        return abs(a * b) / gcdr(a, b);
    }

    void simplify() {
        int sign = 1;

        if (numerator == 0) {
            denominator = 1;
        }

        if (numerator < 0) sign *= -1;
        if (denominator < 0) sign *= -1;
        
        numerator = abs(numerator);
        denominator = abs(denominator);

        int _gcd = gcdr(numerator, denominator);
        numerator = sign * numerator / _gcd;
        denominator = denominator / _gcd;
    };

};

// Реализуйте для класса Rational операторы ==, + и -

bool operator == (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

// Реализуйте для класса Rational операторы * и /

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int _numerator =  lhs.Numerator() * rhs.Numerator(),
        _denominator = rhs.Denominator() * lhs.Denominator();
    return Rational(_numerator, _denominator);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int _numerator =  lhs.Numerator() * rhs.Denominator(),
        _denominator = lhs.Denominator() * rhs.Numerator();
    return Rational(_numerator, _denominator);
}




int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
