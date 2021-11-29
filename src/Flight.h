#ifndef AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
#define AIRLINEMANAGEMENTPROGRAM_FLIGHT_H

#include <string>
#include "Airport.h"

using namespace std;

class Flight {
    int number;
    int duration;
    string dateDeparture;
    Airport* origin;
    Airport* destiny;
    //We can add the tickets here maybe?
public:
    Flight() {};
    Flight(int number, int duration, Airport* origin, Airport* destiny);
    int getNumber();
    int getDuration();
    Airport* getOrigin();
    Airport* getDestiny();
};


#endif //AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
