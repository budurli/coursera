#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;
    for (auto i : m) {
        result.insert(i.second);
    }

    return result;
}