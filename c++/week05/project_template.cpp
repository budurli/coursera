#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Date {
public:
  Date() : year(1), month(1), day(1) {};
  Date(int y, int m, int d) {
    if (m < 1 || m > 12) throw runtime_error("Month value is invalid: " + to_string(m));
    if (d < 1 || d > 31) throw runtime_error("Day value is invalid: " + to_string(d));
    year = y;
    month = m;
    day = d;
  };

  int GetYear() const {
    return year;
  };
  int GetMonth() const {
    return month;
  };
  int GetDay() const {
    return day;
  };
  int ToInt() const {
    return year * 372 + month * 32 + day;
  }
private:
  int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  return (lhs.ToInt() < rhs.ToInt());
}


ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() << "-"
         << setw(2) << setfill('0') << date.GetMonth() << "-"
         << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

istream& operator>>(istream& stream, Date& date) {
  int year, month, day;
  char delimiter1, delimiter2;
  if (stream && stream.peek() != EOF) {
    stream >> year >> delimiter1 >> month >> delimiter2 >> day;
    if (delimiter1 == '-' && delimiter2 == '-') {
      date = {year, month, day};
    } else {
      throw runtime_error("Wrong date format: ");
    }
  }
  return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
    events[date].push_back(event);
    sort(begin(events[date]), end(events[date]));
  };

  bool DeleteEvent(const Date& date, const string& event) {
    if (events.find(date) != events.end()){ //date exists
      auto it = find(begin(events[date]), end(events[date]), event);
      if (it != events[date].end()){
        events[date].erase(it);
        return 1;
      }
    }
    return 0;
  };

  int  DeleteDate(const Date& date) {
    int result = 0;
    if (events.find(date) != events.end()) {
      result = events[date].size();
      events.erase(date);
    }
    return result;
  };

  vector<string> Find(const Date& date) const {
    vector<string> result = {};
    if (events.count(date) > 0) {
      result = events.at(date);
    } 
    return result;
  };

  void Print() const {
    for (auto s : events) {
      for (auto event : s.second) {
        cout << s.first << " " << event << endl;
      }
    }

  };
private:
  map<Date, vector<string>> events;
};

void ParseInputCommand(const string& input, Database& db) {
  stringstream s_input(input);
  string command, event;
  Date date;

  s_input >> command;

  if (command == "Add") {
    s_input >> date >> event;
    db.AddEvent(date, event);
  } else if (command == "Del") {
    s_input >> date;
    if (s_input && s_input.peek() != EOF) {
      s_input >> event;
      if (db.DeleteEvent(date, event)) {
        cout << "Deleted successfully" << endl;
      } else {
        cout << "Event not found" << endl;
      }
    } else {
      cout << "Deleted " << to_string(db.DeleteDate(date)) << " events" << endl;;
    }

  } else if (command == "Find") {
    s_input >> date;
    for (string event : db.Find(date)) {
      cout << event << endl;
    };
  } else if (command == "Print") {
    db.Print();
  } else throw runtime_error("Unknown command: " + command);
}


int main() {
  Database db;

  string input;
  while (getline(cin, input)) {
    try {
      if (!input.empty()) {
        ParseInputCommand(input, db);
      }
    } catch (exception& ex) {
      cout << ex.what() << endl;
      return 1;
    }

  }

  return 0;
}