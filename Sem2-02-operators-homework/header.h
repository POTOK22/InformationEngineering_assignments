#ifndef HEADER_H
#define HEADER_H
#pragma once

#include <iostream>

using namespace std;

class Time {
public:
    Time(int num=0);
    void set(int num); //setter
    int num() const; //getter
    void print () const;
    friend ostream &operator<<(ostream &str, Time &rhs);
    friend istream &operator>>(istream &str, Time &rhs);
    Time operator+(const Time &rhs) const;
    Time operator-(const Time &rhs) const;
    Time operator*(const Time &rhs) const;
    operator int();
private:
    int num_;
};

#endif // HEADER_H

