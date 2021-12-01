#ifndef AIRLINEMANAGEMENTPROGRAM_TICKET_H
#define AIRLINEMANAGEMENTPROGRAM_TICKET_H

#include "Passenger.h"

using namespace std;

class Ticket {
    int baggage;
    int price;
    Passenger* passenger;

public:
    Ticket(int baggage, int price, Passenger* passenger);
    int getBaggage() {return baggage;};
    int getPrice() {return price;};
    Passenger getPassenger() {return *passenger;};

};

#endif //AIRLINEMANAGEMENTPROGRAM_TICKET_H
