#include "Time.h"

Time::Time(string time){
    vector<string> v = Menu::split(time, ":");
    this->hour = stoi(v[0]);
    this->minute = stoi(v[1]);
}
bool Time::operator== (Time time2){

}
bool Time::operator< (Time time2){

}