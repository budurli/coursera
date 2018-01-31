#include <iostream>

using namespace std;

int main() {
    float n, a, b, x, y, discount;
    
    cin >> n >> a >> b >> x >>y;
    if (n > b) {
        discount = y;
    } else if (n > a) {
        discount = x;
    } else {
        discount = 0.0;
    }

    cout << (n * (100.0-discount) / 100);

    return 0;
}
