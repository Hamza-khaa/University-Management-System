#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

class Menu {
public:
    static void showMainMenu() {
        cout << "\nUniversity Management System Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Add Faculty\n";
        cout << "3. Assign Course to Faculty\n";
        cout << "4. Enroll Student in Course\n";
        cout << "5. Mark Attendance\n";
        cout << "6. Issue Book\n";
        cout << "7. Add Marks\n";
        cout << "8. Display Student Info\n";
        cout << "9. Calculate CGPA and Grade\n";
        cout << "10. Give Feedback\n";
        cout << "11. Display Feedback\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
    }
};

#endif
