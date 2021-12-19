#include <vector>
#include "Flight.h"

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, string date) {
    Date date1(date);
    this->dateDeparture = date1;
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
    this->tickets = vector<Ticket>();
}

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, string date, vector<Ticket> tickets) {
    Date date1(date);
    this->dateDeparture = date1;
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
    this->tickets = tickets;
}

int Flight::getNumber() const {
    return number;
}

int Flight::getDuration() const {
    return duration;
}

Date& Flight::getDate() {
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
    cout << "Flight  Number: " << number << "   Duration: " << duration << "   Date of Departure: " << dateDeparture.getStringDate() << endl;
    cout << "        Airport Origin: " << origin->getName() << "      Airport Destiny: " << destiny->getName() << endl;
    cout << "        Number of tickets: " << tickets.size() << endl;
}

void Flight::setAirportOrigin(Airport *airport) {
    this->origin = airport;
}

void Flight::setAirportDestiny(Airport *airport) {
    this->destiny = airport;
}

bool Flight::compareByNumber(const Flight &flight1, const Flight &flight2) {
    return flight1.getNumber() < flight2.getNumber();
}

bool Flight::compareByDuration(const Flight &flight1, const Flight &flight2) {
    return flight1.getDuration() < flight2.getDuration();
}

bool Flight::compareByDate(Flight &flight1, Flight &flight2) {
    return flight1.getDate() < flight2.getDate();
}

bool Flight::compareByNumberTickets(Flight &flight1, Flight &flight2) {
    return flight1.getTickets().size() < flight2.getTickets().size();
}






