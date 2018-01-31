#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


class ReversibleString {
public:
    ReversibleString() {
        _string = "";
    }
    ReversibleString(string _initial) {
        _string = _initial;
    }
    void Reverse() {
        reverse(begin(_string), end(_string));
    }
    string ToString() const {
        return _string;
    }
private:
    string _string;
};
