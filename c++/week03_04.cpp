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
private:
    string firstName, lastName;
    map<int, string> firstNameChanges, lastNameChanges;

};



