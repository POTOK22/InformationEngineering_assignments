#ifndef TESTHEADER_H
#define TESTHEADER_H
#pragma once

#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Student{

    string name;

    string surname;

    vector<int> grades;

    int final_score;

    double final_grade;

};

void fill_Student_Vector(std::vector<Student> &students);
int final_score(const vector<Student> &students, const int &i);
void fill_final_score(vector<Student> &students, const int &i);
double grade_based_on_score(const vector<Student> &students, const int &i);
void fill_final_grade(vector<Student> &students, const int &i);
bool by_final_grade(const Student &a, const Student &b);
void sorting_by_grade(vector<Student> &students);

#endif // TESTHEADER_H
