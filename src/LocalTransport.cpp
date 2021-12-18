#include "LocalTransport.h"

LocalTransport::LocalTransport(string typeTransport, string times, int distanceToAirport) {
    this->typeTransport = typeTransport;
    this->times = times;
    this->distanceToAirport = distanceToAirport;
}

string LocalTransport::getTypeTransport() {
    return typeTransport;
}

string LocalTransport::getTimes() {
    return times;
}

int LocalTransport::getDistanceToAirport() {
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
