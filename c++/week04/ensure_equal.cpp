#include <string>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
    if (left != right) {
        string what = left + " != " + right;
        throw runtime_error(what);
    }
}