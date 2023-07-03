#include "test-header.h"

using namespace std;

int main()
{

    std::vector<Student> students;

    fill_Student_Vector(students);

    for(int i=0; i<students.size(); i++){
        fill_final_score(students, i);
        fill_final_grade(students, i);
        cout<<students[i].name<<" "<<students[i].surname<<" "<<final_score(students, i)<<
              " "<<students[i].final_score<<" "<<grade_based_on_score(students, i)<<
              " "<<students[i].final_grade<<endl;
    }
    cout<<endl;
    sorting_by_grade(students);
    for(auto &val : students){
        cout<<val.name<<" "<<val.surname<<" "<<val.final_grade<<endl;
    }
    fstream file;
    file.open("students_grades.txt", ios::in | ios::out | ios::trunc);

    if(file.is_open()){
        cout<<"students_grades.txt was opened correctly"<<endl;
        for(int i=0; i<students.size(); i++){
            file<<students[i].name<<" "<<students[i].surname<<" "<<
                  students[i].final_grade<<endl;
        }
        cout<<"writing into students_grades.txt ended"<<endl;

    }
    file.close();

    /*Student studencik;
    studencik.name="krzysiu";
    studencik.surname="krzysiowy";
    studencik.grades={1,3,4,5,6,3,10};
    cout<<studencik.name<<" "<<studencik.surname<<" "<<endl;
    for(auto &value : studencik.grades){
        cout<<value<<" ";
    }
    cout<<endl;*/

    return 0;


}
