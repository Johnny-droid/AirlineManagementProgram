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

void Ticket::print() {
    cout << "Ticket    Passenger: " << passenger->getName() << "     Baggage: " << baggage << "       Price: " << price << endl;
}


