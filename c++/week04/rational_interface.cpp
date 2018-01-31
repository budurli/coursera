#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

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
        if (numerator == 0) {
            denominator = 1;
        }

        if (numerator * denominator < 0) {
            numerator = (-1) * abs(numerator) ;
            denominator = abs(denominator);
        } else {
            numerator = abs(numerator);
            denominator = abs(denominator);
        }

        int _gcd = gcdr(abs(numerator), abs(denominator));
        numerator = numerator / _gcd;
        denominator = denominator / _gcd;
    };

};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
