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

Rational operator+(const Rational& lhs, const Rational& rhs) {
    const int _numerator =  lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        _denominator = rhs.Denominator() * lhs.Denominator();
        return {_numerator, _denominator};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    const int _numerator =  lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        _denominator = rhs.Denominator() * lhs.Denominator();
    return {_numerator, _denominator};
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
