#include <iostream>

using namespace std;

struct Specialization {
    string value;
    explicit Specialization(string v) {
        value = v;
    }
};

struct Course {
    string value;
    explicit Course(string v) {
        value = v;
    }

};

struct Week {
    string value;
    explicit Week(string v) {
        value = v;
    }

};


struct LectureTitle {

    string specialization;
    string course;
    string week;

    explicit LectureTitle(Specialization s, Course c, Week w) {
        specialization = s.value;
        course = c.value;
        week = w.value;
    }


};


