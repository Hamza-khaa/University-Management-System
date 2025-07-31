#ifndef MARKS_H
#define MARKS_H

#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

class Marks {
    map<int, vector<float>> marksRecord;
    map<int, string> grades;

    string calculateGrade(float percentage) const {
        if (percentage >= 90) return "A";
        else if (percentage >= 80) return "B";
        else if (percentage >= 70) return "C";
        else if (percentage >= 60) return "D";
        return "F";
    }

public:
    void addRollNumber(int rollNo) {
        if (marksRecord.find(rollNo) == marksRecord.end()) {
            marksRecord[rollNo] = {};
            cout << "Roll number " << rollNo << " has been added.\n";
        } else {
            cout << "Roll number " << rollNo << " already exists.\n";
        }
    }

    void addMarks(int rollNo, const vector<float>& marks) {
        if (marksRecord.find(rollNo) != marksRecord.end()) {
            marksRecord[rollNo] = marks;
            float total = 0;
            for (float mark : marks)
                total += mark;
            float percentage = total / marks.size();
            grades[rollNo] = calculateGrade(percentage);
            cout << "Marks and grade added for Roll No: " << rollNo << endl;
        } else {
            cout << "Roll number " << rollNo << " does not exist.\n";
        }
    }

    void calculateCGPA(int rollNo) const {
        auto it = marksRecord.find(rollNo);
        if (it != marksRecord.end() && !it->second.empty()) {
            float total = 0;
            for (float mark : it->second)
                total += mark;
            float cgpa = total / it->second.size() / 25.0f;
            cout << "Roll No: " << rollNo << ", CGPA: " << fixed << setprecision(2) << cgpa << endl;
            cout << "Grade: " << grades.at(rollNo) << endl;
        } else {
            cout << "No marks available for Roll No: " << rollNo << endl;
        }
    }
};

#endif
