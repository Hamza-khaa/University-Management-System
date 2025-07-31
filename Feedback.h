#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Feedback {
    map<int, vector<string>> feedbacks;

public:
    void giveFeedback(int rollNo, const string& feedback) {
        feedbacks[rollNo].push_back(feedback);
        cout << "Feedback recorded for Roll No: " << rollNo << endl;
    }

    void displayFeedback(int rollNo) const {
        auto it = feedbacks.find(rollNo);
        if (it != feedbacks.end() && !it->second.empty()) {
            cout << "Feedback for Roll No: " << rollNo << ":\n";
            for (const auto& feedback : it->second)
                cout << "- " << feedback << endl;
        } else {
            cout << "No feedback available for Roll No: " << rollNo << endl;
        }
    }
};

#endif
