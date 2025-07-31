#ifndef PERSON_H
#define PERSON_H

#include "Address.h"

class Person {
protected:
    string name;
    int age;
    Address address;

public:
    Person(string n = "Unknown", int a = 0) : name(n), age(a), address() {}

    virtual ~Person() {
        cout << "Destructor called for Person: " << name << endl;
    }

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
        address.display();
    }

    void setAddress(const Address& addr) {
        address = addr;
    }
};

#endif
