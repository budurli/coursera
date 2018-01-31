#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<string> split(string s)
{
    vector<string> result;
    std::smatch m;
    std::regex e("\\S+");

    while (std::regex_search (s,m,e)) {
        for (auto x:m) {
            result.push_back(x);
        }
        
        s = m.suffix().str();
    }

    return result;
}

void printWorriedCount(const vector<int>& q){
    int r = 0;
    for (int i : q) {
        if (i>0) r++;
    }
    cout << r << endl;
}


void printQueue(const vector<int>& q){
    int r = 0;
    for (int i : q) {
     cout << i << " ";   
    }
    cout << endl;
}


int main(int argc, char const *argv[])
{
    int n = 0;
    vector<int> queue;
    string command;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i){

        getline(cin, command);

        if (command == "WORRY_COUNT") {
            printWorriedCount(queue);
        } else {
            int count = stoi(split(command)[1]);
            command = split(command)[0];

            if (command == "WORRY") queue[count]++;
            if (command == "QUIET") queue[count]--;
            if (command == "COME") {
                queue.resize(queue.size() + count);
            }
        }
    }

    return 0;
}