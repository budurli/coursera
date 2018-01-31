#include <string>
#include <iostream>
#include <vector>

using namespace std;

void ShiftMonth(int& index, const vector<int>& diy, vector<vector<string>>& tfd) {
    index++;
    if (index > 11)index = 0;
    vector<vector<string>> NewMonth = tfd;
    int a = tfd.size();
    int b = diy[index];
    tfd.resize(b);
    const int e = b - 1;
    if (a > b) {
        for (b; a > b; b++) {
            tfd[e].insert(end(tfd[e]),
                          begin(NewMonth[b]),
                          end(NewMonth[b]));
        }
    }
    NewMonth.clear();
}
void PrintTask(int day, const vector<vector<string>>& tfd) {
    cout << tfd[day - 1].size();
    for (auto i : tfd[day - 1]) {
        cout << " " << i;
    }
    cout << endl;
}
int main()
{
    int Q;
    cin >> Q;
    vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> taskList;
    int month = 0;
    taskList.resize(days_in_months[month], {});
    for (int i = 0; Q > i; i++) {
        string comand;
        int day;
        string task;
        cin >> comand;
        if (comand == "NEXT") {
            ShiftMonth(month, days_in_months, taskList);
        }
        else if (comand == "DUMP") {
            cin >> day;
            PrintTask(day, taskList);
        }
        else if (comand == "ADD") {
            cin >> day >> task;
            taskList[day - 1].push_back(task);
        }
    }
    return 0;
}