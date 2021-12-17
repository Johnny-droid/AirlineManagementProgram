#ifndef AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
#define AIRLINEMANAGEMENTPROGRAM_FLIGHT_H

#include <string>
#include <vector>
#include "Airport.h"
#include "Ticket.h"

using namespace std;

class Flight {
    int number;
    int duration;
    //string dateDeparture;
    Airport* origin;
    Airport* destiny;
    vector<Ticket> tickets;

public:
    Flight(int number, int duration, Airport* origin, Airport* destiny);
    Flight(int number, int duration, Airport* origin, Airport* destiny, vector<Ticket> tickets);
    int getNumber();
    int getDuration();
    Airport* getOrigin();
    Airport* getDestiny();
    vector<Ticket>& getTickets();
};


#endif //AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
