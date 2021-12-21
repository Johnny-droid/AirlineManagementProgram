#include "Date.h"
/**
 * Creates a date object with the default values for day, month and year of '01-01-1000'
 */
Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 1000;
}
/**
 * Creates a date object
 * @param date The string that represents a date in the model 'DD-MM-YYYY'
 */
Date::Date (string date){
    vector<string> v;

    while (date.length() != 0) {
        int pos = date.find_first_of("-");
        if (pos == date.npos) {
            v.push_back(date);
            break;
        }
        string subStr = date.substr(0, pos);
        v.push_back(subStr);
        date = date.substr(pos + 1);
    }

    int tday = stoi(v[0]);
    int tmonth = stoi(v[1]);
    int tyear = stoi(v[2]);
    if (tday > 31 and (tmonth == 1 or tmonth == 3 or tmonth == 5 or tmonth == 7 or tmonth == 8 or tmonth == 10 or tmonth == 12)) cout << "This is an invalid date." << endl;
    if (tday > 30 and (tmonth == 4 or tmonth == 6 or tmonth == 9 or tmonth == 11)) cout << "This is an invalid date." << endl;
    if ((tday > 29 and tmonth == 2 and tyear%4 == 0) or (tday > 28 and tmonth == 2 and tyear%4 != 0)) cout << "This is an invalid date." << endl;
    else{
        this->day = tday;
        this->month = tmonth;
        this->year = tyear;
    }
}
/**
 *
 * @return A representation of the date in the string format 'DD-MM-YYYY'
 */
string Date::getStringDate() const {
    return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
}
/**
 * Checks if two dates are considered equal
 * @param date2 The date object on the right side of the == operator
 * @return True if both dates have the same values for the attributes day, month and year
 */
bool Date::operator==(Date date2) {
    if (this->day == date2.day && this->month == date2.month && this->year == date2.year) return true;
    return false;
}
/**
 * Checks if a date is before another one
 * @param date2 The date object on the right side of the < operator
 * @return True if the date on the left is before the one on the right. False, if otherwise.
 */
bool Date::operator<(Date date2) {
    if (this->year < date2.year) return true;
    if (this->year > date2.year) return false;
    if (this->month < date2.month) return true;
    if (this->month > date2.month) return false;
    if (this->day < date2.day) return true;
    return false;
}



