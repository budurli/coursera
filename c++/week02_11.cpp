#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string first, second;
        map<char, int> firstMap, secondMap;
        cin >> first >> second;
        for (char c : first){
            firstMap.count(c) ? firstMap[c]++ : firstMap[c] = 1;
        }

        for (char c : second){
            secondMap.count(c) ? secondMap[c]++ : secondMap[c] = 1;
        }

        (firstMap == secondMap) ? cout << "YES" : cout << "NO";
        cout << endl;

    }
    return 0;
}