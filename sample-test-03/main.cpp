#include "header.h"

using namespace std;

int main()
{
    /*vector of structure Student*/
    std::vector<Student> students;

    /*function which filling vector with data*/
    fill_Student_Vector(students);

    /*loop where grade is calculated and putted into vector students*/
    for(int i = 0; i<students.size(); i++){
        double grade = calculate_grade(students, i);
        fill_Students_Final_Grade(students, i, grade);
        cout<<students[i].name<<"  "<<students[i].surname<<" "<<grade<<" "<<students[i].final_grade<<endl;
    }

    cout<<endl;
    bool sort_by_grade=true;
    sort_students_by_grade(students, sort_by_grade);
    for(auto &value : students){
        cout<<value.name<<" "<<" "<<value.surname<<" "<<value.final_grade<<endl;
    }
    return 0;


}
