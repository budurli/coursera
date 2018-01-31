#include <iostream>
#include <exception>
#include <sstream>
#include <cmath>
#include <string>
#include <map>
using namespace std;

class Rational {
public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int _numerator, int _denominator) {
        if (_denominator == 0) throw 1;

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

istream& operator>>(istream& stream, Rational& rational) {
    int _numerator = 0, _denominator = 0;
    char delimiter;
    if (stream && stream.peek() != EOF) {
        stream >> _numerator >> delimiter >> _denominator;
        if (delimiter == '/'){
            rational = {_numerator, _denominator};
        }
    }
    return stream;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int _numerator =  lhs.Numerator() * rhs.Numerator(),
        _denominator = rhs.Denominator() * lhs.Denominator();
    return Rational(_numerator, _denominator);
}


Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) throw 2;
    int _numerator =  lhs.Numerator() * rhs.Denominator(),
        _denominator = lhs.Denominator() * rhs.Numerator();
    return Rational(_numerator, _denominator);
}


int main() {
    try
    {
        Rational a, b;
        char ch;
        cin >> a >> ch >> b;
        if (ch == '+') cout << a + b;
        else if (ch == '-') cout << a - b;
        else if (ch == '*') cout << a * b;
        else cout << a / b;
    }
    catch (int f) { //ловим исключения по номеру
        if (f == 1) cout << "Invalid argument";
        else cout << "Division by zero";
    }
 
    return 0;
}