#ifndef AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
#define AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class LocalTransport {
    int id;
    string typeTransport;
    string times; //Ainda n sei bem o que fazer em relação a isto, mas talvez colocar uma lista de horário em que passa por dia
    int distanceToAirport;

public:
    LocalTransport();
    LocalTransport(int id, string typeTransport, string times, int distanceToAirport);
    int getId() const;
    string getTypeTransport() const;
    string getTimes() const;
    int getDistanceToAirport() const;
    void setTypeTransport(string newTypeTransport);
    void setTimes(string newTimes);
    void setDistanceToAirport(int newDistanceToAirport);
    void print() const;

    bool operator<(const LocalTransport& lT) const;
    bool operator==(const LocalTransport& lT) const;
};


#endif //AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
