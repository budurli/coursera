#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if (b == 0) {
        cout << "Impossible";
    } else {
        cout << int (a / b);
    }
    return 0;
}
