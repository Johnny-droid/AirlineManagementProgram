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
