#ifndef HEADER_H
#define HEADER_H
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <numeric>
#include <algorithm>

using namespace std;
/*structure definiton*/
struct Student{

    string name;

    string surname;

    vector<int> grades;

    double final_grade = 0;

};
/*function responsible for filling the vector with data from file*/
void fill_Student_Vector(std::vector<Student> &students);

/*function which calculate grade basing on points*/
double calculate_grade(const vector<Student> &student, const int &a);

/*function which is putting the result of calculate_grade into a vector with data*/
void fill_Students_Final_Grade(vector<Student> &students, const int &i, const double &grade);

/*simple boolean comparision of two elements from Student stucture*/
bool compare_by_surname(const Student &a, const Student &b);

/*here the same*/
bool compare_by_grade(const Student &a, const Student &b);

/*function resposible for sorting data*/
void sort_students_by_grade(vector<Student> &students, const bool &a);

#endif // HEADER_H
