#include "Ticket.h"

Ticket::Ticket(int baggage, int price, Passenger* passenger) {
    this->baggage = baggage;
    this->price = price;
    this->passenger = passenger;
}


