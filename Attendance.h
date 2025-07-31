#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <iostream>
#include <vector>
using namespace std;

class Attendance {
    vector<pair<int, int>> attendanceRecord;

    int findRollNumber(int rollNo) const {
        for (size_t i = 0; i < attendanceRecord.size(); ++i)
            if (attendanceRecord[i].first == rollNo)
                return i;
        return -1;
    }

public:
    void addRollNumber(int rollNo) {
        if (findRollNumber(rollNo) == -1) {
            attendanceRecord.emplace_back(rollNo, 0);
            cout << "Roll number " << rollNo << " has been added to the attendance system.\n";
        } else {
            cout << "Roll number " << rollNo << " already exists.\n";
        }
    }

    void markAttendance(int rollNo) {
        int index = findRollNumber(rollNo);
        if (index != -1) {
            attendanceRecord[index].second++;
            cout << "Attendance marked for Roll No: " << rollNo << endl;
        } else {
            cout << "Roll number " << rollNo << " does not exist.\n";
        }
    }

    void displayAttendance(int rollNo) const {
        int index = findRollNumber(rollNo);
        if (index != -1)
            cout << "Roll No: " << rollNo << ", Days Attended: " << attendanceRecord[index].second << endl;
        else
            cout << "No attendance record for Roll No: " << rollNo << endl;
    }
};

#endif
