#include <vector>
#include "Flight.h"

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, string date) {
    this->dateDeparture = date;
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
    this->tickets = vector<Ticket>();
}

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, string date, vector<Ticket> tickets) {
    this->dateDeparture = date;
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

string Flight::getDate() {
    return dateDeparture;
}


Airport *Flight::getOrigin() {
    return origin;
}

Airport *Flight::getDestiny() {
    return destiny;
}

vector<Ticket>& Flight::getTickets() {
    return tickets;
}

void Flight::setNumber(int newNumber){
    number = newNumber;
}
void Flight::setDuration(int newDuration){
    duration = newDuration;
}

void Flight::printTickets() {
    for (int i = 0; i < tickets.size(); i++) {
        cout << i + 1 << ") ";
        tickets[i].print();
    }
}

void Flight::print() {
    cout << "Flight  Number: " << number << "   Duration: " << duration << "   Date of Departure: " << dateDeparture << endl;
    cout << "        Airport Origin: " << origin->getName() << "      Airport Destiny: " << destiny->getName() << endl;
}

void Flight::setAirportOrigin(Airport *airport) {
    this->origin = airport;
}

void Flight::setAirportDestiny(Airport *airport) {
    this->destiny = airport;
}





