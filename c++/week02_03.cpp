#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string input){
    string tmp(input.rbegin(), input.rend());

    if (input == tmp) {
        return true;
    }

    return false;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> result;
    for (auto c: words){
        if ((IsPalindrom(c)) & (c.length() >= minLength)){
            result.push_back(c);
        }
    }

    return result;
}