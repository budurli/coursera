#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> strings = {"", "", ""};
    cin >> strings[0] >> strings[1] >> strings[2];

    sort(strings.begin(), strings.end());
    cout << strings[0];

    return 0;
}