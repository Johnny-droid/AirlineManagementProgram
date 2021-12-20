#include "Time.h"

Time::Time(string time){
    vector<string> v;

    while (time.length() != 0) {
        int pos = time.find_first_of(":");
        if (pos == time.npos) {
            v.push_back(time);
            break;
        }
        string subStr = time.substr(0, pos);
        v.push_back(subStr);
        time = time.substr(pos + 1);
    }

    this->hour = stoi(v[0]);
    this->minute = stoi(v[1]);
}

int Time::getHour() const {
    return hour;
}
int Time::getMinute() const {
    return minute;
}

string Time::getStringTime() const {
    if (minute < 10) return to_string(hour) + ":0" + to_string(minute);
    else return to_string(hour) + ":" + to_string(minute);
}

bool Time::operator== (const Time& time2){
    return false;
}
bool Time::operator< (const Time& time2){
    return false;
}