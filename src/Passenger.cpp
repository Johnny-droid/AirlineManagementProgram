#include "Passenger.h"

Passenger::Passenger(string name, int baggage) {
    this->name = name;
    this->baggage = baggage;
}

string Passenger::getName() {
    return name;
}

int Passenger::getBaggage() {
    return baggage;
}
