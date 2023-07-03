#pragma once
#ifndef ATHLETE_H
#define ATHLETE_H

#include <string>
#include <vector>

#endif // ATHLETE_H

using namespace std;

struct Athlete{
    string first_name;
    string last_name;
    int bench_pb;
    int deadlift_pb;
};
void print_athlete_info(vector<Athlete> v1);
void modified_print_athlete_info(const Athlete &a);
void best_benchpress(const vector<Athlete> &v1);
void avg_deadlift(const vector<Athlete> &v1);
void best_athlete(const vector<Athlete> &v1);
bool compare(const Athlete &a1, const Athlete &a2);
