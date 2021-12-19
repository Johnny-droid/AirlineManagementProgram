#include "Date.h"

Date::Date (string date){
    vector<string> v = Menu::split(date, "-");
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

bool Date::operator==(Date date2) {
    if (this->day == date2.day and this->month == date2.month and this->year == date2.year) return true;
    return false;
}

bool Date::operator<(Date date2) {
    if (this->year < date2.year) return true;
    if (this->year > date2.year) return false;
    if (this->month < date2.month) return true;
    if (this->month > date2.month) return false;
    if (this->day < date2.day) return true;
    if (this->day >= date2.day) return false;
}