#include "Flight.h"

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny) {
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
}

int Flight::getNumber() {
    return number;
}

int Flight::getDuration() {
    return duration;
}

Airport *Flight::getOrigin() {
    return origin;
}

Airport *Flight::getDestiny() {
    return destiny;
}





