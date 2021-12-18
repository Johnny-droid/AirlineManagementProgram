#include "LocalTransport.h"

LocalTransport::LocalTransport() {
    this->id = -1;
    this->typeTransport = "";
    this->times = "";
    this->distanceToAirport = -1;
}

LocalTransport::LocalTransport(int id, string typeTransport, string times, int distanceToAirport) {
    this->id = id;
    this->typeTransport = typeTransport;
    this->times = times;
    this->distanceToAirport = distanceToAirport;
}

int LocalTransport::getId() const {
    return id;
}

string LocalTransport::getTypeTransport() const {
    return typeTransport;
}

string LocalTransport::getTimes() const {
    return times;
}

int LocalTransport::getDistanceToAirport() const {
    return distanceToAirport;
}

void LocalTransport::setTypeTransport(string newTypeTransport){
    typeTransport = newTypeTransport;
}
void LocalTransport::setTimes(string newTimes){
    times = newTimes;

}
void LocalTransport::setDistanceToAirport(int newDistanceToAirport){
    distanceToAirport = newDistanceToAirport;
}

void LocalTransport::print() const {
    cout << id << ") Local Transport    Type: " << typeTransport << "     times: " << times << "    distance to Airport: " << distanceToAirport << "km" << endl;
}

bool LocalTransport::operator<(const LocalTransport& lT) const {
    return this->distanceToAirport < lT.getDistanceToAirport();
}

bool LocalTransport::operator==(const LocalTransport &lT) const {
    return this->id == lT.id;
}


