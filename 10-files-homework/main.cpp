#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

struct Student{
    string name;
    string surname;
    double grade;
};

/*function return vector<string>*/
vector<string> separate(string str){
    /*vector with separeted elements*/
    vector<string> toreturn;
    /*string where the data will be saved*/
    string w = "";

    /*loop which saves data into w as long
     * as there is no ',' or' '*/
    for(auto x : str){
        if(x==',' || x==' '){
            /*if there is to read ',' or ' '
              store element into vector*/
            toreturn.push_back(w);

            /*set w to empty*/
            w="";
        }
        else{
            /*add single char to string*/
            w=w+x;
        }
    }
    /*at the end of line there is nothing so data from
    last word is never stored to vector so it must be
    stored at the end of function*/
    toreturn.push_back(w);
    return toreturn;
}

int main()
{
    vector<string> vec1;
    fstream file;
    file.open("text.txt", ios::in);
    if(file.is_open()){
        cout<<"text.txt was correctly opened"<<endl;
    }
    /*printing out data normally with spaces*/
    /*while(!file.eof()){
        string line;
        getline(file, line);
        cout<<line;
    }*/

    /*printing out data in a continous block(without spaces)*/
    /*while(!file.eof()){
        char letter;
        file>>letter;
        cout<<letter;
    }*/

    /*writing down data from file into vector*/
    while(!file.eof()){
        string line;
        file>>line;
        vec1.emplace_back(line);
    }
    for(auto &value : vec1){
        cout<<value<<" ";
    }
    cout<<"\nreading from text.txt ended"<<endl;
    /*printing out data from vector in reverse order
      using reverse iterator*/
    /*for(auto it=vec1.rbegin(); it!=vec1.rend(); it++){
        cout<<*it<<endl;
    }*/

    file.close();

    /*IT MUST BE OFSTREAM FSTREAM IS NOT WORKING*/
    /*ofstream - default writing stream - writing to file*/
    ofstream myfile;
    myfile.open("new.txt", ios::trunc);

    if(myfile.is_open()){
        cout<<"new.txt was correctly opened"<<endl;

        /*defining a vector iterator manually*/
        vector<string>::iterator itr;

        /*simple for loop where the beginning is
         the end and vice versa*/
        for(itr=vec1.end(); itr!=vec1.begin(); itr--){
            myfile<<*itr<<endl;
        }
        cout<<"writing to new.txt ended"<<endl;
    }

    myfile.close();

    vector<Student> students;

    /*ifstream - default reading stream - reading from file*/
    ifstream fileStudents;
    fileStudents.open("students.txt");

    if(fileStudents.is_open()){
        cout<<"student.txt was opened correctly"<<endl;
        string line;
        int i = 0;

        /*work until lines are readed from file*/
        while(getline(fileStudents, line)){
            /*declaring a new vector of string el which is equal
            to function separate*/
            vector<string> el = separate(line);
            /*declaring a new Student stucture temp*/
            Student temp;
            /*every element of temp is equal to every element of el*/
            temp.name=el[0];
            temp.surname=el[1];
            /*special case - if there is more than one value in last
            element there is a way how to put in into a vector inside
            the struct Student*/
            /*for(int i=2; i<el.size(); i++){
                temp.grade.push_back(stod(el[i]));
            }*/
            /*there is a standard way to store element of vector el
            into vector of struct Student students but the value of
            this element must be converted into double*/
            temp.grade=stod(el[2]);
            students.emplace_back(temp);
        }
        cout<<"reading from student.txt ended"<<endl;
    }
    cout<<students[0].grade;

    /*cout<<"oceny "<<students[0].name<<endl;
    for(int i = 0; i<students[0].grade.size(); i++){
        cout<<students[0].grade[i]<<endl;
    }*/

    fileStudents.close();


    return 0;
}
