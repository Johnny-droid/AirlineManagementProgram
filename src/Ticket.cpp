#include "Ticket.h"

Ticket::Ticket(int baggage, int price, Passenger* passenger) {
    this->baggage = baggage;
    this->price = price;
    this->passenger = passenger;
}
int Ticket::getBaggage() {
    return baggage;
}

int Ticket::getPrice() {
    return price;
}

Passenger* Ticket::getPassenger() {
    return passenger;
}

void Ticket::setBaggage(int newBaggage){
    baggage = newBaggage;
}
void Ticket::setPrice(int newPrice){
    price = newPrice;
}
void Ticket::setPassenger(Passenger* newPassenger){
    passenger = newPassenger;
}

void Ticket::print() {
    cout << "Ticket    Passenger: " << passenger->getName() << "     Baggage: " << baggage << "       Price: " << price << endl;
}


