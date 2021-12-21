#include "LocalTransport.h"

LocalTransport::LocalTransport() {
    this->id = -1;
    this->typeTransport = "";
    this->times = list<Time>();
    this->distanceToAirport = -1;
}

LocalTransport::LocalTransport(int id, string typeTransport, string strTimes, int distanceToAirport) {
    list<Time> lTimes;
    size_t pos = 0;
    while (pos != string::npos) {
        pos = strTimes.find_first_of(" ");
        if (pos == string::npos) {
            Time t1(strTimes);
            lTimes.push_back(t1);
            break;
        } else {
            string subStr = strTimes.substr(0, pos);
            Time t2(subStr);
            lTimes.push_back(t2);
            strTimes = strTimes.substr(pos + 1);
        }
    }

    this->id = id;
    this->typeTransport = typeTransport;
    this->times = lTimes;
    this->distanceToAirport = distanceToAirport;
}

int LocalTransport::getId() const {
    return id;
}

string LocalTransport::getTypeTransport() const {
    return typeTransport;
}

string LocalTransport::getStringTimes() const {
    string s;
    for (Time time : times) {
        s += time.getStringTime() + " ";
    }
    return s;
}

list<Time>& LocalTransport::getTimes() {
    return times;
}

int LocalTransport::getDistanceToAirport() const {
    return distanceToAirport;
}

void LocalTransport::setTypeTransport(string newTypeTransport){
    typeTransport = newTypeTransport;
}

void LocalTransport::setTimes(string newTimes){
    list<Time> lTimes;

    while (newTimes.length() != 0) {
        int pos = newTimes.find_first_of("-");
        if (pos == newTimes.npos) {
            Time t1(newTimes);
            lTimes.push_back(t1);
            break;
        }
        string subStr = newTimes.substr(0, pos);
        Time t2(subStr);
        lTimes.push_back(t2);
        newTimes = newTimes.substr(pos + 1);
    }
    times = lTimes;
}

void LocalTransport::setDistanceToAirport(int newDistanceToAirport){
    distanceToAirport = newDistanceToAirport;
}

void LocalTransport::print() const {
    cout << id << ") Local Transport    Type: " << typeTransport << "     times: " << this->getStringTimes() << endl;
    cout <<     "                       distance to Airport: " << distanceToAirport << "km" << endl;
}

bool LocalTransport::operator<(const LocalTransport& lT) const {
    return this->distanceToAirport < lT.getDistanceToAirport();
}

bool LocalTransport::operator==(const LocalTransport &lT) const {
    return this->id == lT.id;
}


