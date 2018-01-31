#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string input;

    string::size_type i = 0;
    cin >> input;

    i = input.find('f', 0);
    if (i == string::npos) {
        cout << "-2";
    } else {
        i = input.find('f', i+1);
        if (i == string::npos) {
            cout << "-1";
        } else {
            cout << i;
        }
    }

    return 0;
}