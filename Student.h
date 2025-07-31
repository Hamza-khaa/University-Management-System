#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"
#include <vector>

class Student : public Person {
    static int studentCount;
    int rollNo;
    float GPA;
    vector<Course> courses;

public:
    Student(string n = "Unknown", int a = 0, int r = 0, float g = 0.0f)
        : Person(n, a), rollNo(r), GPA(g) { studentCount++; }

    ~Student() {
        studentCount--;
        cout << "Destructor called for Student: " << name << endl;
    }

    void enrollInCourse(const Course& course) {
        courses.push_back(course);
    }

    void display() const override {
        Person::display();
        cout << "Roll No: " << rollNo << ", GPA: " << GPA << endl;
        if (!courses.empty()) {
            cout << "Enrolled Courses:\n";
            for (const auto& course : courses)
                course.display();
        } else {
            cout << "No courses enrolled.\n";
        }
    }

    int getRollNo() const { return rollNo; }
    void setGPA(float g) { GPA = g; }
    static int getStudentCount() { return studentCount; }
};

int Student::studentCount = 0;

#endif
