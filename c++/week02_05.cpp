#include <iostream>
using namespace std;


void UpdateIfGreater(int first, int& second){
    if (first > second) {
        second = first;
    }
}

int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 1;
    UpdateIfGreater(a, b);
    cout << b << endl;
    return 0;
}
