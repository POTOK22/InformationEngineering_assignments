#include "test-header.h"

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
int final_score(const vector<Student> &students, const int &i){
    int sum=accumulate(students[i].grades.begin(), students[i].grades.end(), 0);
    return sum;
}
void fill_final_score(vector<Student> &students, const int &i){
    students[i].final_score=final_score(students, i);
}
double grade_based_on_score(const vector<Student> &students, const int &i){
    if(students[i].final_score<=50){
        return 2.0;
    }
    else if(students[i].final_score>50 && students[i].final_score<=60){
        return 3.0;
    }
    else if(students[i].final_score>60 && students[i].final_score<=70){
        return 3.5;
    }
    else if(students[i].final_score>70 && students[i].final_score<=80){
        return 4.0;
    }
    else if(students[i].final_score>80 && students[i].final_score<=90){
        return 4.5;
    }
    else{
        return 5.0;
    }
}
void fill_final_grade(vector<Student> &students, const int &i){
    students[i].final_grade=grade_based_on_score(students, i);
}
bool by_final_grade(const Student &a, const Student &b){
    return (a.final_grade>b.final_grade);
}
void sorting_by_grade(vector<Student> &students){
    sort(students.begin(), students.end(), by_final_grade);
}
