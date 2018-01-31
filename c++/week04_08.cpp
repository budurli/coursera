#include <iostream>

using namespace std;



class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int _numerator, int _denominator) {
        if (_numerator * _denominator < 0) {
            _numerator = (-1) * abs(_numerator) ;
            _denominator = abs(_denominator);
        } else {
            _numerator = abs(_numerator);
            _denominator = abs(_denominator);
        }

        if (_numerator == 0){
            _denominator = 1;
        }

        int _gcd = gcdr(_numerator, _denominator);

        numerator = _numerator / _gcd;
        denominator = _denominator / _gcd;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator, denominator;

    int gcdr ( int a, int b )
    {
        if ( a == 0 ) return b;
        return gcdr ( b % a, a );
    }

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
        const Rational r(-2, -3);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(-2, -3) != 2/3" << endl;
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