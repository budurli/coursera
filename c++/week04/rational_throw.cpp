#include <iostream>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int _numerator, int _denominator) {
        if (_denominator == 0) throw invalid_argument("invalid_argument");

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

private:
    int numerator = 0, denominator = 1;

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


Rational operator*(const Rational& lhs, const Rational& rhs) {
    int _numerator =  lhs.Numerator() * rhs.Numerator(),
        _denominator = rhs.Denominator() * lhs.Denominator();
    return Rational(_numerator, _denominator);
}


Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) throw domain_error("domain_error");
    int _numerator =  lhs.Numerator() * rhs.Denominator(),
        _denominator = lhs.Denominator() * rhs.Numerator();
    return Rational(_numerator, _denominator);
}


int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
