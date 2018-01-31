#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a,b,c,d;

    cin >> a >> b >> c;
    d = sqrt(pow(b,2)-4 * a * c);
    if (a != 0) {
        if (d >0) {
            cout << ((-b-d)/(2*a)) << " "<<((-b+d)/(2*a));
        } else if (d == 0) {
            cout << ((-b-d)/(2*a));
        }
    } else if (b != 0) {
        cout << (-c/b);
    }

    return 0;
}