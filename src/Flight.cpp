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
    this->stackMax = 10;
    this->carriageMaxSize = 4;
    this->cartMaxSize = 3;
}

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, string date, vector<Ticket> tickets) {
    Date date1(date);
    this->dateDeparture = date1;
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
    this->tickets = tickets;
    this->stackMax = 10;
    this->carriageMaxSize = 4;
    this->cartMaxSize = 3;
}
//vector<vector<vector<stack<int>>>> Flight::baggageCarts = buildCarts(stackMax, carriageMaxSize, cartMaxSize);

vector<vector<vector<stack<int>>>> Flight::buildCarts(int stackMax, int carriageMaxSize, int cartMaxSize){
    stack<int> stac; int amountOnStack = 0; int amountBaggage;
    vector<stack<int>> carriage {}; vector<vector<stack<int>>> cart {}; vector<vector<vector<stack<int>>>> allCarts {};
    for (Ticket ticket : tickets) {
        amountBaggage = ticket.getBaggage();
        if ((amountBaggage + amountOnStack) <= stackMax){
            amountOnStack += amountBaggage;
            stac.push(ticket.getBaggage());
        }
        else {
            stack<int> stacCopy;
            carriage.push_back(stacCopy);
            stac = {};
            amountOnStack = amountBaggage;
            stac.push(ticket.getBaggage());
            if (carriage.size() == carriageMaxSize) {
                vector<stack<int>> carriageCopy = carriage;
                carriage = {};
                if (cart.size() < cartMaxSize){
                    cart.push_back(carriageCopy);
                }
                else {
                    vector<vector<stack<int>>> cartCopy = cart;
                    allCarts.push_back(cartCopy);
                    cart = {};
                    cart.push_back(carriageCopy);
                }
            }
        }
    }
    carriage.push_back(stac);
    cart.push_back(carriage);
    allCarts.push_back(cart);
    return allCarts;
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
    cout << "Flight  Number: \t" << number << "   Duration: \t" << duration << "   Date of Departure: \t" << dateDeparture.getStringDate() << endl;
    cout << "        Airport Origin: \t" << origin->getName() << "      Airport Destiny: \t" << destiny->getName() << endl;
    cout << "        Number of tickets: \t" << tickets.size() << endl;
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






