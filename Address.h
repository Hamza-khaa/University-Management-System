#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address {
    string street, city, state, zip;

public:
    Address(string s = "Unknown", string c = "Unknown", string st = "Unknown", string z = "00000")
        : street(s), city(c), state(st), zip(z) {}

    void setAddress(string s, string c, string st, string z) {
        street = s; city = c; state = st; zip = z;
    }

    void display() const {
        cout << "Address: " << street << ", " << city << ", " << state << ", ZIP: " << zip << endl;
    }
};

#endif
