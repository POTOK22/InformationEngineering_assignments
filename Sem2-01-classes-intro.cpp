#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student{
public:
    Student(){}

    Student(string n, string s, vector<float> g){
        name = n;
        surname = s;
        grades = g;
    }

    void set_name(string n){    //setter
        name = n;
    }
    void set_surname(string m){ //setter
        surname = m;
    }
    void set_album_num(string i){   //setter
        if (i.size()>=5 && i.size()<=6){
            album_num = i;
        }
    }

    string get_name(){  //getter
        return name;
    }

    string get_surname(){ //getters
        return surname;
    }

    string get_album_num(){ //getter
        return album_num;
    }

    /*method - function inside a structure*/
    float calculate_mean_grade(){
        cout<<"calculating grade for "<<name<<endl;
        float sum=accumulate(grades.begin(), grades.end(), 0.0f);
        return sum/grades.size();
    }

    bool add_grade(float grade){
        if(grade >= 2.0 && grade <= 5.0){
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    void pass_check(Student){
        int counter=0;
        for(auto &val : grades){
            if(val==2){
                counter++;
            }
        }
        if(counter<=1){
            cout<<"student passed semester"<<endl;
        }
        else{
            cout<<"student failed semester"<<endl;
        }
    }

private:
    string name;
    string surname;
    string album_num;
    vector<float> grades;
};

class Complex{
public:
    Complex(){};

    Complex(float a, float b){
        real_part = a;
        imaginary_part = b;
    }
    Complex(float a){
        real_part=a;
    }

    void set_real(float n){ //real value setter
        real_part = n;
    }

    void set_imaginary(float m){ //imaginary value setter
        imaginary_part = m;
    }

    float get_real(){
        return real_part;
    }

    float get_imaginary(){
        return imaginary_part;
    }

    void add(Complex a){
        real_part+=a.real_part;
        imaginary_part+=a.imaginary_part;
    }

    void print(Complex){
        cout<<real_part<<imaginary_part<<"i"<<endl;
    }

private:
    float real_part;
    float imaginary_part;
};

int main()
{
    Student student;

    student.set_name("Nathan");
    student.set_surname("Drake");
    student.set_album_num("155311");
    cout<<"student name, surname and album number is "<<student.get_name()<<" "<<student.get_surname()<<
          " "<<student.get_album_num()<<endl;
//    Student student2{"iman", "es", {0.0,1.1}};
//    student.add_grade(2.0);
    student.add_grade(2.0);
    student.add_grade(5.0);
    student.add_grade(4.5);

    float ave = student.calculate_mean_grade();

    cout<<"average grade is "<<ave<<endl;
    student.pass_check(student);

//    Complex complex={3,-4};
//    Complex complex2={7,-9};
    Complex a(1.0, -2.0);
    Complex b(3.14);

//    complex.print(complex);
//    complex2.print(complex);

    b.set_imaginary(-5);
    a.add(b);

    a.print(a);
    b.print(b);

    return 0;
}
