#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Library {
    map<int, vector<string>> issuedBooks;

public:
    void issueBook(int rollNo, const string& bookName) {
        issuedBooks[rollNo].push_back(bookName);
        cout << "Book \"" << bookName << "\" issued to Roll No: " << rollNo << endl;
    }

    void displayIssuedBooks(int rollNo) const {
        auto it = issuedBooks.find(rollNo);
        if (it != issuedBooks.end() && !it->second.empty()) {
            cout << "Books issued to Roll No: " << rollNo << ": ";
            for (const auto& book : it->second)
                cout << book << ", ";
            cout << endl;
        } else {
            cout << "No books issued to Roll No: " << rollNo << endl;
        }
    }
};

#endif
