#include "header.h"

Time::Time(int num) : num_(num){}

void Time::set(int num){
    num_=num;
}
int Time::num() const{
    return num_;
}
void Time::print() const{
    cout<<num_/60<<"m:"<<num_%60<<"s"<<endl;
}
ostream &operator<<(ostream &str, Time &rhs){
    if(rhs.num_>=3600){
        str << rhs.num_/3600<<"h:"<<(rhs.num_-3600)/60<<"m:"<<rhs.num_%60<<"s";
    }
    if(rhs.num_>=60 && rhs.num_<3600){
        str << rhs.num_/60<<"m:"<<rhs.num_%60<<"s";
    }
    if(rhs.num_<=0){
        str<<0<<"s";
    }
    return str;
}
istream &operator>>(istream &str, Time &rhs){
    str >> rhs.num_;
    return str;
}
Time Time::operator+(const Time &rhs) const {
    return Time(num_ + rhs.num_);
}
Time Time::operator-(const Time &rhs) const {
    return Time(num_ - rhs.num_);
}
Time Time::operator*(const Time &rhs) const {
    return Time(num_ * rhs.num_);
}
Time::operator int(){
    return (int)num_;
}
