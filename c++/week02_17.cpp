#include <iostream>
#include <string>
#include <map>
#include <set>


using namespace std;


void addToDict(const string& word1, const string& word2, map<string, set<string>>& synonyms) {
    synonyms[word1].insert(word2);
    synonyms[word2].insert(word1);
}

void printCountForWord(const string& word, map<string, set<string>>& synonyms){
    cout << synonyms[word].size() << endl;
}

void checkInDict(const string& word1, const string& word2, map<string, set<string>>& synonyms) {
    if (synonyms[word1].find(word2) != synonyms[word1].end()){
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
}


int main(int argc, char const *argv[])
{
    int n;
    string operation_code;
    map<string, set<string>> synonyms;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> operation_code;

        if (operation_code == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            addToDict(word1, word2, synonyms);
        }

        if (operation_code == "COUNT"){
            string word;
            cin >> word;
            printCountForWord(word, synonyms);
        }

        if (operation_code == "CHECK"){
            string word1, word2;
            cin >> word1 >> word2;
            checkInDict(word1, word2, synonyms);
        }

    }
    return 0;
}