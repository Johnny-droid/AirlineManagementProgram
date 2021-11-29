#ifndef AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
#define AIRLINEMANAGEMENTPROGRAM_FLIGHT_H

#include <string>
#include "Airport.h"

using namespace std;

class Flight {
    int number;
    int duration;
    Airport* origin;
    Airport* destiny;
    //date of flight;
public:
    Flight(int number, int duration, Airport* origin, Airport* destiny);
    int getNumber();
    int getDuration();
    Airport* getOrigin();
    Airport* getDestiny();

};


#endif //AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
