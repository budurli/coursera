#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void PrintFile(const string& path) {
    ifstream input(path);

    if (input) {
        string line;
        while (getline(input, line)) {
            cout << fixed << setprecision(3) << stod(line) << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    const string path = "input.txt";
    PrintFile(path);
    return 0;
}