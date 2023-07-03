#include "header.h"

using namespace std;

void fill_Student_Vector(std::vector<Student> &students){
    std::fstream file;
    file.open("grades.txt", std::ios::in);
    std::string line;
    while(getline(file, line)){
        Student a;
        size_t pos;
        pos = line.find(',');
        a.name = line.substr(0, pos);
        line = line.substr(pos+1);
        pos = line.find(',');
        a.surname = line.substr(0, pos);
        line = line.substr(pos+1);
        for(int i = 0; i < 7; i++){
            pos = line.find(',');
            int b = std::stoi(line.substr(0, pos));
            a.grades.emplace_back(b);
            line = line.substr(pos+1);
        }
        students.emplace_back(a);
    }
}
double calculate_grade(const vector<Student> &student, const int &a){
    double sum = accumulate(student[a].grades.begin(), student[a].grades.end(), 0);
    double percentage = (sum/70.0)*100.0;
    if(percentage <= 50){
        return 2.25;
    }
    if(percentage > 51 && percentage < 61){
        return 3.25;
    }
    if(percentage > 61 && percentage < 71){
        return 3.5;
    }
    if(percentage > 71 && percentage < 81){
        return 4.25;
    }
    if(percentage > 81 && percentage < 91){
        return 4.5;
    }
    if(percentage > 91 && percentage <=100){
        return 5;
    }
    else {
        return 0;
    }
}

void fill_Students_Final_Grade(vector<Student> &students, const int &i, const double &grade){
    students[i].final_grade=grade;
}
bool compare_by_surname(const Student &a, const Student &b){
    return (a.surname<b.surname);
}
bool compare_by_grade(const Student &a, const Student &b){
    return (a.final_grade<b.final_grade);
}
void sort_students_by_grade(vector<Student> &students, const bool &a){
    if(a==true){
        sort(students.begin(), students.end(), compare_by_surname);
    }
    else{
        sort(students.begin(), students.end(), compare_by_grade);
    }
}
