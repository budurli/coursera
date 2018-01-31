#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <set>

using namespace std;

void WrongChar(stringstream& ss, const string& str, const char& a) {
    if (ss.peek() != a) {
        string error = "Wrong date format: " + str;
        throw invalid_argument(error);
    }
    ss.ignore(1);
}

void WrongDateFormat(const string& str) {
    stringstream ss(str);
    int y = 0;
    int m = 0;
    int d = 0;
    ss >> y;
    WrongChar(ss, str, '-');
    ss >> m;
    if (m < 1 || m > 12) {
        string error = "Month value is invalid: " + to_string(m);
        throw runtime_error(error);
    }
    WrongChar(ss, str, '-');
    ss >> d;
    if (d < 1 || d > 31) {
        string error = "Day value is invalid: " + to_string(d);
        throw runtime_error(error);
    }
    const char& a = str[str.size() - 1];
    if (int(a) < 47 || int(a) > 58) {
        string error = "Wrong date format: " + str;
        throw invalid_argument(error);
    }
}

class Date {
public:
    Date(const string& input_string) {
        WrongDateFormat(input_string);
        stringstream ss;
        ss << input_string;
        ss >> year;
        ss.ignore(1);
        ss >> month;
        ss.ignore(1);
        ss >> day;
        stringstream ss2;
        ss2 << setw(4) << setfill('0') << to_string(year) << "-"
            << setw(2) << setfill('0') << to_string(month) << "-"
            << setw(2) << setfill('0') << to_string(day);
        ss2 >> date;
    }

    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }

    int ToInt() const {
        return year * 372 + month * 32 + day;
    }

    string GetDate() const {
        return date;
    }
private:
    int year = 0;
    int month = 1;
    int day = 1;
    string date = "0000-01-01";
};

bool operator<(const Date& lhs, const Date& rhs) {
    return lhs.ToInt() < rhs.ToInt();

}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        vector<string>& tmp = database[date];
        bool flag = true;
        for (const auto& item : tmp) {
            if (item == event) {
                flag = false;
            }
        }
        if (flag) {
            tmp.push_back(event);
            sort(begin(tmp), end(tmp));
        }
    }

    bool DeleteEvent(const Date& date, const string& event) {
        vector<string>& tmp = database[date];
        vector<string> duplicate;
        for (size_t i = 0; i < tmp.size(); ++i) {
            if (tmp[i] != event) {
                duplicate.push_back(tmp[i]);
            }
        }
        if (tmp.size() > duplicate.size()) {
            tmp.clear();
            tmp = duplicate;
            return true;
        }
        return false;
    }

    int  DeleteDate(const Date& date) {

        int count = 0;
        if (database.count(date) == 0) {
            return 0;
        } else {
            count = database[date].size();
        }
        database.erase(date);
        return count;
    }

    void Find(const Date& date) const {
        vector<string> tmp;
        if (database.count(date) > 0) {
            tmp = database.at(date);
        }
        for (const auto& a : tmp) {
            cout << a << endl;
        }
    }

    void Print() const {
        for (const auto& date : database) {
            for (const auto& event : date.second) {
                cout << date.first.GetDate() << " "
                     << event << endl;
            }
        }
    }
private:
    map<Date, vector<string>> database;
};
void CommandParse(const string & command, Database & db) {
    stringstream ss;
    ss << command;
    string cmd;
    ss >> cmd;
    if (cmd == "Add") {
        string date, event;
        ss >> date >> event;
        WrongDateFormat(date);
        if (event == "") {
            string error = "Wrong date format: " + date;
            throw invalid_argument(error);
        }
        db.AddEvent({date}, event);
    } else if (cmd == "Print") {
        db.Print();
    } else if (cmd == "Find") {
        string date;
        ss >> date;
        db.Find(date);
    } else if (cmd == "Del") {
        string date, event;
        ss >> date >> event;
        if (event == "") {
            int n = db.DeleteDate(date);
            cout << "Deleted " << n << " events" << endl;
        } else {
            if (db.DeleteEvent(date, event)) {
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Event not found" << endl;
            }
        }
    } else if (cmd == "") {

    } else {
        string error = "Unknown command: " + cmd;
        throw runtime_error(error);
    }
}

int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        if (command == "Stop") {
            break;
        }
        try {
            CommandParse(command, db);
        }
        catch (exception& ex) {
            cout << ex.what() << endl;
        }
    }

    return 0;
}