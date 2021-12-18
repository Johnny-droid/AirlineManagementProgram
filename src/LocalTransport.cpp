#include "LocalTransport.h"

LocalTransport::LocalTransport() {
    this->typeTransport = "";
    this->times = "";
    this->distanceToAirport = -1;
}

LocalTransport::LocalTransport(string typeTransport, string times, int distanceToAirport) {
    this->typeTransport = typeTransport;
    this->times = times;
    this->distanceToAirport = distanceToAirport;
}

string LocalTransport::getTypeTransport() {
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
    cout << "Local Transport    Type: " << typeTransport << "     times: " << times << "    distance to Airport: " << distanceToAirport << "km" << endl;
}

bool LocalTransport::operator<(const LocalTransport& lT) const {
    return this->distanceToAirport < lT.getDistanceToAirport();
}