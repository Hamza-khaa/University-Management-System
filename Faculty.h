#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include "Course.h"
#include <vector>

class Faculty : public Person {
    static int facultyCount;
    string department;
    vector<Course> assignedCourses;

public:
    Faculty(string n = "Unknown", int a = 0, string dept = "Unknown")
        : Person(n, a), department(dept) { facultyCount++; }

    ~Faculty() {
        facultyCount--;
        cout << "Destructor called for Faculty: " << name << endl;
    }

    void assignCourse(const Course& course) {
        assignedCourses.push_back(course);
    }

    void display() const override {
        Person::display();
        cout << "Department: " << department << endl;
        if (!assignedCourses.empty()) {
            cout << "Assigned Courses:\n";
            for (const auto& course : assignedCourses)
                course.display();
        } else {
            cout << "No courses assigned.\n";
        }
    }

    static int getFacultyCount() { return facultyCount; }
};

int Faculty::facultyCount = 0;

#endif
