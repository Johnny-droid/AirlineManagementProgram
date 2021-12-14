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
    int getBaggage();
    int getPrice();
    Passenger getPassenger();
};

#endif //AIRLINEMANAGEMENTPROGRAM_TICKET_H
