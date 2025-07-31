#include "Student.h"
#include "Faculty.h"
#include "Course.h"
#include "Attendance.h"
#include "Library.h"
#include "Marks.h"
#include "Feedback.h"
#include "Menu.h"

int main() {
    vector<Student*> students;
    vector<Faculty*> faculties;
    Attendance attendance;
    Library library;
    Marks marks;
    Feedback feedback;

    vector<Course> courses = {
        {"Math 101", 101, 3},
        {"Physics 201", 201, 4},
        {"Chemistry 301", 301, 3},
        {"Biology 401", 401, 2},
    };

    int choice;
    do {
        Menu::showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, street, city, state, zip;
            int age, rollNo;
            float gpa;

            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter roll number: ";
            cin >> rollNo;
            cout << "Enter GPA: ";
            cin >> gpa;

            cout << "Please Enter your Address" << endl;
            cout << "Enter street: ";
            cin >> street;
            cout << "Enter city: ";
            cin >> city;
            cout << "Enter state: ";
            cin >> state;
            cout << "Enter ZIP code: ";
            cin >> zip;

            Address studentAddress(street, city, state, zip);
            Student* student = new Student(name, age, rollNo, gpa);
            student->setAddress(studentAddress);
            students.push_back(student);

            cout << "Student added successfully.\n";
            break;
        }

        case 2: {
            string name, department, street, city, state, zip;
            int age;

            cout << "Enter faculty name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter department: ";
            cin >> department;

            cout << "Please Enter your Address" << endl;
            cout << "Enter street: ";
            cin >> street;
            cout << "Enter city: ";
            cin >> city;
            cout << "Enter state: ";
            cin >> state;
            cout << "Enter ZIP code: ";
            cin >> zip;

            Address facultyAddress(street, city, state, zip);
            Faculty* faculty = new Faculty(name, age, department);
            faculty->setAddress(facultyAddress);
            faculties.push_back(faculty);

            cout << "Faculty added successfully.\n";
            break;
        }

        case 3: {
            int facultyIndex, courseIndex;
            cout << "Available Faculty:\n";
            for (int i = 0; i < faculties.size(); ++i) {
                cout << i + 1 << ". ";
                faculties[i]->display();
            }
            cout << "Select a faculty (enter index): ";
            cin >> facultyIndex;

            cout << "Available Courses:\n";
            for (int i = 0; i < courses.size(); ++i) {
                cout << i + 1 << ". ";
                courses[i].display();
            }
            cout << "Select a course (enter index): ";
            cin >> courseIndex;

            if (facultyIndex > 0 && facultyIndex <= faculties.size() &&
                courseIndex > 0 && courseIndex <= courses.size()) {
                faculties[facultyIndex - 1]->assignCourse(courses[courseIndex - 1]);
                cout << "Course assigned successfully.\n";
            } else {
                cout << "Invalid selection.\n";
            }
            break;
        }

        case 4: {
            int studentIndex, courseIndex;
            cout << "Available Students:\n";
            for (int i = 0; i < students.size(); ++i) {
                cout << i + 1 << ". ";
                students[i]->display();
            }
            cout << "Select a student (enter index): ";
            cin >> studentIndex;

            cout << "Available Courses:\n";
            for (int i = 0; i < courses.size(); ++i) {
                cout << i + 1 << ". ";
                courses[i].display();
            }
            cout << "Select a course (enter index): ";
            cin >> courseIndex;

            if (studentIndex > 0 && studentIndex <= students.size() &&
                courseIndex > 0 && courseIndex <= courses.size()) {
                students[studentIndex - 1]->enrollInCourse(courses[courseIndex - 1]);
                cout << "Student enrolled in course successfully.\n";
            } else {
                cout << "Invalid selection.\n";
            }
            break;
        }

        case 5: {
            int rollNo;
            cout << "Enter student roll number to mark attendance: ";
            cin >> rollNo;
            attendance.markAttendance(rollNo);
            attendance.displayAttendance(rollNo);
            break;
        }

        case 6: {
            int rollNo;
            string bookName;
            cout << "Enter student roll number: ";
            cin >> rollNo;
            cout << "Enter book name: ";
            cin >> bookName;
            library.issueBook(rollNo, bookName);
            break;
        }

        case 7: {
            int rollNo, numSubjects;
            vector<float> marksList;
            cout << "Enter student roll number: ";
            cin >> rollNo;
            cout << "Enter number of subjects: ";
            cin >> numSubjects;
            cout << "Enter marks for " << numSubjects << " subjects:\n";
            for (int i = 0; i < numSubjects; ++i) {
                float mark;
                cin >> mark;
                marksList.push_back(mark);
            }
            marks.addMarks(rollNo, marksList);
            cout << "Marks added successfully.\n";
            break;
        }

        case 8: {
            int rollNo;
            cout << "Enter student roll number: ";
            cin >> rollNo;
            bool found = false;
            for (const auto& student : students) {
                if (student->getRollNo() == rollNo) {
                    student->display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Student with Roll No: " << rollNo << " not found.\n";
            break;
        }

        case 9: {
            int rollNo;
            cout << "Enter student roll number to calculate CGPA and grade: ";
            cin >> rollNo;
            marks.calculateCGPA(rollNo);
            break;
        }

        case 10: {
            int rollNo;
            string feedbackText;
            cout << "Enter student roll number: ";
            cin >> rollNo;
            cout << "Enter feedback: ";
            cin >> feedbackText;
            feedback.giveFeedback(rollNo, feedbackText);
            break;
        }

        case 11: {
            int rollNo;
            cout << "Enter student roll number to display feedback: ";
            cin >> rollNo;
            feedback.displayFeedback(rollNo);
            break;
        }

        case 12:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 12);

    for (auto student : students) delete student;
    for (auto faculty : faculties) delete faculty;

    return 0;
}
