#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


string toLower(string word){
    transform(word.begin(), word.end(), word.begin(),::tolower);
    return word;
}


int main(int argc, char const *argv[])
{
    int n = 0;
    vector<string> words;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {   
        string next_word;
        cin >> next_word;
        words.push_back(next_word);
    }

    sort(begin(words), end(words), [](string x, string y){ return toLower(x) < toLower(y);});
    for (string& i : words){
        cout << i << " ";
    }

    return 0;
    return 0;
}