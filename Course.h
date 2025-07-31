#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course {
    string courseName;
    int courseCode, credits;

public:
    Course(string name = "Unknown", int code = 0, int cr = 0)
        : courseName(name), courseCode(code), credits(cr) {}

    void display() const {
        cout << "Course Name: " << courseName << ", Code: " << courseCode << ", Credits: " << credits << endl;
    }

    string getName() const { return courseName; }
    int getCode() const { return courseCode; }
    int getCredits() const { return credits; }
};

#endif
