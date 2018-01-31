#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string word;
    set<string> words;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> word;
        words.insert(word);
    }

    cout << words.size() << endl;

}