#include <iostream>
#include <sstream>
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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
