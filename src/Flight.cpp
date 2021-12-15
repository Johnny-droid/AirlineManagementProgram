#include <vector>
#include "Flight.h"

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, vector<Ticket> tickets) {
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
    this->tickets = tickets;
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

vector<Ticket> Flight::getTickets() {
    return tickets;
}





