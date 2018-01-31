#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void WriteToFile(const string& _input, const string& _output){
    ifstream input(_input);
    ofstream output(_output);

    if (input){
        string line;
        while (getline(input, line)){
            output << line << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    const string path = "input.txt";
    const string o_path = "output.txt";
    WriteToFile(path, o_path);
    return 0;
}