#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        firstNameChanges[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        lastNameChanges[year] = last_name;
    }
    string GetFullName(int year) {
        string first_name = "", last_name = "", result;
        for (auto f : firstNameChanges) {
            first_name = (f.first <= year) ? f.second : first_name;
        }

        for (auto l : lastNameChanges) {
            last_name = (l.first <= year) ? l.second : last_name;
        }

        if (first_name == "") {
            if (last_name == "") {
                return "Incognito";
            } else {
                return last_name + " with unknown first name";
            }

        } else {
            if (last_name == "") {
                return first_name + " with unknown last name";
            }
            else {
                return first_name + " " + last_name;
            }
        }

    }

    string GetFullNameWithHistory(int year) {
        string first_name, last_name, result;

        vector<string> first_name_history, last_name_history;

        for (auto f : firstNameChanges) {
            if (f.first <= year) {
                if ((first_name_history.size() == 0) || (first_name_history.back() != f.second)) {
                    first_name_history.push_back(f.second);
                }
            } else {
                break;
            }

        }

        for (auto l : lastNameChanges) {
            if (l.first <= year) {
                if ((last_name_history.size() == 0) || (last_name_history.back() != l.second)) {
                    last_name_history.push_back(l.second);
                }
            } else {
                break;
            }
        }

        reverse(begin(first_name_history), end(first_name_history));
        reverse(begin(last_name_history), end(last_name_history));


        first_name = formatNameString(first_name_history);
        last_name = formatNameString(last_name_history);


        if (first_name == "") {
            if (last_name == "") {
                return "Incognito";
            } else {
                return last_name + " with unknown first name";
            }

        } else {
            if (last_name == "") {
                return first_name + " with unknown last name";
            }
            else {
                return first_name + " " + last_name;
            }
        }
    }
private:
    string firstName, lastName;
    map<int, string> firstNameChanges, lastNameChanges;

    string formatNameString(const vector<string>& words) {
        string result = "";

        if (words.size() == 1) {
            result = words[0];
        }

        if (words.size() == 2) {
            result = words[0] + " (" + words[1] + ")";
        }

        if (words.size() > 2) {
            result = words[0] + " (" + words[1];
            for (int i = 2; i < words.size(); ++i)
            {
                result += ", " + words[i];
            }

            result += ")";
        }


        return result;

    }

};

