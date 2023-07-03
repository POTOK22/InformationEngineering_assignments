#include "Athlete.h"

#include <iostream>
#include <algorithm>

using namespace std;

void print_athlete_info(vector<Athlete> v1){
    for(auto &v1 : v1){
        cout<<"First name: "<<v1.first_name<<endl;
        cout<<"Last name: "<<v1.last_name<<endl;
        cout<<"Bench press personal best: "<<v1.bench_pb<<endl;
        cout<<"Deadlift perfonal best: "<<v1.deadlift_pb<<endl;
    }
}
void modified_print_athlete_info(const Athlete &a){
    cout<<a.first_name<<endl;
    cout<<a.last_name<<endl;
    cout<<a.bench_pb<<endl;
    cout<<a.deadlift_pb<<endl;
}
void best_benchpress(const vector<Athlete> &v1){
    int max=0;
    for(int i=0; i<static_cast<int>(v1.size()); i++){
        if(v1[i].bench_pb>max){
            max=v1[i].bench_pb;
        }
    }
    cout<<"Max benchpress is: "<<max<<endl;
}
void avg_deadlift(const vector<Athlete> &v1){
    int sum=0;
    int avg=0;
    for(int i=0; i<static_cast<int>(v1.size()); i++){
            sum+=v1[i].deadlift_pb;
        }
    avg=sum/v1.size();
    cout<<"Avarage of deadlift is: "<<avg<<endl;
}
bool compare(const Athlete &a1, const Athlete &a2){
    int avg_a1=(a1.bench_pb+a1.deadlift_pb)/2;
    int avg_a2=(a2.bench_pb+a2.deadlift_pb)/2;
    return avg_a1>avg_a2;
}
void best_athlete(vector<Athlete> &v1){
    sort(v1.begin(), v1.end(), compare);
    for(auto &v1 : v1){
        cout<<"First name: "<<v1.first_name<<endl;
        cout<<"Last name: "<<v1.last_name<<endl;
        cout<<"Bench press personal best: "<<v1.bench_pb<<endl;
        cout<<"Deadlift perfonal best: "<<v1.deadlift_pb<<endl;
    }
}
