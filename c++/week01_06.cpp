#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a,b;
    cin >> a >> b;
    a += (a % 2);
    b -= (b % 2);
    for (int i = a; i <= b; i+=2)
    {
        cout << i;
        if (i < b-1){
            cout << " ";
        }
    }
    return 0;
}