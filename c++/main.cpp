#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int> s = {4, 2, 1, 2};
    s.erase(2);
    s.insert(1);
    cout << s.size();
    return 0;
}