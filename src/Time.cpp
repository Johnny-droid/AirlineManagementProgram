#include "Time.h"
/**
 * Create a time object
 * @param time The string that represents a time's hours and minutes in the model 'HH:MM'
 */
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
/**
 *
 * @return Hour represented by an integer
 */
int Time::getHour() const {
    return hour;
}
/**
 *
 * @return Minute represented by an integer
 */
int Time::getMinute() const {
    return minute;
}
/**
 *
 * @return A string that represents the time's hours and minutes in the model 'HH:MM'
 */
string Time::getStringTime() const {
    if (minute < 10) return to_string(hour) + ":0" + to_string(minute);
    else return to_string(hour) + ":" + to_string(minute);
}
/**
 * Check if two time objects are considered equal
 * @param time2 The time object on the right side of the == operator
 * @return True, if both time objects have the same hours and minutes
 */
bool Time::operator== (const Time& time2){
    if (this->hour == time2.hour && this->minute == time2.minute) return true;
    return false;
}
/**
 * Check if a time object is before another one
 * @param time2 The time object on the right side of the < operator
 * @return True, if the first time object happens before the second one.
 */
bool Time::operator< (const Time& time2){
    if (this->hour < time2.hour) return true;
    if (this->hour > time2.hour) return false;
    if (this->minute < time2.minute) return true;
    return false;
}