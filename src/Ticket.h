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
    Passenger* getPassenger();
    void setBaggage(int newBaggage);
    void setPrice(int newPrice);
    void setPassenger(Passenger* newPassenger);
    void print();

    static bool compareByBaggage(const Ticket& ticket1, const Ticket& ticket2);
    static bool compareByPrice(const Ticket& ticket1, const Ticket& ticket2);
    static bool compareByPassenger(const Ticket& ticket1, const Ticket& ticket2);
};

#endif //AIRLINEMANAGEMENTPROGRAM_TICKET_H
