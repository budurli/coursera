#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string input){
    string tmp(input.rbegin(), input.rend());

    if (input == tmp) {
        return true;
    }

    return false;
}