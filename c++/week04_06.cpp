#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


void PrintTableFromFile(const string& path) {
    ifstream input(path);
    int n, m;
    if (input) {
        string line;
        getline(input, line, ' ');
        n = stod(line);
        getline(input, line);
        m = stod(line);

        while (input.good()) {
            for (int i = 0; i < m - 1; ++i)
            {
                getline(input, line, ',');
                cout << setw(10) << line << " ";
            }
            getline(input, line);
            cout << setw(10) <<  line << endl;


        }

    }

}


int main(int argc, char const *argv[])
{
    const string path = "input.txt";
    PrintTableFromFile(path);
    return 0;
}