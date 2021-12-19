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
    string dateDeparture;
    Airport* origin;
    Airport* destiny;
    vector<Ticket> tickets;

public:
    Flight(int number, int duration, Airport* origin, Airport* destiny, string date);
    Flight(int number, int duration, Airport* origin, Airport* destiny, string date, vector<Ticket> tickets);
    int getNumber();
    int getDuration();
    string getDate();
    Airport* getOrigin();
    Airport* getDestiny();
    vector<Ticket>& getTickets();
    void setNumber(int newNumber);
    void setDuration(int newDuration);
    void setAirportOrigin(Airport* airport);
    void setAirportDestiny(Airport* airport);
    void printTickets();
};


#endif //AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
