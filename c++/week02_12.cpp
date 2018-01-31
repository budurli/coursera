#include <iostream>
#include <string>
#include <map>

using namespace std;

void changeCapital(const string& country, const string& new_capital, map<string, string>& capitals) {
    if (capitals.count(country) == 0) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    } else {
        if (capitals[country] == new_capital) {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        } else {
            cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << new_capital << endl;
        }
    }

    capitals[country] = new_capital;

}

void renameCountry(const string& old_country_name, const string& new_country_name, map<string, string>& capitals) {
    if ((old_country_name == new_country_name) || (capitals.count(old_country_name) == 0) || (capitals.count(new_country_name) > 0)) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        cout << "Country " << old_country_name << " with capital " << capitals[old_country_name] << " has been renamed to " << new_country_name << endl;
        capitals[new_country_name] = capitals[old_country_name];
        capitals.erase(old_country_name);
    }

}

void printCountryInfo(const string& country, map<string, string>& capitals) {
    if (capitals.count(country) > 0) {
        cout << "Country " << country << " has capital " << capitals[country] << endl;
    } else {
        cout << "Country " << country << " doesn't exist" << endl;
    }

}

void printAllCountries(const map<string, string>& capitals) {
    if (capitals.size() > 0) {
        for (auto const& c : capitals) {
            cout << c.first << "/" << c.second << " ";
        }

    } else {
        cout << "There are no countries in the world";
    }

    cout << endl;

}

int main(int argc, char const *argv[])
{
    int n = 0;
    map<string, string> capitals;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            changeCapital(country, new_capital, capitals);

        } else if (operation_code == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            renameCountry(old_country_name, new_country_name, capitals);

        } else if (operation_code == "ABOUT") {
            string country;
            cin >> country;
            printCountryInfo(country, capitals);

        } else if (operation_code == "DUMP") {
            printAllCountries(capitals);
        }

    }
    return 0;
}