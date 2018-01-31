#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator == (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

bool operator< (const Rational& lhs, const Rational& rhs) {
    const int r = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    if (r < 0)
    {
        return 1;
    }

    return 0;
};

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};

        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational> {{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[ {1, 2}];
        ++count[ {1, 2}];

        ++count[ {2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
