#include <iostream>
#include <string>
#include <vector>


using namespace std;


struct Student {
    string Name;
    string Lastname;
    unsigned long int day, month, year;
};


void PrintStudentsName(int i, const vector<Student>& students) {
    Student student = students[i];
    cout << student.Name << " " << student.Lastname << endl;
}

void PrintStudentsDate(int i, const vector<Student>& students) {
    Student student = students[i];
    cout << student.day << "." << student.month << "." << student.year << endl;
}

int main(int argc, char const *argv[])
{
    vector<Student> students;
    int n, m;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string name, lastname;
        unsigned long int day, month, year;
        cin >> name >> lastname >> day >> month >> year;
        students.push_back({name, lastname, day, month, year});
    }


    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string command;
        int number;
        cin >> command >> number;
        if (students.size() < number || number <= 0) {
            cout << "bad request" << endl;
        } else if (command == "name") {
            PrintStudentsName(number - 1, students);

        } else if (command == "date") {
            PrintStudentsDate(number - 1, students);

        } else {
            cout << "bad request" << endl;
        }

    }

    return 0;
}