#ifndef AIRLINEMANAGEMENTPROGRAM_TICKET_H
#define AIRLINEMANAGEMENTPROGRAM_TICKET_H

#include "Flight.h"

using namespace std;

class Ticket {
    int baggage;
    int price;
    Flight flight;

public:
    Ticket(int baggage, int price, Flight flight);


};


#endif //AIRLINEMANAGEMENTPROGRAM_TICKET_H
