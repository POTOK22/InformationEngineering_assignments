#include <iostream>
#include <vector>

#include "Athlete.h"
#include "Athlete.cpp"

using namespace std;

int main()
{
    bool end_loop=false;
    do{
        int user_choice=0;
        cout<<"Choose an option:\n1-Homework1\n2-Homework2\n3-Homework3\n4-Homework4\n5-Homework5"
              "\nEverything else-Exit"<<endl;
        cin>>user_choice;
        Athlete one;
        Athlete two;
        Athlete three;
        Athlete four;
        vector<Athlete> vec1;

        one.first_name="Rick";
        one.last_name="Sanchez";
        one.bench_pb=100;
        one.deadlift_pb=180;

        two.first_name="Peter";
        two.last_name="Griffin";
        two.bench_pb=80;
        two.deadlift_pb=130;

        three.first_name="Nathan";
        three.last_name="Drake";
        three.bench_pb=150;
        three.deadlift_pb=270;

        vec1.emplace_back(one);
        vec1.emplace_back(two);
        vec1.emplace_back(three);
        switch(user_choice){
            case 1:{
                cout<<"Enter first name of fourth athlete: ";
                cin>>four.first_name;
                cout<<"Enter last name of fourth athlete: ";
                cin>>four.last_name;
                cout<<"Enter bench press personal best of fourth athlete: ";
                cin>>four.bench_pb;
                cout<<"Enter deadlift perfonal best of fourth athlete: ";
                cin>>four.deadlift_pb;
                vec1.emplace_back(four);
                print_athlete_info(vec1);
                break;
            }
            case 2:{
                modified_print_athlete_info(three);
                break;
            }
            case 3:{
                best_benchpress(vec1);
                break;
            }
            case 4:{
                avg_deadlift(vec1);
                break;
            }
            case 5:{
                best_athlete(vec1);
                break;
            }
            default:{
                cout<<"Exiting"<<endl;
                end_loop=true;
            }
        }
    }while(end_loop==false);
    return 0;
}
